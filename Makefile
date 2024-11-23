NAME = prueba
SRC = extract_prueba.c\
		quotes.c\
		words.c\
		signal.c\
		main.c\
		count.c\
		check_chars.c\
		execute.c\
		execute_cmd.c\
		execute_cd.c\
		execute_pwd.c\
		list_command.c\
		list_mini.c\
		env.c\
		execute_rest.c\
		execute_utils.c\
		make_pipe.c\
		make_input.c\
		exit_mini.c

OBJ = ${SRC:.c=.o}
CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address #-fsanitize=leak
MAKEFLAGS = --no-print-directory
LFLAGS = -L libft -lft

RM = rm -f

all: ${NAME}

${NAME}: ${OBJ}
	@$(MAKE) -C libft
	${CC} ${CFLAGS} ${OBJ} $(LFLAGS) -lreadline -o ${NAME}

clean:
	@cd libft && $(MAKE) clean
	@echo "[🧹 Limpiando... 🧹]"
	@${RM} ${OBJ}
	@${RM} ${OBJ_BONUS}

fclean: clean
	@cd libft && $(MAKE) fclean
	@echo "    [🗑️ Mucho 🗑️ ]"
	@${RM} ${NAME}
	@${RM} ${BONUS}

re: fclean all
	@echo "[🛠️  Rehaciendo...🛠️ ]"

.PHONY: all clean fclean re 