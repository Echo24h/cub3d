SRCS_DIR		=	src/
SCREEN_DIR		=	scene/
PARSING_DIR		=	parsing/
UTILS_DIR		=	utils/

OBJS_DIR		=	obj/
BIN_DIR			=	bin/

LIB_DIR			=	Lib/
MINI_LIB_DIR	=	minilibx/


LIB_SRCS		=	libft.a
MINI_SRC		=	libmlx.a

LIB_PATH		=	$(addprefix $(LIB_DIR), $(LIB_SRCS))
MINI_LIB_PATH	=	$(addprefix $(MINI_LIB_DIR), $(MINI_SRC))

SRCS			=	main.c	init.c raycast.c init_base.c
SCREEN			=	display.c	player.c utils.c  handle.c
PARSING			=	check.c	check_rgb.c	get.c	utils.c texture.c
UTILS			=	extra.c	utils.c	utils2.c

SCREEN_PATH		=	$(addprefix $(SRCS_DIR)$(SCREEN_DIR), $(SCREEN))
PARSING_PATH	=	$(addprefix $(SRCS_DIR)$(PARSING_DIR), $(PARSING))
UTILS_PATH		=	$(addprefix $(SRCS_DIR)$(UTILS_DIR), $(UTILS))

SRCS_PATH		=	$(addprefix $(SRCS_DIR), $(SRCS)) $(PARSING_PATH) $(SCREEN_PATH) $(UTILS_PATH)

OBJS			=	$(SRCS_PATH:.c=.o)
OBJS_PATH		=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(OBJS))

NAME			=	cub3D
NAME_PATH		=	$(addprefix $(BIN_DIR), $(NAME))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
MINI_FLAG		=	 -framework OpenGL -framework AppKit #-Lmlx -lmlx

$(OBJS_DIR)%.o	: $(SRCS_DIR)%.c
				mkdir -p $(OBJS_DIR)
				mkdir -p $(OBJS_DIR)$(SCREEN_DIR)
				mkdir -p $(OBJS_DIR)$(PARSING_DIR)
				mkdir -p $(OBJS_DIR)$(UTILS_DIR)
				$(CC) $(CFLAGS) -c $< -o ${addprefix $(OBJS_DIR), ${<:$(SRCS_DIR)%.c=%.o}}

${NAME_PATH}	: ${OBJS_PATH}
				mkdir -p $(BIN_DIR)
				cd $(LIB_DIR) && make
				cd $(MINI_LIB_DIR) && make
				$(CC) $(CFLAGS) $(MINI_FLAG) ${LIB_PATH} ${MINI_LIB_PATH} $(OBJS_PATH) -o $(NAME_PATH)

all		: $(NAME_PATH)

clean			:
				rm -rf $(OBJS_DIR)
				cd $(LIB_DIR) && make clean
				cd $(MINI_LIB_DIR) && make clean

fclean			: clean
				rm -rf $(BIN_DIR)
				cd $(LIB_DIR) && make fclean
				cd $(MINI_LIB_DIR) && make clean

re				: fclean all

lib				:
				cd $(LIB_DIR) && make
				cd $(MINI_LIB_DIR) && make

bonus			:
				@echo no bonus
.PHONY			: all clean fclean re