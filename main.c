
#include "src/headers.h"

void start();

int main(int argc, char **argv){

    loadEnv();
    start();
    closeEnv();
    
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