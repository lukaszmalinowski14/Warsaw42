NAME = libftprintf.a
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
# **Ścieżka do biblioteki libft**
LIBFT_PATH = ./libft
LIBFT = ${LIBFT_PATH}/libft.a
# **Ścieżka do pliku nagłówkowego ft_printf.h**
LIBFTPRINTF_PATH = .
LIBFTPRINTF = ${LIBFTPRINTF_PATH}/ft_printf.h
CC = gcc
FLAGS = -Wall -Werror -Wextra -I. -I${LIBFT_PATH} # **Dodano flagi -I dołączenia katalogów**
REMOVE = rm -f

# **Pliki źródłowe ft_printf**

SRCS = ft_printf.c \
       print_func.c \
       print_libft.c \
       write_out.c

OBJS = $(SRCS:.c=.o)

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	@echo "\n$(NAME): $(GREEN)$(NAME) was created$(RESET)"
	ar -rcs ${NAME} ${OBJS}
	@echo

${LIBFT}:
	@echo
	make bonus -C ${LIBFT_PATH}
	cp ${LIBFT} ${NAME}

.c.o:
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	${CC} -c ${FLAGS} $< -o ${@:.c=.o}

clean:
	make clean -C ${LIBFT_PATH}
	@echo "\n$(NAME): $(RED)object files were deleted$(RESET)"
	${REMOVE} ${OBJS}
	@echo

fclean:
	make fclean -C ${LIBFT_PATH}
	@echo "\n$(NAME): $(RED)object files were deleted$(RESET)"
	${REMOVE} ${OBJS}
	@echo "\n$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	${REMOVE} ${NAME}
	@echo

re : fclean all

norm:
	norminette

.PHONY: all clean fclean re norm