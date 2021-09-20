
#include <sys/types.h>
#include "src/headers.h"
#include "test/test.h"
void startOrExecute(int argc, char ** argv);
void start();


int main(int argc, char **argv){
    loadEnv();
    // startTest();
    // return 0;

    startOrExecute(argc, argv);

    // start();    
    return 0;
}



void startOrExecute(int argc, char ** argv){
    if(argc > 1){
        if(strncmp(argv[1], (char*)"--exec", 6) == 0){
            char **  auxArgv = charArrayPopFront(argv, argc);
            argc--;
            if(argc > 1){
                parseCommand(argc, auxArgv);
            }else{
                int size = 0;
                char ** args = parseExecuteSingleStr(argv[0], &size);
            }
        }else{
            printf("Error : Ripshell no acepta commandos que no sean parametros de --exec\nvea help --exec para mas informacion o inicie ripshell sin ningun commando.\n");
        }
    }else{
        start();
    }
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