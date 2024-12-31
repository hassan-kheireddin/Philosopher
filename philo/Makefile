NAME = philo
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src/
OBJ_DIR = objects/

SRC =	philo \
    	parse \
    	init \
    	time \
		utils \
    	monitor \
       	eat \
    	forks \
    	sleep \
    	think \
    	get_number \
    	get_time \
    	counter \
		loop

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))

OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[0;92m$(NAME) is up to date!\033[0m"
$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) 

re: fclean all
#-g #-fsanitize=thread
.PHONY: all clean fclean re