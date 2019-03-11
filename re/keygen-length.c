#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {

	if (argc <= 1) {
		fprintf(stderr, "Usage: %s <password>\n\x0", argv[0]);
		return 1;
	}

	// 10 characters
	if (strlen(argv[1]) == 10) {
		puts("That's a good start");
		return 0;
	} else {
		fputs("Nope, nope, nope\n\x0", stderr);
		return 1;
	}
}