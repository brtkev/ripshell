
#include <sys/types.h>
#include "src/headers.h"

void start();


int main(int argc, char **argv){


    // fork();
    // printf("hello world");
    start();    
    return 0;
}


void start(){
    loadEnv();
    int loop = 1;
    while(loop){
        char ** args;
        int count = getArguments(&args);
        loop = parseCommand(count, args);
        freeArgumentsArray(count, args);
    }
    closeEnv();
}