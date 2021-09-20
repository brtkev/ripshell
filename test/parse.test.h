// #include "../src/parse.h"

int _parseArgumentTEST(){
    
    Argument arg = _parseArgument((char *)"--exec");
    if(arg.size != 6)return 1;
    else if(arg.type != 2) return 2;
    else if(strcmp(arg.string, (char*)"exec") != 0){
        free(arg.string);
        return 3;
    } 
    free(arg.string);

    arg = _parseArgument((char *)"-o");
    if(arg.size != 2)return 4;
    else if(arg.type != 1) return 5;
    else if(strcmp(arg.string, (char*)"o") != 0){
        free(arg.string);
        return 6;
    } 
    free(arg.string);

    arg = _parseArgument((char *)"read");
    if(arg.size != 4)return 7;
    else if(arg.type != 0) return 8;
    else if(strcmp(arg.string, (char*)"read") != 0){
        free(arg.string);
        return 9;
    } 
    free(arg.string);

    return 0;
}


int _parserTEST(){
    char ** argv = malloc(5 * sizeof(char**));
    
    argv[0] = malloc(6*sizeof(char*));argv[0] = "read";
    argv[1] = malloc(6*sizeof(char*));argv[1] = "file.txt";
    argv[2] = malloc(6*sizeof(char*));argv[2] = "-o";
    argv[3] = malloc(6*sizeof(char*));argv[3] = "outputfile.txt";

    argv[4] = NULL;
    _parser(4, argv);
}