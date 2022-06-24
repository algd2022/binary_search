CFLAGS=-W

array.out: ./src/array.c
	$(CC) $(CFLAGS) -o array.out ./src/array.c

apple.out: ./src/apple.c
	$(CC) $(CFLAGS) -o apple.out ./src/apple.c

spear.out: ./src/spear.c
	$(CC) $(CFLAGS) -o spear.out ./src/spear.c

works.out: ./src/works.c
	$(CC) $(CFLAGS) -o works.out ./src/works.c
