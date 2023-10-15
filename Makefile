NAME = push_swap

CFLAGS =	-Wall -Wextra -Werror

SRCS = main.c stack.c ./ftprinf/*.c

HEADERS = main.h stack.h ./ftprintf/*.h

LIBFT = libft.a

LIBFTDIR = ./libft

FTPRINTFDIR = ./ftprintf

all: $(NAME)

$(LIBFT):
	@make -s -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFT) .
$(NAME): $(LIBFT) $(OBJS)
	@cc $(CFLAGS) -o $(NAME) $(SRCS) $(OBJS) $(LIBFT)

clean:
	@rm -rf $(LIBFT)
	@make -s fclean -C $(LIBFTDIR)

fclean: clean
	@rm -rf $(NAME)
re:	fclean all

.PHONY: all clean fclean r $(NAME) SRCS.c muuta tämä $(LIBFT)

clean:
	@rm -rf $(LIBFT)
	@make -s fclean -C $(LIBFTDIR)

fclean: clean
	@rm -rf $(NAME)
re:	fclean all

.PHONY: all clean fclean re 
