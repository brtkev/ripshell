


void addToHistory(char ** args){
    FILE *fp = fopen(_ripshellHistDir, "a");
    if(fp != NULL){
        for(int i = 0; args[i] != NULL; i++){
            fprintf(fp, "%s ", args[i]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void history(){
    FILE *fp = fopen(_ripshellHistDir, "r");
    if(fp != NULL){
        char buff[255];
        while(fgets(buff, 255, fp) != NULL){
            printf("%s", buff);
        }
        printf("\n");
    }
}