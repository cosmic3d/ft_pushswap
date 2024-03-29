# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME		= checker
MK			= Makefile

# -=-=-=-=-	CLRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

RESET		:= \033[0;39m
BLACK		:= \033[0;30m
RED			:= \033[0;91m
GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
MAGENTA		:= \033[0;95m
CYAN		:= \033[0;96m
GRAY		:= \033[0;90m
WHITE		:= \033[0;97m

# -=-=-=-=-	CMNDS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #
CC			= gcc
SANS		= -fsanitize=address -g
CFLAGS		= -Wall -Werror -Wextra -D BUFFER_SIZE=42
AR			= ar -rcs
RM			= rm -f
MKDIR		= mkdir -p
CP			= cp -f

# -=-=-=-=-	DIRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #
SRC_DIR	= src/
OBJ_DIR	= obj/
INC_DIR	= hdrs/
LIB_DIR	= lib/ft_libft/
PRINTF_DIR = lib/ft_printf/

# -=-=-=-=-	LIBS/HEADERS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIBS		+= $(LIB_DIR)libft.a
LIBS		+= $(PRINTF_DIR)libftprintf.a
LIBS		+= lib/ft_getnextline/get_next_line.c lib/ft_getnextline/get_next_line_utils.c
LIBS_HDRS	+= $(INC_DIR)checker.h
INCLUDE		= -I $(LIBS_HDRS)

# -=-=-=-=-	SOURCES -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #
SRCS		+= checker.c check_input.c init_stacks.c utils.c \
checker_utils.c push.c reverse_rotate.c rotate.c swap.c

# -=-=-=-=-	OBJECTS/DEPENDENCIES -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEP			= $(addsuffix .d, $(basename $(OBJS)))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(MK)
	@$(MKDIR) $(dir $@)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) -c $< -o $@

# -=-=-=-=-	MAKING LIBS AND COMPILING WITH THEM -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all: make_libs $(NAME)

make_libs:
	@make -sC $(LIB_DIR)
	@make -sC $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)🧩CHECKER COMPILED🧩$(RESET)"

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -sC $(LIB_DIR)
	@make clean -sC $(PRINTF_DIR)
	@echo "$(CYAN)Dependencies and objects removed$(RESET)"

fclean:	clean
	@$(RM) $(NAME) 
	@make fclean -sC $(LIB_DIR)
	@make fclean -sC $(PRINTF_DIR)
	@echo "$(RED)$(NAME) Removed$(RESET)"

re:	fclean	all

-include $(DEP)

.PHONY:	all clean fclean re make_libs
