# !bin/bash

gcc -Wall -g client.c ../lib/account.c request.c -o client `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`  -w && ./client
