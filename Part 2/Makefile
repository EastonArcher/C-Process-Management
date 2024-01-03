CC = gcc
CFLAGS = -Wall

all: parent_children process_chain

parent_children: parent_children.c
	$(CC) $(CFLAGS) -o parent_children parent_children.c

process_chain: process_chain.c
	$(CC) $(CFLAGS) -o process_chain process_chain.c

clean:
	rm -f parent_children process_chain
