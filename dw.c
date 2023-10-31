#include "words.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH(x) (sizeof(x) / sizeof(x[0]))

const char *
randword(void)
{
	return words[arc4random_uniform(LENGTH(words))];
}

int
main(int argc, char *argv[])
{
	int nwords = 4;
	if (argc >= 2)
		nwords = atoi(argv[1]);
	if (nwords == 0) {
		fprintf(stderr, "Usage: dw [number of words]\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < nwords; i++)
		printf("%s%s", randword(), i == nwords - 1 ? "\n" : " ");
	return EXIT_SUCCESS;
}
