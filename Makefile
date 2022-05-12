CC = cc
CFLAGS = -Wall -Wextra -Werror
FUNC = pipex.c ./utils/parsing.c ./utils/ft_substr.c ./utils/ft_strtrim.c ./utils/ft_strncmp.c ./utils/ft_strlen.c ./utils/ft_strjoin.c ./utils/ft_strchr.c ./utils/ft_split.c ./utils/error.c
# FUNC_BONUS = checker.c ./push_swap_utils/get_next_line.c ./push_swap_utils/ft_check_args.c ./push_swap_utils/error_handler.c \
# 			 ./push_swap_utils/operations.c ./push_swap_utils/operations1.c ./push_swap_utils/libft/libft.a
NAME = pipex
NAME_BONUS = checker
OBJ = *.o
NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME):
	@echo $(CURSIVE)$(GRAY) "-MAKING pipex..." $(NONE)
	@$(CC) $(CFLAGS) $(FUNC) -o $(NAME)
	@echo  $(GREEN) "DONE!"

# bonus: $(NAME_BONUS)

# $(NAME_BONUS):
# 	@echo  $(CURSIVE)$(GRAY) "-MAKING BONUS..." $(NONE)
# 	@cd ./push_swap_utils/libft && make
# 	@cd ./push_swap_utils/libft && make bonus
# 	@$(CC) $(CFLAGS) $(FUNC_BONUS) -o $(NAME_BONUS)
# 	@echo  $(GREEN) "DONE!"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)

re : fclean all

.PHONY: re fclean all clean bonus