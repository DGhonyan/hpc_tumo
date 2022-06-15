NAME = main
OPT = -O3
CC = mpic++
# MLX = -I/usr/include -Imlx_linux -O3
# MLX_LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.cpp.o:
	$(CC) -c $(SRCS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -o $(NAME)
# $(CC)  $(OBJS) $(MLX) $(MLX_LINUX) -o $(NAME)

clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re