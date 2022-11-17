// premise: this is a SETUID file. It starts running as root, prints its argv[1], then lowers privileges and runs a file.

// Read about setuid() to learn more

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
	printf("Starting.\n");

	if (argc != 2) {
		printf("provide a command to run as a lower user.\n");
		return 0;
	}

	printf("argv[1]: %s\n", argv[1]);
	printf("lowering permissions\n");
	
	setuid(1000); // UID of lower priv user
	seteuid(1000);

	system(argv[1]);
	printf("done.\n");
	return 0;
}
