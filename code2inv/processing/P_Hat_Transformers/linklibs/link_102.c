
/*
 * Linkage file for
 * for 102.c file
 */

#include <stdio.h>
#include <stdlib.h>

#define assume(cond) \
    if (!(cond)) exit(0);

void prebody_f1(long long int choices, long long int& n, long long int& x) { (x = 0); }

void loopbody_f2(long long int choices, long long int& n, long long int& x) {
    {
        // loop body
        { (x = (x + 1)); }
    }
}
