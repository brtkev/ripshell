#include "stdheaders.h"

size_t bufferSize = 32;

struct argument
{
    int size, type;
    char * name, * value;
};

typedef struct argument Argument;


int validateChar(int c){
    return (c == '\0' || c == '\n' || c == ' ');
}

int _getArgument(char ** argument){
    int c;
    char *p = *argument;
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
    printf("\n%s $", getenv("PWD"));
    *args = (char **)malloc(bufferSize * sizeof(char**));
    char **p = *args;
    int count = 0;
    while(1){
        char * arg = (char*)malloc(bufferSize * sizeof(char*));
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


void freeArgumentsArray(int count, char ** arguments){
    for(int i = 0; arguments[i] != NULL; i++){
        free(arguments[i]);
        arguments[i] = NULL;
    }
    free(arguments);
    arguments = NULL;
    
}    

int parseCommand(int argc, char **argv){
    char * command = argv[0];
    if(strcmp(command, "exit") == 0) return 0;
    else if(strcmp(command, "cd") == 0){
        cd(argv[1]);
    }else if(strcmp(command, "say") == 0){
        say(argv, argc);
    }else if(strcmp(command, "show") == 0){
        show(argv[1]);
    }else if(strcmp(command, "pause") == 0){
        pause();
    }else if(strcmp(command, "read") == 0){
        ripshellRead(argv, argc);
    }else if(strcmp(command, "list") == 0){
        list();
    }else if(strcmp(command, "enviroment") == 0){
        enviroment();
    }else if(strcmp(command, "history") == 0){
        history(argv, argc);
    }else if(strcmp(command, "help") == 0){
        help(argv[1]);
    }else if(strcmp(command, "--exec") == 0){
        execute(argc, argv);
    }

    addToHistory(argv);
    return 1;
}



Argument _parseArgument(char * arg){
    Argument newArg;
    newArg.size = 0;
    newArg.name = malloc(PATH_MAX * sizeof(char *));
    newArg.type = 0;
    char * i = arg , * j = newArg.name;
    for(; *i; i++ , newArg.size++){
        if(*i == '-' && newArg.size < 2 && newArg.size == newArg.type){
            newArg.type++;
        }else{
            *j = *i;
            j++;
        }
    }
    *j = *i;
    newArg.name = realloc(newArg.name, newArg.size * sizeof(char*));
    return newArg;
}

int _parser(int argc, char ** argvars){
    char ** argv;
    if(strcmp(argvars[0], (char*)"/.ripshell") == 0){
        argv = charArrayPopFront(argv, argc);
        argc--;
    }else{
        argv = arrayCopy(argvars);   
    }
    Argument lastArg;
    lastArg.type = 0;
    for(int i = 0; argv[i]; i++){
        Argument arg = _parseArgument(argv[i]);

        if(lastArg.type > 0 && arg.type == 0){
            lastArg.value = arg.name;
        }
    }
}