
/*
 * Linkage file for
 * for 10.c file
 */

#include <stdio.h>
#include <stdlib.h>

#define assume(cond) \
    if (!(cond)) exit(0);

void prebody_f1(long long int choices, long long int& x, long long int& y) {
    assume((x >= 0));
    assume((x <= 2));
    assume((y <= 2));
    assume((y >= 0));
}

void loopbody_f2(long long int choices, long long int& x, long long int& y) {
    {
        // loop body
        (x = (x + 2));
        (y = (y + 2));
    }
}
