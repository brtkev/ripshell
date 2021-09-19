

int show(char * dir)
{
	struct dirent *de;

	if(dir == NULL){
		dir = ".";
	}
	DIR *dr = opendir(dir);

	if (dr == NULL) 
	{
		printf("Error : No se pudo abrir o no existe el dir \"%s\"\n", dir );
		return 0;
	}

	de = readdir(dr);
	while ((de = readdir(dr)) != NULL)
		printf("%s\n", de->d_name);

	closedir(dr);
	return 0;
}
