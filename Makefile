# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 12:05:34 by tel-bouh          #+#    #+#              #
#    Updated: 2022/01/06 18:17:04 by tel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server

NAME_CLIENT = client

NAME_SERVER_BONUS = ./bonus/server

NAME_CLIENT_BONUS = ./bonus/client

SRC_SERVER = ./server.c ./ft_putnbr.c

SRC_CLIENT = ./client.c ./ft_atoi.c

SRC_SERVER_BONUS = ./bonus/server_bonus.c ./bonus/ft_putnbr_bonus.c

SRC_CLIENT_BONUS = ./bonus/client_bonus.c ./bonus/ft_atoi_bonus.c

INCLUDE_BONUS = ./bonus

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJ_SERVER = ./server.o ./ft_putnbr.o

OBJ_CLIENT = ./client.o ./ft_atoi.o

OBJ_SERVER_BONUS = ./bonus/server_bonus.o ./bonus/ft_putnbr_bonus.o

OBJ_CLIENT_BONUS = ./bonus/client_bonus.o ./bonus/ft_atoi_bonus.o

all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER) : $(OBJ_SERVER) 
	$(CC) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT) : $(OBJ_CLIENT)
	$(CC) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(OBJ_SERVER) : $(SRC_SERVER)
	$(CC) -c $(FLAGS) $(SRC_SERVER)

$(OBJ_CLIENT) : $(SRC_CLIENT)
	$(CC) -c $(FLAGS) $(SRC_CLIENT)

bonus : $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS) : $(OBJ_SERVER_BONUS)
	$(CC) -o $(NAME_SERVER_BONUS) $(OBJ_SERVER_BONUS)

$(NAME_CLIENT_BONUS) : $(OBJ_CLIENT_BONUS)
	$(CC) -o $(NAME_CLIENT_BONUS) $(OBJ_CLIENT_BONUS)

$(OBJ_SERVER_BONUS) : $(SRC_SERVER_BONUS)
	$(CC) -c $(FLAGS) ./bonus/server_bonus.c -I $(INCLUDE_BONUS) -o ./bonus/server_bonus.o
	$(CC) -c $(FLAGS) ./bonus/ft_putnbr_bonus.c -I $(INCLUDE_BONUS) -o ./bonus/ft_putnbr_bonus.o

$(OBJ_CLIENT_BONUS) : $(SRC_CLIENT_BONUS)
	$(CC) -c $(FLAGS) ./bonus/client_bonus.c -I $(INCLUDE_BONUS) -o ./bonus/client_bonus.o
	$(CC) -c $(FLAGS) ./bonus/ft_atoi_bonus.c -I $(INCLUDE_BONUS) -o ./bonus/ft_atoi_bonus.o

clean :
	rm -rf $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean : clean
	rm -rf $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re : fclean all
