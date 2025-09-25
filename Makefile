SRCS = consider_cost.c \
cost_calc.c \
ft_turk_sort.c \
push_swap.c \
operations_push.c \
operations_revrot.c \
operations_rot.c \
operations_swap.c \
sort_in.c \
utils.c

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCDIR = src
OBJDIR = obj

LIBFT = libft/libft.a
FT_PRINTF = ft_printf/ft_printf.a

all: $(NAME)

$(NAME): $(FT_PRINTF) $(LIBFT) $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(FT_PRINTF):
	$(MAKE) -C ft_printf

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $(CFLAGS) -Ift_printf/include -Ilibft/include $< -o $@

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C ft_printf clean
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
