CC = gcc
CFLAGS = -Wall -Werror

OBJECT = btdemo

SRC = btdemo.c bintree.c
OUTPUT = $(SRC:.c=.o)

all: $(OBJECT)

$(OBJECT): $(OUTPUT)
	@$(CC) $(CFLAGS) -o $(OBJECT) $(OUTPUT)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rvf *.o $(OBJECT)

.PHONY: all clean

