#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	
	if (argc <= 1) {
		fprintf(stderr, "Usage: %s <password>\n\x0", argv[0]);
		return 1;
	}

	// votez_ddos_plz
	const char *pass = argv[1];
	if (strlen(pass) == 14) {
		if (pass[0] == 'v'
			&& pass[2] == 't'
			&& pass[6] == 'd'
			&& pass[3] == 'e'
			&& pass[4] == 'z'
			&& pass[1] == 'o'
			&& pass[8] == 'o'
			&& pass[5] == '_'
			&& pass[12] == 'l'
			&& pass[9] == 's'
			&& pass[7] == 'd'
			&& pass[11] == 'p'
			&& pass[10] == '_'
			&& pass[13] == 'z') {
			puts("Good job !");
			return 0;
		}
	}

	fputs("Nah, try again\n\x0", stderr);
	return 1;
}