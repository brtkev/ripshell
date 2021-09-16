#include "stdheaders.h"

char *path = "~/user";
size_t bufferSize = 32;

int validateChar(char c){
    return (c == '\0' || c == '\n' || c == ' ');
}

int _getArgument(char ** argument){
    *argument = (char*)malloc(bufferSize * sizeof(char*));
    char c, *p = *argument;
    int i = 0;
    while(1){
        c = getc(stdin);
        if(validateChar(c)){
            *p = '\0';
            break;
        }
        *p = c;
        p++;
    };
    return (c == '\n');
}

int getArguments(char ***args){
    *args = (char **)malloc(bufferSize * sizeof(char**));
    char **p = *args;
    int count = 0;
    while(1){
        char * arg;
        int endOfLine = _getArgument(&arg);
        *p = arg;
        p++;
        count++;
        if(endOfLine){
            *p = '\0';
            p = NULL;
            break;
        }
    }
    return count;
}


void freeArgumentsArray(int count, char *** arguments){
    int i = 0;
    char ** p = *arguments;
    printf("init\n");
    while(i < count){
        free(p);
        p = NULL;
        p++;i++;
    }
    free(*arguments);
    *arguments = NULL;
}


void getCommandLine(){
    printf("\n%s $ ", path);
    
    size_t lineSize;
    size_t bufferSize = 32;
    char * line = (char *)malloc(bufferSize * sizeof(char*));
    
    lineSize = getline(&line, &bufferSize, stdin);
    printf("??\n");
    int argCount = getCommandLineCount(line, lineSize);
    char **args = getCommandLineVariables(line, lineSize, argCount);

    printf("\n");
    for (size_t j = 0; j < argCount; j++)
    {
        char * p = args[j];
        for (size_t i = 0; i < 10; i++)
        {
            printf("%c --- ", *p);
            if(*p == '\0') break;
            p++;
        }
    }
    // parseCommandLine(argCount, args);
    free(line);
    freeCommandLineVariables(args, argCount);
}

void freeCommandLineVariables(char ** args, int count){

    for(int i = 0; i < count; i++){
        free(&args[i]);
        args[i] = NULL;
    }
    free(*args);
}

int getCommandLineCount(char * line, int lineSize){
    int count = 0;
    for(int i = 0; i < lineSize; i++){
        if(line[i] == '\n' || line[i] == '\0' || line[i] == ' '){
            line[i] = '\0';
            count++;
        }
    }return count;
}

int validateLinePosition(char * line, int i){
    if(i == 0){
        return 1;
    }else if(line[i - 1] == '\0'){
        return 1;
    }else{
        return 0;
    }
}

char** getCommandLineVariables(char * line, int lineSize, int argCount){
    char **args = malloc(argCount * sizeof(char**)); 
    for(int i = 0, j = 0; i< lineSize; i++){
        if(validateLinePosition(line, i) == 1){
            args[j] = &line[i];
            j++;
        }
    }
    return args;
}


int parseCommandLine(int argc, char **argv)
{
    int aflag = 0;
    int bflag = 0;
    char *cvalue = NULL;
    int index;
    int c;
    optind = 1;
    while ((c = getopt(argc, argv, "abc:")) != -1)
        // printf("%u ->", c);
        switch (c)
        {
        case 'a':
            aflag = 1;
            printf("a");
            break;
        case 'b':
            printf("b");
            bflag = 1;
            break;
        case 'c':
            printf("c");
            cvalue = optarg;
            break;
        case '?':
            if (optopt == 'c')
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            else if (isprint(optopt))
                fprintf(stderr, "Unknown option `-%c'.\n", optopt);
            else
                fprintf(stderr,
                        "Unknown option character `\\x%x'.\n",
                        optopt);
                printf("%x\n", optopt);
            return 1;
        default:
            abort();
        }
    printf("aflag = %d, bflag = %d, cvalue = %s\n",
            aflag, bflag, cvalue);

    for (index = optind; index < argc; index++)
        printf("Non-option argument %s\n", argv[index]);
    return 0;
}
