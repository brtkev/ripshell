# ripshell
Taller 1 Sistemas Operativos

```batch
    $make
    ./RUN
```


## 

- [ ] comandos
- [ ] hilo
- [ ] parser


# List.h

Hice mi propia implementacion de una linked list, porque puede que C no permita oop, pero eso no me va a deterner.
implemento metodos a medida que voy necesitando

### newListString y newNodeString

son lo que suenan, basicamente constructores para tener ya una plantilla universal de como debe ser la instancia.

### push O(1)
empuja nuevos elementos a la parte final de la lista, usando el atributo tail es constante

### print O(N)
print cada elemento de la lista
es para hacer debug mas que cualquier cosa

### free O(N)
libera la memoria de todos los hijos, no quiero memory leeks por ahi



# parse.h
> saber como funcionan los pointers y ser bueno en ellos son cosas totalmente diferentes, he perdido totalmente la practica

### mi mas grande problema

dios mio juro que odio la poca info que tuve acerca de esto.
o lo ciego que fui no se cual es peor
en resumen, getopt() me daba un error en el ultimo char siempre que usaba el getLine()
y obvio yo no entendia porque, basicamente pase horas tratando de arreglar este problema.

tl;dr getLine() al igual que fgets() lee el '\n' del final, y eso no va con getopt(), de hecho va tan mal que cuando 
me imprime el caracter que da error con "printf("%x\n", optopt);" el caracter que aparece es 'a', y yo no sabia que significaba eso, ya que la mayoria de caracteres al ser printeados con "%x" daban 2 caracteres (ejem 'd6').
al final despues de probar mil metodos descubri que era getLine el del problema y que yo estaba desinformado.

```c
int getCommandLineCount(char * line, int lineSize){
    int count = 0;
    for(int i = 0; i < lineSize; i++){
        if(line[i] == '\n' || line[i] == '\0' || line[i] == ' '){
            line[i] = '\0';
            count++;
        }
    }return count;
}
```

asi arreglamos el problema

### getCommandLine
al hacer la funcion ```void getCommandLine()``` tuve mas de un inconveniente

primero que nada no soy un experto en pointer, pero afortunadamente soy bueno siendo malo.
basicamente aprendi de mis errores y aprendi a usar los pointers, aunque aun asi de vez en cuando me dan problemas

con esta funcion tuve el inconveniente de que al correrla la primera vez todo funcionaba perfectamente, pero
al llamarla una segunda vez, la variable ```char * line``` por alguna extraña razon no se libraria de sus pointers
o no se que cosa, pero al llamar la funcion una segunda vez y hacer el llamado de  

```lineSize = getline(&line, &bufferSize, stdin);```

el programa creashearia, y esto al parecer fue porque no aplicaba ```free(line)```

#### 
