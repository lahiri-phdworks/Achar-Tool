
/*
 * P-Hat Transformation
 * Coverage
 * for 86.c file
 */

#include <86.h>
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
                       long long int&, long long int&);

extern void loopbody_f2(long long int, long long int&, long long int&, long long int&,
                        long long int&, long long int&);

#define UNROLL_LIMIT 64

#define setflag(cond, flag) \
    if (!(cond)) flag = 1;

#define assume(cond) \
    if (!(cond)) exit(0);

#define INV(x, y, z1, z2, z3) PHI

long long unsigned int counter = 0;
int preflag = 0, loopflag = 0, postflag = 0;
long long unsigned int precount = 0, loopcount = 0, postcount = 0;

// COMMENT : Precheck function
void precheck(FILE* fptr, char* modelFileBuffer, long long int x, long long int y, long long int z1,
              long long int z2, long long int z3) {
    int f = preflag;
    setflag(INV(x, y, z1, z2, z3), preflag);
    if (f == 0 && preflag == 1) {
        fprintf(fptr, "Pre : %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld\n", "x", x, "y",
                y, "z1", z1, "z2", z2, "z3", z3);

        assert(0);
    }
}

// COMMENT : Loopcheck function
void loopcheck(FILE* fptr, char* modelFileBuffer, long long int temp_x, long long int temp_y,
               long long int temp_z1, long long int temp_z2, long long int temp_z3, long long int x,
               long long int y, long long int z1, long long int z2, long long int z3) {
    int f = loopflag;
    setflag(INV(x, y, z1, z2, z3), loopflag);
    if (f == 0 && loopflag == 1) {
        fprintf(fptr, "LoopStart : %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld\n", "x",
                temp_x, "y", temp_y, "z1", temp_z1, "z2", temp_z2, "z3", temp_z3);
        fprintf(fptr, "LoopEnd : %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld\n", "x", x,
                "y", y, "z1", z1, "z2", z2, "z3", z3);

        assert(0);
    }
}

// COMMENT : Postcheck Macro
#define postcheck(fptr, modelFileBuffer, cond, x, y, z1, z2, z3) \
    \ 
{                                                           \
        \ 
    int f = postflag;                                            \
        \ 
   setflag(cond, postflag);                                      \
        \ 
    if (f == 0 && postflag == 1) {                               \
            \ 
        fprintf(fptr, "Post : %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld\n", \ 
 "x",                                                            \
                x, "y", y, "z1", z1, "z2", z2, "z3", z3);        \
            assert(0);                                           \
        \ 
}                                                       \
    }

int main(int argc, char** argv) {
    // variable declarations

    // Buffered File stream.
    char modelFileBuffer[2048];
    memset(modelFileBuffer, '\0', sizeof(modelFileBuffer));
    FILE* fptr = fopen("models.txt", "w");
    setvbuf(fptr, modelFileBuffer, _IOLBF, 2048);

    // variable declarations
    long long int x = atoi(argv[1]);
    long long int y = atoi(argv[2]);
    long long int z1 = atoi(argv[3]);
    long long int z2 = atoi(argv[4]);
    long long int z3 = atoi(argv[5]);
    long long int choices = atoi(argv[6]);

    char vars[128];
    memset(vars, '\0', sizeof(vars));
    snprintf(vars, 128, "%s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld\n", "x", x, "y", y,
             "z1", z1, "z2", z2, "z3", z3);

    // Translate()
    if (choices > 10000) {
        prebody_f1(choices, x, y, z1, z2, z3);

        precount++;
        // fprintf(fptr, "Pre\n");
        // precheck
        precheck(fptr, vars, x, y, z1, z2, z3);
    } else {
        // loop-check program
        assume((loopflag + postflag < 2));
        assume(INV(x, y, z1, z2, z3));

        // Loop Condition
        if ((x < 0)) {
            // K-Bounded Exploration
            int unroll = UNROLL_LIMIT;
            while ((x < 0) && unroll--) {
                assume((loopflag == 0));
                long long int temp_x = x;
                long long int temp_y = y;
                long long int temp_z1 = z1;
                long long int temp_z2 = z2;
                long long int temp_z3 = z3;

                loopbody_f2(choices, x, y, z1, z2, z3);

                loopcount++;
                loopcheck(fptr, vars, temp_x, temp_y, temp_z1, temp_z2, temp_z3, x, y, z1, z2, z3);
            }
        } else {
            // post-check program
            assume((postflag == 0));
            postcount++;
            // fprintf(fptr, "Post\n");

            // post-condition
            postcheck(fptr, vars, ((y > 0)), x, y, z1, z2, z3)
        }
    }

    // Regular Close FILE
    fclose(fptr);
    return 0;
}
