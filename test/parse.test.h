char** getCommandLineVariables(char * line, int lineSize, int argCount){
    char **args = malloc(argCount * sizeof(char**)); 
    printf("count : %i\n", argCount);
    printf("line string : %s\n", &line[8]);
    printf("line addr : %p\n ", &line);

    char aux;
    aux = *line;
    printf("char aux: %p\n ", &aux);
    printf("\n");

    for(int i = 0, j = 0; i< lineSize; i++){
        if(validateLinePosition(line, i) == 1){
            // strcpy(args[j], &line[i]);
            args[j] = &line[i];
            j++;
        }
    }
    printf("args string : %s\n", args[0]);
    printf("args addr : %p\n", &args[0]);
    args[0][0] = 's';
    printf("args string : %s\n", args[0]);
    printf("args addr : %p\n", &args[0]);
    printf("string : %s\n", line);
    printf("sex addr : %p\n", 's');


    return args;
}