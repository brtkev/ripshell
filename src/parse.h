#include "stdheaders.h"

char *path = "~/user";


void getCommandLine(){
    printf("\n%s $ ", path);
    
    size_t lineSize;
    size_t bufferSize = 32;
    char * line = (char *)malloc(bufferSize * sizeof(char*));
    lineSize = getline(&line, &bufferSize, stdin);
    char **args = getCommandLineVariables(line, lineSize);
    int argCount = getCommandLineCount(line, lineSize);
    printf("\n");
    for(int i = 0; i < argCount; i++){
        printf("%s\n", args[i]);
    }
    parseCommandLine(argCount, args);
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

char** getCommandLineVariables(char * line, int lineSize){
    int argCount = getCommandLineCount(line, lineSize);
    char **args = malloc(argCount * sizeof(char**)); 
    printf("count : %i\n", argCount);
    printf("string : %s\n", line);
    printf("line addr : %p\n ", line);

    // char aux;
    // aux = *line;
    // printf("char aux: %p\n ", &aux);
    printf("\n");

    for(int i = 0, j = 0; i< lineSize; i++){
        if(validateLinePosition(line, i) == 1){
            // strcpy(args[j], &line[i]);
            args[j] = &line[i];
            j++;
        }
    }
    printf("args addr : %p\n", args[0]);
    return args;
}


int parseCommandLine(int argc, char **argv)
{
    int aflag = 0;
    int bflag = 0;
    char *cvalue = NULL;
    int index;
    int c;
    while ((c = getopt(argc, argv, "abc:")) != -1)
        switch (c)
        {
        case 'a':
            aflag = 1;
            break;
        case 'b':
            bflag = 1;
            break;
        case 'c':
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
