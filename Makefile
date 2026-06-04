NAME = libft.a
AR = ar rcs
RM = rm -f
CC = cc
CFLAGS = -Wall -Werror -Wextra

RESET  = \033[0m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m

SRCS = ft_atoi.c \
ft_bzero.c       \
ft_calloc.c      \
ft_isalnum.c     \
ft_isalpha.c     \
ft_isascii.c     \
ft_isdigit.c     \
ft_isprint.c     \
ft_itoa.c        \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c    \
ft_lstdelone.c   \
ft_lstiter.c     \
ft_lstlast.c     \
ft_lstmap.c      \
ft_lstnew.c      \
ft_lstsize.c     \
ft_memchr.c      \
ft_memcmp.c      \
ft_memcpy.c      \
ft_memmove.c     \
ft_memset.c      \
ft_putchar_fd.c  \
ft_putendl_fd.c  \
ft_putnbr_fd.c   \
ft_putstr_fd.c   \
ft_split.c       \
ft_strchr.c      \
ft_strdup.c      \
ft_striteri.c    \
ft_strjoin.c     \
ft_strlcat.c     \
ft_strlcpy.c     \
ft_strlen.c      \
ft_strmapi.c     \
ft_strncmp.c     \
ft_strnstr.c     \
ft_strrchr.c     \
ft_strtrim.c     \
ft_substr.c      \
ft_tolower.c     \
ft_toupper.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@printf "$(GREEN)·▄▄▄▄   ▄▄▄·  ▐▄▄▄▄▄▄ .     ·▄▄▄      ▄▄▄  ▄▄▄▄▄▄▄▄ .$(RESET)\n"
	@printf "$(GREEN)██▪ ██ ▐█ ▀█   ·██▀▄.▀·    ▐▄▄·▪     ▀▄ █·•██  ▀▄.▀·$(RESET)\n"
	@printf "$(GREEN)▐█· ▐█▌▄█▀▀█ ▪▄ ██▐▀▀▪▄    ██▪  ▄█▀▄ ▐▀▀▄  ▐█.▪▐▀▀▪▄$(RESET)\n"
	@printf "$(GREEN)██. ██ ▐█ ▪▐▌▐▌▐█▌▐█▄▄▌    ██▌.▐█▌.▐▌▐█•█▌ ▐█▌·▐█▄▄▌$(RESET)\n"
	@printf "$(GREEN)▀▀▀▀▀•  ▀  ▀  ▀▀▀• ▀▀▀     ▀▀▀  ▀█▄▀▪.▀  ▀ ▀▀▀  ▀▀▀ $(RESET)\n"
	@printf "\n"
	@printf "$(GREEN)✓ %s creato con successo!$(RESET)\n" "$(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(BLUE)Compilato:$(RESET) %s\n" "$<"

clean:
	@$(RM) $(OBJS)
	@printf "$(YELLOW)File oggetto rimossi.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)Eseguibile %s rimosso.$(RESET)\n" "$(NAME)"

re: fclean all

.PHONY: all clean fclean re
