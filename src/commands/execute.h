
int strIndex = 0;

char * execDivideStrByCommand(char * str){
    char * word = malloc(PATH_MAX * sizeof(char*));
    int i = 0;
    for(; str[strIndex]; strIndex++ , i++){
        if(str[strIndex] == '=' || str[strIndex] == ';'){
            strIndex++;
            break;
        }
        word[i] = str[strIndex];
    }
    word[i] = '\0';
    return realloc(word, i * sizeof(char*));
}

char ** parseExecuteSingleStr(char * execString, int * size){
    char ** argv = malloc(PATH_MAX * sizeof(char**));
    *size = 0;
    strIndex = 0;
    for( ;execString[strIndex]; *size++){
        argv[*size] = execDivideStrByCommand(execString);
    }
    return realloc(argv, *size * sizeof(char**));
}

int execute(int count, char ** args){
    
    int pid = fork();
    if(pid == 0){
        char * execPath = getenv("EXECDIR");
        printf("%i\n", execv(execPath, args));
    }
}