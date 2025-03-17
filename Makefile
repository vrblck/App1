CC=gcc
CFLAGS=-Wall -Wextra -std=c11

TARGET=app1
SRCS=src/main.c src/csv_reader.c src/metrics.c
OBJS=$(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(TARGET)  