SRCS= ft_printf.c \
ft_printf_handle.c \
ft_printf_handle2.c \
ft_printf_hex.c \
ft_printf_itoa.c \
ft_printf_str_tools.c

NAME = ft_printf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCDIR = src
OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

$(NAME): $(OBJDIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -I../libft/include $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

all: $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re