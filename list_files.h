#include <dirent.h>

/*
 *
 */
void list_files()
{
	struct dirent *entry;
	DIR *dir = opendir(".");

	if (dir == NULL) {
		perror("opendir");
		return;
	}

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_type == DT_REG) {  /* Check if it's a regular file */
			printf("%s\n", entry->d_name);
		}
	}

	closedir(dir);
}
