
#include "src/headers.h"

//command arg arg2 arg3 arg4

void start();



int main(int argc, char **argv){

    getInitialCwd(&PWD);
    start();
    free(PWD);
    return 0;
}


void start(){

    int loop = 1;
    while(loop){
        char ** args;
        int count = getArguments(&args);
        loop = parseCommand(count, args);
        // parseArguments(count, args);
        freeArgumentsArray(count, &args);
    }
}