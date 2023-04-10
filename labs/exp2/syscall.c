#include <stdio.h>
#include <dirent.h>

struct dirent *dptr;

int main() {
	char buffer[100];
	DIR *dirp;

	printf("\n\n ENTER DIRECTORY NAME: ");
	scanf("%s", buffer);

	if ((dirp = opendir(buffer)) == NULL) {
		printf("The given directory does not exist.\n");
		exit(1);
	}

	while (dptr = readdir(dirp)) {
		printf("%s\n", dptr->d_name);
	}

	closedir(dirp);
}

