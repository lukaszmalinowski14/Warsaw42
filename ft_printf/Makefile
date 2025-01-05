NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_printf.c\
	print_func.c\
	write_out.c\

OBJS =$(SRCS:.c=.o)

BONUS = ft_printf_bonus.c\
	print_func_bonus.c\
	write_out_bonus.c\

BONUS_OBJS = $(BONUS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INCLUDES) -c $< -o $@

clean: 
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

$(BONUS_OBJS): %.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INCLUDES) -c $< -o $@

.PHONY: all clean fclean re bonus so




