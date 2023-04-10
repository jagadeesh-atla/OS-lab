#include <stdio.h>
#include <dirent.h>

int main (int argc, char **argv) {
	DIR *dp;
	struct dirent *link;
	dp = opendir(argv[1]);

	printf("contents of the directory %s are \n", argv[1]);

	while ((link = readdir(dp)) != 0) {
		printf("%s\t", link->d_name);
	}
	closedir(dp);
	printf("\n");
	return 0;
}

