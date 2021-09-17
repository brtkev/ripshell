
void test(){
    char cwd[MAX_PATH];
    if(getcwd(cwd, sizeof(cwd)) != NULL){
        printf("%s\n", cwd);
    }else{
        perror("getcwd() error");
    }
}

int getInitialCwd(char ** cwdPointer){
    char cwd[MAX_PATH];
    // char * cwd = (char*)malloc(MAX_PATH);
    if(getcwd(cwd, sizeof(cwd)) != NULL){
        *cwdPointer = malloc(sizeof(cwd));
        strcpy(*cwdPointer, cwd);
        return 1;
    }else{
        perror("getcwd() error");
        return 0;
    }
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