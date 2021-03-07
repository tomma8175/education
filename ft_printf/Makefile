NAME = libftprintf.a

MKEX = gcc -o

COMP = gcc -c

AR = ar -rc

SRC =	check_sym.c ft_atoi.c ft_flags.c ft_hex.c ft_isdigit.c \
 		ft_itoa.c ft_pointer.c ft_precision.c ft_print_c.c \
 		ft_printf.c ft_str.c ft_strlen.c ft_toupper.c \
 		ft_utoa.c ft_width.c num_base.c parse_flags.c \
 		print_c_str.c print_d_i.c print_pointer.c \
 		wr_char_len.c spec.c

FLAGS = -Wall -Wextra -Werror

OBJECT = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECT)	
	@$(AR) $(NAME) $(OBJECT)	
	@ranlib $(NAME) 
	@echo "\033[32m$(NAME) OK ! \033[0m" 

$(OBJECT) : 
	@$(COMP) $(SRC) $(FLAGS) 
	@echo "\033[33mCompilation OK\033[0m" 

clean :	
	@/bin/rm -f $(OBJECT)	
	@echo "\033[33mObject deleted\033[0m"

fclean : clean 
	@/bin/rm -f $(NAME)	
	@echo "\033[33mExec deleted\033[0m" 

re : fclean all