VPATH = src
OUT_PATH=./bin

CC=g++
CFLAGS=-Wall -Wextra -Werror -I include

main: main.o clean_bin
	$(CC) $(CFLAGS) $< -o $(OUT_PATH)/$@

main.o: main.cpp
	$(CC) $(CFLAGS) -c $<

clean_bin:
	mkdir -p bin
	rm -rf bin/*
