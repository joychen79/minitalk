
# Server
SERVER				=	server
SERVER_SRC			=	./server.c
SERVER_BONUS		=	server_bonus
SERVER_BONUS_SRC	=	server_bonus.c

# Client
CLIENT				=	client
CLIENT_SRC			=	./client.c
CLIENT_BONUS		=	client_bonus
CLIENT_BONUS_SRC	=	client_bonus.c

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

# Compiler
CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra

# Rules
all:		$(LIBFT) $(SERVER) $(CLIENT)

bonus:		$(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT):
			@make -C libft bonus

$(SERVER):			$(SERVER_SRC)
					$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT_SRC)$(LIBFT) -o $(SERVER)

$(SERVER_BONUS):	$(SERVER_BONUS_SRC)
					$(CC) $(CFLAGS) $(SERVER_BONUS_SRC) $(LIBFT_SRC)$(LIBFT) -o $(SERVER_BONUS)

$(CLIENT):			$(CLIENT_SRC)
					$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT_SRC)$(LIBFT) -o $(CLIENT)

$(CLIENT_BONUS):	$(CLIENT_BONUS_SRC)
					$(CC) $(CFLAGS) $(CLIENT_BONUS_SRC) $(LIBFT_SRC)$(LIBFT) -o $(CLIENT_BONUS)

clean:
			@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS)	$(SERVER_BONUS)

fclean:		clean
			@make -C libft fclean

re:			fclean all

.PHONY:		all clean fclean re bonus