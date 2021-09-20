
int strCopyTEST(){
    char * str = "test string";
    char * newStr = strCopy(str);
    char *i = newStr;
    for(; *i; i++ && str++){
        if(*i != *str){
            free(newStr);
            return 1;
        }
    }
    free(newStr);
    return 0;
}

int charArrayPopFrontTEST(){
    char ** arr = malloc(5 * sizeof(char**));
    for(int i = 0; i < 4; i++){
        arr[i] = malloc(6*sizeof(char*));
        arr[i] = "args";
    }
    arr[4] = NULL;

    char ** new = charArrayPopFront(arr, 0);
    for(int i = 0; new[i]; i++){
        if(strcmp(new[i], arr[i+1]) != 0){
            return 1;
        }
    }
    for(int i = 0; new[i]; i++){
        free(new[i]);
    }
    free(new);
    free(arr);
    return 0;
}

int arrayCopyTEST(){
    
    char ** arr = malloc(5 * sizeof(char**));
    for(int i = 0; i < 4; i++){
        arr[i] = malloc(6*sizeof(char*));
        arr[i] = "args";
    }
    arr[4] = NULL;

    char ** copy = arrayCopy(arr);
    for(int i = 0;copy[i];i++){
        if(strcmp(copy[i], arr[i])){
            return 1;
        }
    }
    return 0;
}
