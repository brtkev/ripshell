
#include <sys/types.h>
#include "src/headers.h"

void start();


int main(int argc, char **argv){
    loadEnv();
    char ** x = charArrayPopFront(argv, argc);

    // parseCommand(argc-1, x);
    start();    
    return 0;
}


void start(){
    int loop = 1;
    while(loop){
        char ** args;
        int count = getArguments(&args);
        loop = parseCommand(count, args);
        freeArgumentsArray(count, args);
    }
}