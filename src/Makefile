CC = gcc
CFLAGS = -Wall -g
SRCS = main.c graph.c stack.c 
OBJS = $(SRCS:.c=.o)
TARGET = game.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
