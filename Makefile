CC = gcc
CFLAGS = -Wall -Wextra 
CLIBS = -lraylib -lGL -lpthread -ldl -lrt -lX11 -lm

output: main.c
	$(CC) -o a.out main.c $(CFLAGS) $(CLIBS)

clean:
	rm pong
