NAME = minishell
#~~~~~~ Directories ~~~~~~
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIB_DIR = ./libft/
#~~~~ Src Directories ~~~~
ENV_DIR = enviroment/
EXE_DIR = execute/
LIST_DIR = list_functions/
MAKE_DIR = make_redirs/
PARS_DIR = parse/
SIG_DIR = signal/
UTIL_DIR = utils/
#~~~~~~ Src Files ~~~~~~~
SRCS = main.c\
		$(ENV_DIR)env.c\
		$(ENV_DIR)env_utils.c\
		$(EXE_DIR)execute_cd.c\
		$(EXE_DIR)execute_cmd.c\
		$(EXE_DIR)execute_echo.c\
		$(EXE_DIR)execute_env.c\
		$(EXE_DIR)execute_pwd.c\
		$(EXE_DIR)execute_rest.c\
		$(EXE_DIR)execute_utils.c\
		$(EXE_DIR)execute.c\
		$(LIST_DIR)list_command.c\
		$(LIST_DIR)list_mini.c\
		$(LIST_DIR)list_utils.c\
		$(MAKE_DIR)make_append.c\
		$(MAKE_DIR)make_delimiter.c\
		$(MAKE_DIR)make_here_doc.c\
		$(MAKE_DIR)make_input.c\
		$(MAKE_DIR)make_output.c\
		$(MAKE_DIR)make_pipe.c\
		$(PARS_DIR)check_chars.c\
		$(PARS_DIR)count.c\
		$(PARS_DIR)expand_variable.c\
		$(PARS_DIR)quotes.c\
		$(PARS_DIR)lexer.c\
		$(PARS_DIR)search_in_line.c\
		$(PARS_DIR)words.c\
		$(SIG_DIR)signal.c\
		$(UTIL_DIR)fd_utils.c\
		$(UTIL_DIR)exit_mini.c\
		$(UTIL_DIR)ft_joinchar.c
#~~~~~~ Obj Files ~~~~~~~
OBJ_FILES = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
#~~~~~~ Includes ~~~~~~~~
INCLUDES = $(INC_DIR)minishell.h\
			$(INC_DIR)env.h
#~~~~~~ Compiling ~~~~~~~
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -fsanitize=leak
MAKEFLAGS = --no-print-directory
LFLAGS = -L libft -lft -lreadline
RM = rm -f
#~~~~~~~ Dir Obj ~~~~~~~~
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIB_DIR) -c $< -o $@

all: obj ${NAME}

obj:
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(NAME)

clean:
	@${RM} -Rf $(OBJ_DIR)
	@cd libft && $(MAKE) clean

fclean: clean
	@cd libft && $(MAKE) fclean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
