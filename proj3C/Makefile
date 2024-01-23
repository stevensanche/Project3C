CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = project3C
SRCS = project3C.c project3C_hashtable.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

project3C.o: project3C.c project3C_hashtable.h
	$(CC) $(CFLAGS) -c project3C.c

project3C_hashtable.o: project3C_hashtable.c project3C_hashtable.h
	$(CC) $(CFLAGS) -c project3C_hashtable.c

clean:
	rm -f $(OBJS) $(TARGET)