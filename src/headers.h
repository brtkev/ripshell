#include "stdheaders.h"

void freeCommandLineVariables(char ** args, int count);
int getCommandLineCount(char * line, int lineSize);
char** getCommandLineVariables(char * line, int lineSize, int argCount);
int parseCommandLine(int argc, char **argv);
char * updatePWD();

#include "commands/cd.h"
#include "commands/say.h"
#include "commands/show.h"
#include "commands/pause.h"
#include "commands/read.h"
#include "commands/list.h"
#include "commands/history.h"
#include "commands/env.h"
#include "commands/help.h"

#include "utils.h"
#include "envLoad.h"
#include "parse.h"
#include "forks.h"


