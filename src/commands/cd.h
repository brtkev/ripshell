#include <dirent.h>

int validateDir(char * dir){
    struct dirent *de; // Pointer for directory entry

	// opendir() returns a pointer of DIR type.
	if(dir == NULL){
		dir = ".";
	}
	DIR *dr = opendir(dir);
    if(dr == NULL) return 1;
    return 0;
}

int cd(char * dir){
    
    if(validateDir(dir)){
        printf("Error : El directorio \"%s\" es invalido \n", dir);
        return 0;
    } 

    if(strcmp(dir, "..") == 0){
        //back one step
    }else if(strcmp(dir, ".") == 0){
        // do nothing
    }else{
        strcat(PWD, "\\");
        strcat(PWD, dir);
    }
    
    return 1;
}
