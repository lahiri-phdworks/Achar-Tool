
/*
 * P-Hat Transformation
 * for Colossus : 82.c file
 */

#include <assert.h>
#include <klee/klee.h>
#include <loop_82.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>

#define UNROLL_LIMIT 1

#define setflag(cond, flag) \
    if (!cond) flag = 1;

#define assume(cond) \
    if (!cond) exit(0);

#define INV(z1, z2, z3, i, x, y) PHI

long long unsigned int counter = 0;
int preflag = 0, loopflag = 0, postflag = 0;
long long unsigned int precount = 0, loopcount = 0, postcount = 0;

// COMMENT : Precheck function
void precheck(int z1, int z2, int z3, int i, int x, int y) {
    int f = preflag;
    setflag(INV(z1, z2, z3, i, x, y), preflag);
    if (f == 0 && preflag == 1) {
        printf("Pre : %s : %d, %s : %d, %s : %d, %s : %d, %s : %d, %s : %d\n", "z1", z1, "z2", z2,
               "z3", z3, "i", i, "x", x, "y", y);
        /* assert(0); */
    }
}

// COMMENT : Loopcheck function
void loopcheck(int temp_z1, int temp_z2, int temp_z3, int temp_i, int temp_x, int temp_y, int z1,
               int z2, int z3, int i, int x, int y) {
    int f = loopflag;
    setflag(INV(z1, z2, z3, i, x, y), loopflag);
    if (f == 0 && loopflag == 1) {
        printf("LoopStart : %s : %d, %s : %d, %s : %d, %s : %d, %s : %d, %s : %d\n", "z1", temp_z1,
               "z2", temp_z2, "z3", temp_z3, "i", temp_i, "x", temp_x, "y", temp_y);
        printf("LoopEnd : %s : %d, %s : %d, %s : %d, %s : %d, %s : %d, %s : %d\n", "z1", z1, "z2",
               z2, "z3", z3, "i", i, "x", x, "y", y);
        /* assert(0); */
    }
}

// COMMENT : Postcheck Macro
#define postcheck(cond, z1, z2, z3, i, x, y)                                     \
    \ 
{                                                                           \
        \ 
    int f = postflag;                                                            \
        \ 
   setflag(cond, postflag);                                                      \
        \ 
    if (f == 0 && postflag == 1) {                                               \
            \ 
        printf("Post : %s : %d, %s : %d, %s : %d, %s : %d, %s : %d, %s : %d\n", \ 
 "z1",                                                                           \
               z1, "z2", z2, "z3", z3, "i", i, "x", x, "y", y); /* assert(0); */ \
        \ 
}                                                                       \
    }

int main(int argc, char* argv[]) {
    // variable declarations

    int z1 = 0;
    int z2 = 0;
    int z3 = 0;
    int i;
    int x;
    int y;
    int choices;
    // klee make symbolic calls.
    klee_make_symbolic(&i, sizeof(i), "i_sym");
    klee_make_symbolic(&x, sizeof(x), "x_sym");
    klee_make_symbolic(&y, sizeof(y), "y_sym");
    klee_make_symbolic(&choices, sizeof(choices), "choices_sym");

    // Translate() Colossus
    if (choices > 10000) {
        (i = 0);
        klee_assume((x >= 0));
        klee_assume((y >= 0));
        klee_assume((x >= y));
        precount++;
        // fprintf(fptr, "Pre\n");
        // precheck
        precheck(z1, z2, z3, i, x, y);
    } else {
        // loop-check program
        // assume((loopflag + postflag < 2));
        klee_assume(INV(z1, z2, z3, i, x, y));
        // Loop Condition
        if ((choices > 2500)) {
            // K-Bounded Exploration
            int unroll = UNROLL_LIMIT;
            while ((choices > 2500) && unroll--) {
                // assume((loopflag == 0));
                int temp_z1 = z1;
                int temp_z2 = z2;
                int temp_z3 = z3;
                int temp_i = i;
                int temp_x = x;
                int temp_y = y;

                {
                    // loop body
                    if ((i < y)) {
                        (i = (i + 1));
                    }
                }
                // fprintf(fptr, "Loop\n");
                // fprintf(fptr, "Flag : %d\n", reach_flag);
                // assume(reach_flag);

                loopcount++;
                loopcheck(temp_z1, temp_z2, temp_z3, temp_i, temp_x, temp_y, z1, z2, z3, i, x, y);
            }
        } else {
            // post-check program
            // assume((postflag == 0));
            postcount++;
            // fprintf(fptr, "Post\n");

            // post-condition
            if ((i >= x)) {
                if ((0 > i)) {
                    postcheck(((i >= y)), z1, z2, z3, i, x, y)
                }
            }
        }
    }

    // Print the counters if no flags are hit
    if (preflag + loopflag + postflag == 0 && counter == 100) {
        printf("%s : %lld, %s : %lld, %s : %lld\n", "precount", precount, "loopcount", loopcount,
               "postcount", postcount);
        counter = 0;
    }

    // Regular Close FILE
    return 0;
}
