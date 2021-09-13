#include <stdlib.h>
#include <stdbool.h>
#include "ripshell.h"


void start(){
    bool exit = false;
    while(!exit){
        logIntro();
        char command[255]; 
        getNewCommand(command);
        printf(command);
        return;
    }
}