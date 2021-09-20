
#include "parse.test.h"
#include "utils.test.h"

void testResult(char * testName, int result){
    printf("%s :\n", testName);
    if(result == 0){
        printf("    passed!\n");
    }else{
        printf("    failed at %i\n", result);
    }
}

int startTest(){
    printf("start testing:\n\n");

    testResult("_parseArgument()", _parseArgumentTEST());
    testResult("_parser()", _parserTEST());


    testResult("strCopy()", strCopyTEST());
    testResult("charArrayPopFront()", charArrayPopFrontTEST());
    testResult("arrayCopy()", arrayCopyTEST());

}