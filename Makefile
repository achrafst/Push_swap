CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./mandatory/main.c ./common/basic_operations.c ./common/basic_operations2.c ./common/basic_operations3.c ./common/initialize_stack_utils.c \
		./common/check_errors_utils.c ./mandatory/lis_utils.c ./mandatory/lis_utils2.c  ./mandatory/sort3_utils.c ./mandatory/sort_stack_utils1.c ./mandatory/sort_stack_utils2.c
BSRCS = ./bonus/checker_main_bonus.c ./bonus/checker_utils_bonus.c  ./common/check_errors_utils.c ./common/initialize_stack_utils.c \
		./common/basic_operations.c ./common/basic_operations2.c ./common/basic_operations3.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
NAME = push_swap
BNAME = checker
LIBFT_DIR = ./common/libft/
LIBFT = ./common/libft/libft.a

all : $(NAME)
$(LIBFT) : 
	@ make -C $(LIBFT_DIR)
$(NAME) : $(LIBFT) ${OBJS}
	@ $(CC) $(CFLAGS) ${OBJS} $< -o $@
	@ echo push_swap built succesfully
bonus : $(LIBFT) $(BOBJS)
	@ $(CC) $(CFLAGS) ${BOBJS} $< -o $(BNAME)
	@ echo checker built succesfully
%.o : %.c
	@ $(CC) -c $(CFLAGS) -o $@ $<
clean :
	@ make -C $(LIBFT_DIR) clean
	@ rm -f ${OBJS} $(BOBJS)
	@echo Object files deleted succesfully
fclean : clean
	@ rm -f $(LIBFT)
	@ rm -f $(NAME)
	@ rm -f $(BNAME)
	@ echo Executable files deleted succesfully
re : fclean all
