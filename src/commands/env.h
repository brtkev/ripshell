

int enviroment(){

    // printf("PWD=%s\n",PWD);
    // printf("ORIGINALPWD=%s\n",ORIGINALPWD);


    extern char **environ;
    char **s = environ;

    for (; *s; s++) {
        printf("%s\n", *s);
    }
}