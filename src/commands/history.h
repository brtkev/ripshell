
void addToHistory(char ** args){
    FILE *fp = fopen(getenv("HISTORYDIR"), "a");
    if(fp != NULL){
        for(int i = 0; args[i] != NULL; i++){
            if(i != 0) fprintf(fp, " ");
            fprintf(fp, "%s", args[i]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}


int parseHistory(char ** args, int count){
    optind = 1;
    opterr = 0;
    int c, all = 0;
    int option_index = 0;
    static struct option long_options[] = {
        {"all",  no_argument,       0,  0 },
        {0,         0,                 0,  0 }
    };
    while (1) { 
        c = getopt_long(count, args, "", long_options, &option_index);
        if (c == -1)
            break;

        switch (c) {
            case 0:
                if(option_index == 0){
                    all = 1;
                }
                break;

            case '?':
                if((isprint(optopt))){
                    printf("Error : '%c' no es un argumento valido", optopt);
                }else{
                    printf("Error : '%s' no es un argumento valido", args[optind- 1]);
                }
                break;

            default:
                printf("?? getopt returned character code 0%o ??\n", c);
        }
    }
    return all;
}

int history(char ** args, int count){
    int last, all = -1;
    while(last != all){
        last = all;
        all = parseHistory(args, count);
    }
    
    FILE *fp = fopen(getenv("HISTORYDIR"), "r");
    if(fp != NULL){
        char buff[255];
        if ( all == 0 ){
            while(fgets(buff, 255, fp) != NULL);
            printf("%s", buff);
        }else{
            while(fgets(buff, 255, fp) != NULL){
                printf("%s", buff);
            }
        }
    }
    fclose(fp);
}