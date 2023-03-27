CC = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = linked-list.o test.c main.o
TARGET = linked_list

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~

