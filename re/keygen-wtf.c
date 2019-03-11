#include <stdio.h>
#include <string.h>

int check(const char *pass) {
	if (strlen(pass) == 17) {
		if (pass[6] == pass[8] - 32
				&& pass[15] == pass[16] - 1
				&& pass[1] == pass[7]
				&& pass[7] == pass[6] ^ 0x14
				&& pass[11] == pass[9] ^ 0x43
				&& pass[0] == (pass[3] - pass[6]) << 1 | 1
				&& pass[2] == pass[9]
				&& pass[13] == pass[3]
				&& pass[2] == 'r'
				&& pass[8] == pass[6] + 32
				&& pass[5] == pass[2] - 14) {

			return 1;
		}
	}

	return 0;
}

int main(int argc, char const *argv[]) {
	
	if (argc <= 1) {
		fprintf(stderr, "Usage: %s <password>\n\x0", argv[0]);
		return 1;
	}

	// 01234567890123456
	// MQrkjdEQerb1dkIwx
	// xxxx xxxxx x x xx
	const char *pass = argv[1];
	if (check(pass)) {
		puts("I hope this one took you more than a day.");
		return 0;
	}

	fputs("Well yes, but actually no.\n\x0", stderr);
	return 1;
}
