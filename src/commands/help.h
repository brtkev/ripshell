
int helpRead(char * command){
    
    FILE * fp = fopen( strcat( getenv("HELPDIR"), command ), "r");
    if(fp != NULL){
        char buff[255];
        while(fgets(buff, 255, fp) != NULL){
            printf("%s", buff);
        }
    }
}

int help(char * command){
    if(command != NULL){
        helpRead(command);
    }else{
        printf("%s%s%s%s%s%s%s%s%s%s",
        "cd                 [dir]\n",
        "show               [dir/file]\n",
        "say                [msg1] [msg2] [msg3] ...\n",
        "enviroment         WIP\n",
        "exit\n",
        "pause\n",
        "read               [-o] [-n]\n",
        "list\n",
        "help               [command]\n\n",
        "para mas informacion help [command]\n");
        }
    return 0; 
}