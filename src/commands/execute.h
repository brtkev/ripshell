

char ** parseExecute(int argc, char ** argv){
    
}

int execute(int count, char ** args){

    // printStringArray(args);
    int pid = fork();
    if(pid == 0){
        char * execPath = getenv("EXECDIR");
        printf("%i\n", execv(execPath, args));
    }
}