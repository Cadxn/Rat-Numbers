#include <stdbool.h>

#ifndef RAT_H
#define RAT_H

struct rtype {
    int n, d;
};

typedef struct rtype *rat;

rat createRat(int n,int d){
    rat temp_rat;

    temp_rat->n = n;
    temp_rat->d = d;

    return temp_rat;
}
rat norm(const rat r){
    rat temp_rat;
    int count = 0;

    for(int i = 0; i<9;i++){
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
    rat temp_rat;
    int count = 0;

    for(int i = 0; i<9;i++){
        if(((r->d)%i==0) && ((r->n%i)==0)){
            count = i;
        }
    }

    temp_rat->d /= count;
    temp_rat->n /= count;

    return temp_rat;
}
int cmp(const rat r1, const rat r2){
    rat temp_rat;

    return temp_rat;
}

rat add(const rat r1, const rat r2){
    rat temp_rat;

    temp_rat->n = r1->n + r2->n;
    temp_rat->d = r1->d + r2->d;

    return temp_rat;
}
rat sub(const rat r1, const rat r2){
    rat temp_rat;

    temp_rat->n = r1->n - r2->n;
    temp_rat->d = r1->d - r2->d;

    return temp_rat;
}
rat mul(const rat r1, const rat r2){
    rat temp_rat;

    temp_rat->n = r1->n - r2->n;
    temp_rat->d = r1->d - r2->d;

    return temp_rat;
}
rat divide(const rat r1, const rat r2){
    rat temp_rat;

    temp_rat->n = r1->n / r2->n;
    temp_rat->d = r1->d / r2->d;

    return temp_rat;
}
rat inverse(const rat r){
    rat temp_rat;
    temp_rat->d = r->n;
    temp_rat->n = r->d;

    return temp_rat;
}
bool wellFormed(const rat r){
    bool isWellFormed;

    return isWellFormed;
}

#endif