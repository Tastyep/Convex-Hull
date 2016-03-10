NAME	= viewer

CC	= g++

RM	= rm -f

SRCDIR	= src/

INCDIR	= inc/

LIBINC	= ../inc/

OBJDIR	= obj/

LIBDIR 	= ../build/

LIBNAME = ConvexHull.a

SRCS	= main.cpp \
	  Render.cpp
			
OBJS	= $(addprefix $(OBJDIR), $(SRCS:.cpp=.o))

INCCOMP	= -I $(INCDIR) -I $(LIBINC)

CXXFLAGS	= -O2 -march=native -std=c++14

LIB	= -L$(LIBDIR) -lConvexHull

LDFLAGS	= -lsfml-graphics -lsfml-window -lsfml-system

dummy	:= 	$(shell test -d $(OBJDIR) || mkdir $(OBJDIR))

$(OBJDIR)%.o:	$(SRCDIR)%.cpp
	$(CC) $(CXXFLAGS) $(INCCOMP) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(LIB)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
