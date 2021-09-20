

char * updatePWD(){
    char pwd[PATH_MAX];
    if(getcwd(pwd, sizeof(pwd)) != NULL){
        char *nPwd  = malloc(sizeof(pwd));
        strcpy(nPwd, pwd);
        setenv("PWD", nPwd, 1);
        return nPwd;
    }else{
        perror("getcwd() error");
        return NULL;
    }
}

int _initOriginalPWD(char *cwd){
    char * auxp, *p, *ORIGINALPWD = malloc(PATH_MAX * sizeof(char*));
    auxp = cwd;p = ORIGINALPWD;
    while(*auxp != '\0'){
        if(*auxp == '\\' || *auxp == '/'){
            *p = *auxp;
            p++;
        }
        *p = *auxp;
        p++;auxp++;
    }
    *p = '\0';
    setenv("ORIGINALPWD", ORIGINALPWD, 1);
    free(ORIGINALPWD);
}

int restartHistoryFile(){
    
    FILE *fp = fopen(getenv("HISTORYDIR"), "w");
    fclose(fp);
}

int loadEnv(){
    char *buffer = updatePWD();
    _initOriginalPWD(buffer);
    char * origin = malloc(PATH_MAX* sizeof(char*));
    strcpy(origin, getenv("ORIGINALPWD"));
    sprintf(buffer, "%s%s", origin, "//.history");
    setenv("HISTORYDIR", buffer, 0);
    sprintf(buffer, "%s%s", origin, "//src//helpDocs//");
    setenv("HELPDIR", buffer, 0);
    sprintf(buffer, "%s%s", origin, "//ripshell");
    setenv("EXECDIR", buffer, 0);
    
    restartHistoryFile();
    free(origin);
    free(buffer);
    
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


int charArraySize(char **arr){
    char **i = arr;
    int count = 0;
    for(; *i; i++ && count++);
    return count;
}


char *strCopy(char * string){
    char * new = malloc(PATH_MAX * sizeof(char*)), *i, *j;
    i = new, j= string;
    int count = 0;
    for(;*j; i++ && j++ && count++){
        *i = *j;
    }
    return realloc(new , count * sizeof(char*));


}

char ** charArrayPopFront(char ** arr, int size){
    if(size == 0) size = charArraySize(arr);
    char ** newArr = malloc(size * sizeof(arr)), ** i, **j;
    i = arr; j = newArr;
    for(int count = 0; *i; i++ && count++){
        if(count > 0){
            *j = strCopy(*i);
            // *j = *i;
            j++ ;
        }
    }
    return newArr;
}

char ** arrayCopy(char ** arr){
    char ** newArr = malloc(PATH_MAX * sizeof(arr)), ** i, **j;
    i = arr; j = newArr;
    int count = 0;
    for(; *i; i++ && j++ && count++){
        *j = strCopy(*i);
    }
    return realloc(newArr, count * sizeof(char**));
}