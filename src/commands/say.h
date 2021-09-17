
int say(char ** args, int count){
    for (int i = 1; i < count; i++)
    {
        printf("%s ", args[i]);
    }
    
    return 1;
}