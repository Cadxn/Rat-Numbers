#include <stdio.h>
#include "rat.h"
#include "rat.c"

int main(){

    rat r1 = createRat(2,3), r2 = createRat(5,-6);
    printf("add(r1,r2) = %s\n",toString(add(r1,r2)));
    r1->d = 0;
    printf("is r1 well formed? %s\n",wellFormed(r1)?"yes":"no");

    return 0;
}