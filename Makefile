NAME = so_long

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -f

LIB_FLAG = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -L $(LIBFT_DIR) -lft
MLX = libmlx.a
MLX_DIR = ./library/mlx
LIBFT = libft.a
LIBFT_DIR = ./library/libft
INCLUDE = -I./include -I./library/libft -I./library/mlx

SRCS_FILE = so_long.c struct.c movements.c images.c error.c check.c arguments.c\
			maps1.c maps2.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))

SRCS_DIR = ./src

OBJS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS) $(MLX_DIR)/$(MLX) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CFLAGS) $(LIB_FLAG) $(OBJS) $(INCLUDE) -o $@

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/$(LIBFT) :
	@$(MAKE) all -C $(LIBFT_DIR)

$(MLX_DIR)/$(MLX) : 
	@$(MAKE) all -C $(MLX_DIR)

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean;
	@$(RM) $(SRCS_DIR)/*.o

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean;
	@$(MAKE) -C $(MLX_DIR) clean;
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
