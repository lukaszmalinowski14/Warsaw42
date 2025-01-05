NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_printf.c
OBJS =$(SRCS:.c=.o)

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
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus so




