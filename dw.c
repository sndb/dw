#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>

#include "words.h"

const int DEFAULT_NWORDS = 4;

size_t
randsize(void)
{
	uint64_t n;
	ssize_t r = getrandom((void *)&n, sizeof(size_t), 0);
	if (r != sizeof(size_t)) {
		fprintf(stderr, "dw: cannot read random bytes\n");
		exit(EXIT_FAILURE);
	}
	return n;
}

const char *
randword(void)
{
	size_t i = randsize() % (sizeof(words) / sizeof(words[0]));
	return words[i];
}

int
main(int argc, char *argv[])
{
	int nwords = DEFAULT_NWORDS;
	if (argc >= 2)
		nwords = atoi(argv[1]);
	if (nwords == 0) {
		fprintf(stderr, "Usage: dw [NUMBER]\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < nwords; i++)
		printf("%s%s", randword(), i == nwords - 1 ? "\n" : " ");
	return 0;
}
