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
rat norm(const rat){
    rat temp_rat;

    return temp_rat;
}
rat reduce(const rat){
    rat temp_rat;

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

#endif