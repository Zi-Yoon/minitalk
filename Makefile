# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 23:46:14 by byan              #+#    #+#              #
#    Updated: 2022/07/04 15:42:29 by byan             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

MINITALK			= MINITALK

SERVER 				= server
CLIENT				= client

CC 					= gcc
CFLAGS				= -Wall -Werror -Wextra

INCFLAGS 			= -I./libft

LIBFT_FILES 		= ft_putstr_fd.c ft_putnbr_fd.c ft_atoi.c ft_strdup.c ft_strlen.c
LIBFT_SRCS			= $(addprefix ./libft/, $(LIBFT_FILES))
LIBFT_OBJS			= $(LIBFT_SRCS:.c=.o)

SERVER_FILES 		= server.c server_utils.c
SERVER_FILES_BONUS 	= server_bonus.c server_utils_bonus.c
CLIENT_FILES 		= client.c client_utils.c
CLIENT_FILES_BONUS	= client_bonus.c client_utils_bonus.c
SERVER_SRCS			= $(addprefix ./srcs/, $(SERVER_FILES))
SERVER_SRCS_BONUS	= $(addprefix ./srcs_bonus/, $(SERVER_FILES_BONUS))
CLIENT_SRCS			= $(addprefix ./srcs/, $(CLIENT_FILES))
CLIENT_SRCS_BONUS	= $(addprefix ./srcs_bonus/, $(CLIENT_FILES_BONUS))
SERVER_OBJS			= $(SERVER_SRCS:.c=.o)
SERVER_OBJS_BONUS	= $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_OBJS			= $(CLIENT_SRCS:.c=.o)
CLIENT_OBJS_BONUS	= $(CLIENT_SRCS_BONUS:.c=.o)

ifdef BONUS
	SERVER_OBJECTS 	= $(SERVER_OBJS_BONUS)
	CLIENT_OBJECTS 	= $(CLIENT_OBJS_BONUS)
else
	SERVER_OBJECTS	= $(SERVER_OBJS)
	CLIENT_OBJECTS	= $(CLIENT_OBJS)
endif

all: $(MINITALK)

.c.o:
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(SERVER): $(LIBFT_OBJS) $(SERVER_OBJECTS)
	$(CC) $(CFLAGS) $(INCFLAGS) $^ -o $@

$(CLIENT): $(LIBFT_OBJS) $(CLIENT_OBJECTS)
	$(CC) $(CFLAGS) $(INCFLAGS) $^ -o $@

$(MINITALK): $(SERVER) $(CLIENT)

bonus:
	$(MAKE) BONUS=1 all

re: fclean all

clean:
	$(RM) $(LIBFT_OBJS) $(SERVER_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS) $(CLIENT_OBJS_BONUS)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

.PHONY: all re clean fclean