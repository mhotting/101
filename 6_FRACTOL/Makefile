# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/13 19:10:45 by mhotting     #+#   ##    ##    #+#        #
#    Updated: 2018/11/16 02:47:27 by mhotting    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME =		fractol
SRCS =		./src/main.c			\
			./src/event_manager.c	\
			./src/context.c			\
			./src/error.c			\
			./src/mandelbrot.c
OBJ =		$(SRCS:.c=.o)
HEADER =	./includes/
CFLAGS = 	-Wall -Wextra -Werror -I $(HEADER)
CC =		gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C ./libft
	@make -s -C ./minilibx
	@$(CC) $(OBJ) -L./libft -lft -L./minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ): %.o : %.c $(HEADER)
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@make -s -C ./libft clean
	@make -s -C ./minilibx clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -s -C ./libft fclean
	@make -s -C ./minilibx fclean
	@/bin/rm -f $(NAME)

re: fclean all
