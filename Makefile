#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avannier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/14 11:11:21 by avannier          #+#    #+#              #
#    Updated: 2016/03/14 11:11:22 by avannier         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 		= fractol

SRC 		= 		main.c \
					julia.c \
					mandelbrot.c \
					sierpinski.c \
					tools.c \
					key.c \
					key2.c \
					tools2.c \
					mandelbis.c \

SRCDIR 		= ./srcs/

HEADER		= ./includes/

SRCS 		= $(addprefix $(SRCDIR), $(SRC))

OBJ 		= $(SRC:.c=.o)

OBJDIR 		= ./objs/

OBJS		= $(addprefix $(OBJDIR), $(OBJ))

FLAGS		= -Wall -Wextra -Werror -O3

all : $(NAME)

$(NAME) : $(OBJDIR) $(OBJS)
	
	@make -C ./libft/
	@make -C ./mlx
	@gcc $(FLAGS) $(OBJS) -o $(NAME) -I$(HEADER) -L./libft -L./mlx -lft -lmlx -framework OpenGl -framework AppKit

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o : $(SRCDIR)%.c
	gcc $(FLAGS) $< -c -I$(HEADER) -o $@

clean :
	@make -C ./libft/ clean
	@rm -rf $(OBJS)
	@rm -rf $(OBJDIR)

fclean : clean
	@make fclean -C ./libft/
	@make clean -C ./mlx
	@rm -f $(NAME)

re : fclean all

.PHONY : flcean $(NAME) all clean re