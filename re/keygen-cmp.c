#include <stdio.h>
#include <string.h>

char *password = "je_suis_une_banane";

int main(int argc, char const *argv[]) {
	
	if (argc <= 1) {
		fprintf(stderr, "Usage: %s <password>\n\x0", argv[0]);
		return 1;
	}

	if (!strcmp(argv[1], password)) {
		puts("Ez");
		return 0;
	} else {
		fputs("Nope\n\x0", stderr);
		return 1;
	}
}