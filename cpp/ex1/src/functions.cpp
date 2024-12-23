#include "functions.h"
#include "globals.h"

void addValue(int &number){
    number+=globalValue;
}

int counter(){
    static int count = 0;
    return ++count;
}