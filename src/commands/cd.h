

int cd(char * dir){
    if(dir == NULL){
        printf("Error : Falta directorio.\n", dir);
        return 0;
    }
    if(chdir(dir) != 0){
        printf("Error : El directorio \"%s\" no es valido \n", dir);
        return 0;
    }
    updatePWD(&PWD);
    return 1;
}
