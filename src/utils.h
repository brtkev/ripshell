
void test(){
    char cwd[MAX_PATH];
    if(getcwd(cwd, sizeof(cwd)) != NULL){
        printf("%s\n", cwd);
    }else{
        perror("getcwd() error");
    }
}

int updatePWD(char ** pwdPointer){
    char cwd[MAX_PATH];
    // char * cwd = (char*)malloc(MAX_PATH);
    if(getcwd(cwd, sizeof(cwd)) != NULL){
        *pwdPointer = malloc(sizeof(cwd));
        strcpy(*pwdPointer, cwd);
        return 1;
    }else{
        perror("getcwd() error");
        return 0;
    }
}

int _initOriginalPWD(){
    char * aux, * auxp, *p;
    updatePWD(&aux);
    ORIGINALPWD = malloc(MAX_PATH * sizeof(char*));
    auxp = aux;p = ORIGINALPWD;
    while(*auxp != '\0'){
        if(*auxp == '\\'){
            *p = *auxp;
            p++;
        }
        *p = *auxp;
        p++;auxp++;
    }
    *p = '\0';
    free(aux);
}

int restartHistoryFile(){
    _ripshellHistDir = malloc(MAX_PATH * sizeof(char*));
    strcpy(_ripshellHistDir, ORIGINALPWD);
    strcat(_ripshellHistDir, "\\\\.ripshellhist");
    FILE *fp = fopen(_ripshellHistDir, "w");
    fclose(fp);
}

int loadEnv(){
    updatePWD(&PWD);
    _initOriginalPWD();
    restartHistoryFile();
}

int closeEnv(){
    free(PWD);
    free(ORIGINALPWD);
    free(_ripshellHistDir);
}


void printStringArray(char ** arr){
    int j = 0, i = 0;
    while( arr[j] != NULL)
    {
        char * p = arr[j];
        while(1)
        {
            if(*p == '\0'){
                printf("\\0\n");
                break;  
            } 
            printf("%c", *p);
            p++;
        }
        j++;
    }
}

void printStringArrayByChar(char **arr){
    int j = 0, i = 0;
    while( arr[j] != NULL)
    {
        char * p = arr[j];
        while(1)
        {
            if(*p == '\0'){
                printf("\\0\n");
                break;  
            } 
            printf("%c ---", *p);
            p++;
        }
        j++;
    }
}

