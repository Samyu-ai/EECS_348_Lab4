CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: football temperature

football: football.c
	$(CC) $(CFLAGS) football.c -o football

temperature: temperature.c
	$(CC) $(CFLAGS) temperature.c -o temperature

clean:
	rm -f football temperature