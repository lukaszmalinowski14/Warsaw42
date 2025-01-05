NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_tolower.c\
ft_putstr_fd.c\
ft_putnbr_fd.c\
ft_strncmp.c\
ft_isascii.c\
ft_striteri.c\
ft_strtrim.c\
ft_strnstr.c\
ft_isalnum.c\
ft_split.c\
ft_memmove.c\
ft_itoa.c\
ft_strdup.c\
ft_memset.c\
ft_strmapi.c\
ft_strlen.c\
ft_toupper.c\
ft_isdigit.c\
ft_atoi.c\
ft_strlcat.c\
ft_putendl_fd.c\
ft_substr.c\
ft_memcpy.c\
ft_memcmp.c\
ft_memchr.c\
ft_putchar_fd.c\
ft_calloc.c\
ft_strlcpy.c\
ft_strrchr.c\
ft_strchr.c\
ft_strjoin.c\
ft_isprint.c\
ft_isalpha.c\
ft_bzero.c

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstadd_back.c\
ft_lstadd_front.c\
ft_lstclear.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstlast.c\
ft_lstnew.c\
ft_lstsize.c

BONUS_OBJS = $(BONUS:.c=.o)

# Default target to build the static library
all: $(NAME)

# Rule to build the static library from the object files
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to build object files from source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the shared library
# so: $(SRCS:.c=.o)
# 	$(CC) -shared -o libft.so $(SRCS:.c=.o)

# Clean up object files
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

# Clean up object files and the static library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Build the library with bonus files included
bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus so
