#include <stdio.h>
#include <string.h>

// t_est_une_belle_personne_timothee ^ 0x43
char pass_xor[34] = {'7', '\x1c', '&', '0', '7', '\x1c', '6', '-', '&', '\x1c', '!', '&', '/', '/', '&', '\x1c', '3', '&', '1', '0', ',', '-', '-', '&', '\x1c', '7', '*', '.', ',', '7', '+', '&', '&', '\x43'};

int main(int argc, char const *argv[]) {

	if (argc <= 1) {
		fprintf(stderr, "Usage: %s <password>\n\x0", argv[0]);
		return 1;
	}

	char buffer[34];
	for (int i = 0; i < 34; ++i) {
		buffer[i] = pass_xor[i] ^ 0x43;
	}

	if (!strcmp(buffer, argv[1])) {
		puts("Isn't it beautiful ?");
		return 0;
	}

	fputs("Nah\n\x0", stderr);
	return 1;
}
