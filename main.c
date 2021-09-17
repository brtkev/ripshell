
#include "src/headers.h"

void start();

int main(int argc, char **argv){

    updatePWD(&PWD);
    updatePWD(&ORIGINALPWD);
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