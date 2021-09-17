

int linesIsActive(int nlines, int i){
    return ( i < nlines && 0 < nlines);
}

int printFileToConsole(char * fileName, int lines){
    FILE *fp = fopen(fileName, "r");
    if(fp != NULL){
        int i = 0;
        char buff[255];
        while(fgets(buff, 255, fp) != NULL && linesIsActive(lines, i)){
            printf("%s", buff);
            i++;
        }
        printf("\n");
    }
    fclose(fp);

}

int writeToFile(char * fileName, char * newFileName, int lines ){
    FILE *fp = fopen(fileName, "r"), *nfp = fopen(newFileName, "w");
    if(fp != NULL && nfp != NULL){
        int i = 0;
        char buff[255];
        while(fgets(buff, 255, fp) != NULL && linesIsActive(lines, i)){
            fprintf(nfp, buff);
            i++;
        }
    }
    fclose(nfp);
    fclose(fp);

}

int parseReadArgs(char ** args, int count){
    int c;
    int nLines = 0;
    char * newFileName = NULL;
    optind = 2;
    opterr = 0;
    while((c = getopt(count, args, "o:n:")) != -1){
        switch (c)
        {
        case 'o':
            newFileName = optarg;
            break;
        
        case 'n':
            nLines = atoi(optarg);
            break;

        case '?':
            if(optopt == 'o'){
                fprintf(stderr, "Error : -%c necesita nombrar el archivo de salida.\n", optopt);
            }else if (isprint(optopt))
                fprintf(stderr, "Error : opcion desconocida `-%c'.\n", optopt);
            else
                fprintf(stderr,
                        "Error : Caracter desconocido `\\x%x'.\n",
                        optopt);
                printf("%x\n", optopt);
            return 0;
        
        default:
            abort();
        }
    }
    if( newFileName != NULL){
        writeToFile(args[1], newFileName, nLines);
    }else{
        printFileToConsole(args[1], nLines);
    }
}

int ripshellRead(char ** args, int count){
    if(count > 1){
        parseReadArgs(args, count);
    }else{
        fprintf(stderr, "Error : Falta archivo'.\n");
    }
}