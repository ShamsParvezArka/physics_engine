CC = g++
CFLAGS = -Wall -Wextra -Wshadow -Wswitch-default -Wconversion -Wunreachable-code  
CLIBS = -lraylib -lGL -lpthread -ldl -lrt -lX11 -lm

output: main.cpp
	$(CC) -o a.out main.cpp particle.cpp random.cpp $(CFLAGS) $(CLIBS)

clean:
	rm a.out
