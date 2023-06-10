
# Server
SERVER				=	server
SERVER_SRC			=	./server.c

# Client
CLIENT				=	client
CLIENT_SRC			=	./client.c

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

# Compiler
CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra

# Rules
all:		$(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
			@make -C libft

$(SERVER):			$(SERVER_SRC)
					$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT_SRC)$(LIBFT) -o $(SERVER)

$(CLIENT):			$(CLIENT_SRC)
					$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT_SRC)$(LIBFT) -o $(CLIENT)

clean:
			@$(RM) $(CLIENT) $(SERVER)

fclean:		clean
			@make -C libft fclean

re:			fclean all

.PHONY:		all clean fclean re