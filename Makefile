
CC = gcc
CFLAGS = -Wall -Wextra
TARGET = studentdata

SRCS = stud_main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c 
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c stud.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

