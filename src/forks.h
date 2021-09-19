

int forking(char ** args, int count){
    
    int pid = fork();
    if(pid == 0){
        char * execPath = getenv("EXECDIR");
        execv(execPath, args);
    }
    
    
}