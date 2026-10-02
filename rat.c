#include <stdbool.h>

#ifndef RAT_H
#define RAT_H

struct rtype {
    int n, d;
};

typedef struct rtype *rat;

rat createRat(int n,int d){
    rat temp_rat;
    
    temp_rat->d = d;
    temp_rat->n = n;

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
    return (r1 + r2);
}
rat sub(const rat r1, const rat r2){
    return (r1 - r2);
}

#endif