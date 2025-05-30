CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libft.a

INCDIR	=	includes
INC		=	$(INCDIR)/libft.h

SRCDIR	=	srcs

CHARDIR	=	$(SRCDIR)/char
CHARSRC	=	ft_isalpha.c		ft_isdigit.c		ft_isalnum.c		ft_isascii.c		ft_isprint.c		\
			ft_toupper.c		ft_tolower.c

CONVDIR	=	$(SRCDIR)/convert
CONVSRC	=	ft_atoi.c			ft_itoa.c

LSTDIR	=	$(SRCDIR)/list
LSTSRC	=	ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c		ft_lstlast.c		ft_lstadd_back.c	\
			ft_lstdelone.c		ft_lstclear.c		ft_lstiter.c		ft_lstmap.c

MEMDIR	=	$(SRCDIR)/memory
MEMSRC	=	ft_memset.c			ft_bzero.c			ft_memcpy.c			ft_memmove.c		ft_memchr.c			\
			ft_memcmp.c			ft_calloc.c

PUTDIR	=	$(SRCDIR)/put
PUTSRC	=	ft_putchar_fd.c		ft_putstr_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c

STRDIR	=	$(SRCDIR)/string
STRSRC	=	ft_strlen.c			ft_strlcpy.c		ft_strlcat.c		ft_strchr.c			ft_strrchr.c		\
			ft_strncmp.c		ft_strnstr.c		ft_strdup.c			ft_substr.c			ft_strjoin.c		\
			ft_strtrim.c		ft_split.c			ft_strmapi.c		ft_striteri.c

SRC		=	$(addprefix	$(CHARDIR)/, $(CHARSRC))	\
			$(addprefix	$(CONVDIR)/, $(CONVSRC))	\
			$(addprefix	$(LSTDIR)/, $(LSTSRC))		\
			$(addprefix	$(MEMDIR)/, $(MEMSRC))		\
			$(addprefix	$(PUTDIR)/, $(PUTSRC))		\
			$(addprefix	$(STRDIR)/, $(STRSRC))

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	ar rcs $@ $^
	echo "libft created."

clean:
	rm -f $(OBJ)
	echo "object files deleted."

fclean: clean
	rm -f $(NAME)
	echo "libft deleted."

re: fclean all

%.o: %.c
	echo "compiling $@..."
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

.PHONY: all clean fclean re
.SILENT:
