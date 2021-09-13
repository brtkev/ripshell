#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char RIPSHELLPATH[] = "/root";
static int commandLimit = 255;

void logIntro(){
    printf("\n%s$ ", RIPSHELLPATH);
}

char getNewCommand(char command[255]){
    fgets(command, commandLimit, stdin);
}

char *getPath(){
    return RIPSHELLPATH;
}
void setPath(char *newPath){
    strcpy(RIPSHELLPATH, newPath);
}