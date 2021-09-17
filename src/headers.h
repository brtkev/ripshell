#include "stdheaders.h"

char * PWD;
char * ORIGINALPWD;

void freeCommandLineVariables(char ** args, int count);
int getCommandLineCount(char * line, int lineSize);
char** getCommandLineVariables(char * line, int lineSize, int argCount);
int parseCommandLine(int argc, char **argv);
int updatePWD(char ** pwdPointer);

#include "commands/cd.h"
#include "commands/say.h"
#include "commands/show.h"
#include "commands/pause.h"
#include "commands/read.h"
#include "commands/list.h"

#include "utils.h"
#include "parse.h"


