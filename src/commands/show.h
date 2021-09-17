#include <dirent.h>

int show(char * dir)
{
	struct dirent *de; // Pointer for directory entry

	// opendir() returns a pointer of DIR type.
	if(dir == NULL){
		dir = ".";
	}
	DIR *dr = opendir(dir);

	if (dr == NULL) // opendir returns NULL if couldn't open directory
	{
		// printf("Could not open current directory" );
		printf("Error : No se pudo abrir o no existe el dir \"%s\"\n", dir );
		return 0;
	}

	// Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
	// for readdir()
	de = readdir(dr);
	while ((de = readdir(dr)) != NULL)
		printf("%s\n", de->d_name);

	closedir(dr);	
	return 0;
}
