
#include "src/headers.h"

//command arg arg2 arg3 arg4

void start();

int main(int argc, char **argv){
    // getCommandLine();
    // printf("%i", NULL == '\0');
    // for (size_t j = 0; j < argc; j++)
    // size_t j = 0;
    // while( argv[j] != NULL)
    // {
    //     char * p = argv[j];
    //     for (size_t i = 0; i < 10; i++)
    //     {
    //         if(*p == '\0'){
    //             printf("\\0 --- ");
    //             break;  
    //         } 
    //         printf("%c --- ", *p);
    //         p++;
    //     }
    //     j++;
    // }
    
    // start();
    char ** args;
    int count = getArguments(&args);
    // parseCommandLine(count, args);
    freeArgumentsArray(count, &args);
    return 0;
}


void start(){

    bool exit = false;
    while(!exit){
        
        getCommandLine();
        break;
        // exit = executeNewCommandLine();
    }
}