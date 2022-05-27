CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./pipex_mandatory/pipex.c ./utils/parsing.c ./utils/ft_substr.c ./utils/ft_strtrim.c ./utils/ft_strncmp.c ./utils/ft_strlen.c ./utils/ft_strjoin.c ./utils/ft_strchr.c ./utils/ft_split.c ./utils/error.c
# FUNC_BONUS = checker.c ./push_swap_utils/get_next_line.c ./push_swap_utils/ft_check_args.c ./push_swap_utils/error_handler.c \
# 			 ./push_swap_utils/operations.c ./push_swap_utils/operations1.c ./push_swap_utils/libft/libft.a
NAME = pipex.a
NAME_BONUS = pipex_bonus.a 
OBJS = $(SRCS:.c=.o)
AR = ar rc
B_SRCS = ./pipx_bonus/pipex_bonus.c ./pipx_bonus/process.c ./utils/parsing.c ./utils/ft_substr.c ./utils/ft_strtrim.c ./utils/ft_strncmp.c ./utils/ft_strlen.c ./utils/ft_strjoin.c ./utils/ft_strchr.c ./utils/ft_split.c ./utils/error.c ./utils/get_next_line_utils.c .//pipx_bonus/get_next_line.c

B_OBJS = $(B_SRCS:.c=.o)

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJS)
	@rm -rf $(NAME_BONUS)
	@echo $(CURSIVE)$(GRAY) "-MAKING pipex..." $(NONE)
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(NAME) -o pipex
	@echo  $(GREEN) "DONE!"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(B_OBJS)
	@rm -rf $(NAME)
	@echo  $(CURSIVE)$(GRAY) "-MAKING BONUS..." $(NONE)
	@$(AR) $(NAME_BONUS) $(B_OBJS)
	@$(CC) $(CFLAGS) $(NAME_BONUS) -o pipex
	@echo  $(GREEN) "DONE!"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJS) $(B_OBJS)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME) $(NAME_BONUS)
	@rm -rf pipex

re : fclean all

.PHONY: re fclean all clean bonus