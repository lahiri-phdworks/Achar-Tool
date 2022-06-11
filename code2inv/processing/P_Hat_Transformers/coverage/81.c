
/*
 * P-Hat Transformation
 * Coverage
 * for 81.c file
 */

#include <81.h>
#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>

#include <cstring>

extern void prebody_f1(long long int, long long int&, long long int&, long long int&,
                       long long int&, long long int&, long long int&);

extern void loopbody_f2(long long int, long long int&, long long int&, long long int&,
                        long long int&, long long int&, long long int&);

#define UNROLL_LIMIT 64

#define setflag(cond, flag) \
    if (!(cond)) flag = 1;

#define assume(cond) \
    if (!(cond)) exit(0);

#define INV(z1, z2, z3, i, x, y) PHI

long long unsigned int counter = 0;
int preflag = 0, loopflag = 0, postflag = 0;
long long unsigned int precount = 0, loopcount = 0, postcount = 0;

// COMMENT : Precheck function
void precheck(FILE* fptr, char* modelFileBuffer, long long int z1, long long int z2,
              long long int z3, long long int i, long long int x, long long int y) {
    int f = preflag;
    setflag(INV(z1, z2, z3, i, x, y), preflag);
    if (f == 0 && preflag == 1) {
        fprintf(fptr, "Pre : %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld\n",
                "z1", z1, "z2", z2, "z3", z3, "i", i, "x", x, "y", y);

        assert(0);
    }
}

// COMMENT : Loopcheck function
void loopcheck(FILE* fptr, char* modelFileBuffer, long long int temp_z1, long long int temp_z2,
               long long int temp_z3, long long int temp_i, long long int temp_x,
               long long int temp_y, long long int z1, long long int z2, long long int z3,
               long long int i, long long int x, long long int y) {
    int f = loopflag;
    setflag(INV(z1, z2, z3, i, x, y), loopflag);
    if (f == 0 && loopflag == 1) {
        fprintf(fptr,
                "LoopStart : %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld\n",
                "z1", temp_z1, "z2", temp_z2, "z3", temp_z3, "i", temp_i, "x", temp_x, "y", temp_y);
        fprintf(fptr,
                "LoopEnd : %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld\n",
                "z1", z1, "z2", z2, "z3", z3, "i", i, "x", x, "y", y);

        assert(0);
    }
}

// COMMENT : Postcheck Macro
#define postcheck(fptr, modelFileBuffer, cond, z1, z2, z3, i, x, y) \
    \ 
{                                                              \
        \ 
    int f = postflag;                                               \
        \ 
   setflag(cond, postflag);                                         \
        \ 
    if (f == 0 && postflag == 1) {                                  \
            \ 
        fprintf(fptr, "Post : %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld\n", \ 
 "z1",                                                              \
                z1, "z2", z2, "z3", z3, "i", i, "x", x, "y", y);    \
            assert(0);                                              \
        \ 
}                                                          \
    }

int main(int argc, char** argv) {
    // variable declarations

    // Buffered File stream.
    char modelFileBuffer[2048];
    memset(modelFileBuffer, '\0', sizeof(modelFileBuffer));
    FILE* fptr = fopen("models.txt", "w");
    setvbuf(fptr, modelFileBuffer, _IOLBF, 2048);

    // variable declarations
    long long int z1 = atoi(argv[1]);
    long long int z2 = atoi(argv[2]);
    long long int z3 = atoi(argv[3]);
    long long int i = atoi(argv[4]);
    long long int x = atoi(argv[5]);
    long long int y = atoi(argv[6]);
    long long int choices = atoi(argv[7]);

    char vars[128];
    memset(vars, '\0', sizeof(vars));
    snprintf(vars, 128, "%s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld\n", "z1",
             z1, "z2", z2, "z3", z3, "i", i, "x", x, "y", y);

    // Translate()
    if (choices > 10000) {
        prebody_f1(choices, z1, z2, z3, i, x, y);

        precount++;
        // fprintf(fptr, "Pre\n");
        // precheck
        precheck(fptr, vars, z1, z2, z3, i, x, y);
    } else {
        // loop-check program
        assume((loopflag + postflag < 2));
        assume(INV(z1, z2, z3, i, x, y));

        // Loop Condition
        if ((choices > 2500)) {
            // K-Bounded Exploration
            int unroll = UNROLL_LIMIT;
            while ((choices > 2500) && unroll--) {
                assume((loopflag == 0));
                long long int temp_z1 = z1;
                long long int temp_z2 = z2;
                long long int temp_z3 = z3;
                long long int temp_i = i;
                long long int temp_x = x;
                long long int temp_y = y;

                loopbody_f2(choices, z1, z2, z3, i, x, y);

                loopcount++;
                loopcheck(fptr, vars, temp_z1, temp_z2, temp_z3, temp_i, temp_x, temp_y, z1, z2, z3,
                          i, x, y);
            }
        } else {
            // post-check program
            assume((postflag == 0));
            postcount++;
            // fprintf(fptr, "Post\n");

            // post-condition
            if ((i < y)) {
                postcheck(fptr, vars, ((0 <= i)), z1, z2, z3, i, x, y)
            }
        }
    }

    // Regular Close FILE
    fclose(fptr);
    return 0;
}
