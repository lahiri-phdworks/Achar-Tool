
/*
 * Linkage file for
 * for 33.c file
 */

#include <stdio.h>
#include <stdlib.h>

#define assume(cond) \
    if (!(cond)) exit(0);

void prebody_f1(long long int choices, long long int& n, long long int& v1, long long int& v2,
                long long int& v3, long long int& x) {
    (x = n);
}

void loopbody_f2(long long int choices, long long int& n, long long int& v1, long long int& v2,
                 long long int& v3, long long int& x) {
    {
        // loop body
        (x = (x - 1));
    }
}
