
/*
 * Linkage file for
 * for 86.c file
 */

#include <stdio.h>
#include <stdlib.h>

#define assume(cond) \
    if (!(cond)) exit(0);

void prebody_f1(long long int choices, long long int& x, long long int& y, long long int& z1,
                long long int& z2, long long int& z3) {
    (x = -50);
}

void loopbody_f2(long long int choices, long long int& x, long long int& y, long long int& z1,
                 long long int& z2, long long int& z3) {
    {
        // loop body
        {
            (x = (x + y));
            (y = (y + 1));
        }
    }
}
