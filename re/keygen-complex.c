#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {

	if (argc <= 1) {
		fprintf(stderr, "Usage: %s <password>\n\x0", argv[0]);
		return 1;
	}

	const char *pass = argv[1];

	// 5zEAvD
	if (strlen(pass) == 6
		&& pass[1] == 'z'
		&& pass[2] == pass[3] | pass[5]
		&& pass[4] == pass[1] - 4
		&& pass[0] >= '0' && pass[0] <= '9') {

		puts("I guess you win ! If you enjoyed that kind of challenges, check out https://crackmes.one/");
		return 0;
	}

	fputs("Not event close, good luck\n\x0", stderr);
	return 1;
}