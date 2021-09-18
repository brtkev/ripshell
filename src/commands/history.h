


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

void _history(int all){
    if ( all == 0 ){
        printf("last commnad");
    }else{
        FILE *fp = fopen(_ripshellHistDir, "r");
        if(fp != NULL){
            char buff[255];
            while(fgets(buff, 255, fp) != NULL){
                printf("%s", buff);
            }
            printf("\n");
        }
    }
}

int history(char ** args, int count){
    optind = 1;
    opterr = 0;
    int c, digit_optind = 0, all = 0;
    while (1) {
        int this_option_optind = optind ? optind : 1;
        int option_index = 0;
        static struct option long_options[] = {
            {"all",  no_argument,       0,  0 },
            {0,         0,                 0,  0 }
        };

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
    _history(all);
}