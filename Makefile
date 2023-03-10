CC:=cc
CFLAGS:=-Wall -Wextra -Werror -fsanitize=address
NAME:=miniRT

SRC := \
	src/camera/camera.c \
	src/color/color.c \
	src/color/color_utils.c \
	src/compute/compute.c \
	src/compute/compute2.c \
	src/display/display.c \
	src/gnl/get_next_line_utils.c \
	src/gnl/get_next_line.c \
	src/event.c \
	src/img.c \
	src/main.c \
	src/shapes/shape.c \
	src/shapes/shape_normal_vec.c \
	src/shapes/with_shape.c \
	src/utils/double_max.c \
	src/utils/double_min.c \
	src/utils/free_all.c \
	src/utils/ft_exit.c \
	src/utils/ft_walloc.c \
	src/utils/put_usage.c \
	src/utils/is_num.c \
	src/utils/is_float.c \
	src/vector_3d/vec3d_camera.c \
	src/vector_3d/vec3d_camera_to_screen.c \
	src/vector_3d/vec3d_sp_center.c \
	src/vector_3d/vec3d_utils.c \
	src/vector_3d/vec3d_utils1.c \
	src/world/world.c \
	src/world/world_add.c \
	src/world/world_parse_1.c \
	src/world/world_parse_2.c  \
	src/world/world_parse_3.c \
	src/world/world_parse_4.c \
	src/world/world_parse_utills.c \

OBJ := $(SRC:src/%.c=obj/%.o)
DEP := $(SRC:src/%.c=obj/%.d)

OBJ_DIR := $(sort $(dir $(OBJ)))
OBJ_DIR := $(addsuffix .keep, $(OBJ_DIR))

LIBFT := ft
LIBFT_DIR := libft

MLX_DIR := minilibx-linux
OS := $(shell uname)

ifeq ($(OS), Linux)
	LIBS_DIR := /usr/lib
	MLX := mlx_Linux
	LIBS := -lXext -lX11 -lm -lz
	DEBUGFLAGS := -g -fsanitize=address -fsanitize=leak -fsanitize=undefined
else
	MLX := mlx_Darwin
	LIBS_DIR := /usr/X11R6/lib
	LIBS := -lX11 -lXext -framework OpenGL -framework AppKit
	DEBUGFLAGS := -fsanitize=address
endif

DEPSFLAGS := -MMD -MP

ifeq ($(MAKECMDGOALS), bonus)
BONUSFLAGS = -D BONUS
endif

all: $(NAME)

$(NAME): $(MLX_DIR)/lib$(MLX).a $(LIBFT_DIR)/lib$(LIBFT).a $(OBJ)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(BONUSFLAGS) -o $(NAME) $(OBJ) \
		-L$(LIBFT_DIR) -l$(LIBFT) \
		-L$(MLX_DIR) -l$(MLX) \
		-L$(LIBS_DIR) $(LIBS)

$(MLX_DIR)/lib$(MLX).a:
	make -C $(MLX_DIR)

$(LIBFT_DIR)/lib$(LIBFT).a:
	make bonus -C $(LIBFT_DIR)

obj/%.o: src/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEPSFLAGS) $(BONUSFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(@D)
	touch $@

-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP)
	# make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	# make clean -C $(MLX_DIR)
	# make fclean -C $(LIBFT_DIR)

re: fclean all

bonus: all

.PHONY: all clean fclean re
