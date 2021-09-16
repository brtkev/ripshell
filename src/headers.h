#include "stdheaders.h"

void freeCommandLineVariables(char ** args, int count);
int getCommandLineCount(char * line, int lineSize);
char** getCommandLineVariables(char * line, int lineSize, int argCount);
int parseCommandLine(int argc, char **argv);

#include "utils.h"
#include "parse.h"
#include "commands.h"
