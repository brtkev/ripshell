


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
    FILE *fp = fopen(_ripshellHistDir, "r");
    if(fp != NULL){
        printf("??? %i\n", all);
        char buff[255];
        while(fgets(buff, 255, fp) != NULL){
            printf("%s", buff);
            if(all == 1) {
                break;
            }
        }
        printf("\n");
    }
}

int history(char ** args, int count){
    int c, all = 0;
    optind = 1;
    opterr = 0;
    while((c = getopt(count, args, ":--W;")) != -1){
        switch (c)
        {
        case 'W':
            printf(":(");
            if(strcmp(optarg, "all")){
                all = 1;
            }else{
                fprintf(stderr, "Error : opcion desconocida `--%s'.\n", optarg);
            }
            break;

        case '?':
            if (isprint(optopt))
                fprintf(stderr, "Error : opcion desconocida `-%c'.\n", optopt);
            else
                fprintf(stderr,
                        "Error : Caracter desconocido `\\x%x'.\n",
                        optopt);
            return 0;
        
        default:
            abort();
        }
    }
    _history(all);
}