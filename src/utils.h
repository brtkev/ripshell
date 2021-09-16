
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