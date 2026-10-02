#include <stdbool.h>
#include <stdlib.h>
#include "rat.h"

#ifndef RAT_H
#define RAT_H


///////////////////////////////////////
// Creates Rational Number Structure //
///////////////////////////////////////


rat createRat(int n,int d){
    rat temp_rat = (rat)malloc(sizeof(struct rtype));

    temp_rat->n = n;
    temp_rat->d = d;

    if(temp_rat->d==0){
        printf("Undefined");
        exit(1);
    }

    return temp_rat;
}

///////////////////////////////////////
// Normal, Reduce, Compare functions //
///////////////////////////////////////


rat norm(const rat r){
    rat temp_rat = r;
    int count = 1, size = 1;

    if(abs(r->d)>abs(r->n)){
        size = r->d;
    } else {
        size = r->n;
    }


    for(int i = 1; i<size;i++){
        if(((r->d)%i==0) && ((r->n%i)==0)){
            count = i;
        }
    }

    temp_rat->d /= count;
    temp_rat->n /= count;

    if(temp_rat->d<0){
        temp_rat->d*=-1;
        temp_rat->n*=-1;
    }

    return temp_rat;
}
rat reduce(const rat r){
    rat temp_rat = r;

    if(r->n == 0){
        temp_rat->n = 0;
        temp_rat->d = 1;
        return temp_rat;
    }

    int count = 1, size = 1;

    if(abs(r->d)>abs(r->n)){
        size = r->d;
    } else {
        size = r->n;
    }
    
    for(int i = 1; i<9;i++){
        if(((r->d)%i==0) && ((r->n%i)==0)){
            count = i;
        }
    }


    temp_rat->d /= count;
    temp_rat->n /= count;

    return temp_rat;
}
int cmp(const rat r1, const rat r2){

    int ratr1 = 0, ratr2 = 0;

    ratr1 = r1->n * r2->d;
    ratr2 = r2->n * r1->d;

    if(ratr1 < ratr2){
        return -1;
    } else if(ratr1==ratr2){
        return 0;
    } else{
        return 1;
    }
}

///////////////////////////////////////////////////////////////////
// Addition, Subtraction, Multiplicative, and Division functions //
///////////////////////////////////////////////////////////////////

rat add(const rat r1, const rat r2){
    rat temp_rat = malloc(sizeof(struct rtype));

    temp_rat->n = (r1->n * r2->d) + (r2->n * r1->d);
    temp_rat->d = r1->d * r2->d;

    temp_rat = reduce(temp_rat);
    temp_rat = norm(temp_rat);

    return temp_rat;
}
rat sub(const rat r1, const rat r2){
    rat temp_rat = malloc(sizeof(struct rtype));

    temp_rat->n = (r1->n * r2->d) - (r2->n * r1->d);
    temp_rat->d = r1->d * r2->d;

    temp_rat = reduce(temp_rat);
    temp_rat = norm(temp_rat);

    return temp_rat;
}
rat mul(const rat r1, const rat r2){
    rat temp_rat = malloc(sizeof(struct rtype));

    temp_rat->n = r1->n * r2->n;
    temp_rat->d = r1->d * r2->d;

    temp_rat = reduce(temp_rat);
    temp_rat = norm(temp_rat);

    return temp_rat;
}
rat divide(const rat r1, const rat r2){
    rat temp_rat = malloc(sizeof(struct rtype));

    temp_rat->n = r1->n * r2->d;
    temp_rat->d = r1->d * r2->n;

    temp_rat = reduce(temp_rat);
    temp_rat = norm(temp_rat);

    return temp_rat;
}

/////////////////////////////////////////////////
// Inverse, wellFormed, and toString Functions //
/////////////////////////////////////////////////



rat inverse(const rat r){
    rat temp_rat = malloc(sizeof(struct rtype));

    temp_rat->d = r->n;
    temp_rat->n = r->d;

    if(temp_rat->d==0){
        printf("Undefined");
        exit(1);
    }

    temp_rat = reduce(temp_rat);
    temp_rat = norm(temp_rat);

    return temp_rat;
}
bool wellFormed(const rat r){
    if(r->d == 0){
        return false;
    }

    return true;
}
char *toString(const rat r){
    char *temp_string = malloc(sizeof(char) * 30);

        snprintf(temp_string, 30, "%d/%d", r->n, r->d);


    return temp_string;
}

#endif