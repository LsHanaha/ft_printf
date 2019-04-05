#
#	Compiler variables
#

CC= gcc
CC_FLAGS= -Wall -Wextra -Werror

#
#	Debug compiler variables
#

DG_CC_FLAGS= -g -o0

#
#	Release variables
#

NAME= libftprintf.a
HEADER= libftprintf.h
HEADERDIR= ../
SRCSDIR= libftprintf
OBJS= $(patsubst %.c, %.o, $(wildcard $(SRCSDIR)/*.c))
SRCS= $(OBJS: .o=.c)

all: $(NAME)

#
#	Debug mode settings
#

debug: CC_FLAGS += $(DG_CC_FLAGS)
debug: $(NAME)

#
#	Release mode
#

$(NAME): $(OBJS) $(OBJSK)
	ar rc $@ $^

$(SRCSDIR)/%.o:	$(SRCSDIR)/%.c $(HEADER)
	$(CC) $(CC_FLAGS) -I. -c $< -o $@

#
#	Clean
#

clean:
	rm -rf $(SRCSDIR)/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
