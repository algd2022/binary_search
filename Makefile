CFLAGS=-W

array.out:
	$(CC) $(CFLAGS) -o array.out ./src/array.c

apple.out:
	$(CC) $(CFLAGS) -o apple.out ./src/apple.c

spear.out:
	$(CC) $(CFLAGS) -o spear.out ./src/spear.c

works.out:
	$(CC) $(CFLAGS) -o works.out ./src/works.c
