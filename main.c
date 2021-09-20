
#include <sys/types.h>
#include "src/headers.h"
#include "test/test.h"

void start();


int main(int argc, char **argv){
    loadEnv();
    startTest();

    // printStringArray(argv);
    // return 0;
    // if(argc > 1){

    // }else{
    //     start();
    // }
    // if(argc > 1){
    //     if(strcmp(argv[1], (char*)"--exec"))
    // }

    // start();    
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