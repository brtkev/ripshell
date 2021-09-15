#include "stdheaders.h"

int getCommandLineCount(char * line, int lineSize);
char** getCommandLineVariables(char * line, int lineSize);
int parseCommandLine(int argc, char **argv);
// #include "List.h"
#include "parse.h"
// #include "ripshell.h"
#include "commands.h"
#include "thread.h"
