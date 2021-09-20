

int execDivideStrByCommandTEST(){
    int status = 0;
    char * str = (char*)"--exec=read file;show .";
    char ** arr = malloc(3 * sizeof(char**));
    arr[3] = NULL;
    for(int i = 0; str[strIndex]; i++){
        arr[i] = execDivideStrByCommand(str);
    }
    
    if(strcmp(arr[0], "--exec") != 0) status = 1;
    else if(strcmp(arr[1], "read file") != 0) status = 2;
    else if(strcmp(arr[2], "show .") != 0) status = 3;
    
    for(int i = 0; arr[i]; i++){
        free(arr[i]);
    }
    free(arr);

    return status;
}


int parseExecuteSingleStrTEST(){
    int status = 0, size = -1;

    char * str = (char*)"--exec=read file;show .";
    char ** arr = parseExecuteSingleStr(str, &size);

    if(strcmp(arr[0], "--exec") != 0) status = 1;
    else if(strcmp(arr[1], "read file") != 0) status = 2;
    else if(strcmp(arr[2], "show .") != 0) status = 3;
    else if(size == -1) status = 4;

    for(int i = 0; arr[i]; i++){
        free(arr[i]);
    }
    freeArray(arr);

    return status;
}
