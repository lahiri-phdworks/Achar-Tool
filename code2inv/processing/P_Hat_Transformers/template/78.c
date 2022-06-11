
/*
 * P-Hat Transformation
 * for 78.c file
 */

#include <78.h>
#include <assert.h>
#include <inttypes.h>
#include <libhfuzz/libhfuzz.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>

#define UNROLL_LIMIT 64

#define setflag(cond, flag) \
    if (!(cond)) flag = 1;

#define assume(cond) \
    if (!(cond)) continue;

#define INV(i, x, y) PHI

long long unsigned int counter = 0;
int preflag = 0, loopflag = 0, postflag = 0;
long long unsigned int precount = 0, loopcount = 0, postcount = 0;

// COMMENT : Precheck function
void precheck(FILE* fptr, char* modelFileBuffer, long long int i, long long int x,
              long long int y) {
    int f = preflag;
    setflag(INV(i, x, y), preflag);
    if (f == 0 && preflag == 1) {
        fprintf(fptr, "Pre : %s : %lld, %s : %lld, %s : %lld\n", "i", i, "x", x, "y", y);

        assert(0);
    }
}

// COMMENT : Loopcheck function
void loopcheck(FILE* fptr, char* modelFileBuffer, long long int temp_i, long long int temp_x,
               long long int temp_y, long long int i, long long int x, long long int y) {
    int f = loopflag;
    setflag(INV(i, x, y), loopflag);
    if (f == 0 && loopflag == 1) {
        fprintf(fptr, "LoopStart : %s : %lld, %s : %lld, %s : %lld\n", "i", temp_i, "x", temp_x,
                "y", temp_y);
        fprintf(fptr, "LoopEnd : %s : %lld, %s : %lld, %s : %lld\n", "i", i, "x", x, "y", y);

        assert(0);
    }
}

// COMMENT : Postcheck Macro
#define postcheck(fptr, modelFileBuffer, cond, i, x, y) \
    \ 
{                                                  \
        \ 
    int f = postflag;                                   \
        \ 
   setflag(cond, postflag);                             \
        \ 
    if (f == 0 && postflag == 1) {                      \
            \ 
        fprintf(fptr, "Post : %s : %lld, %s : %lld, %s : %lld\n", \ 
 "i",                                                   \
                i, "x", x, "y", y);                     \
            assert(0);                                  \
        \ 
}                                              \
    }

int main(int argc, char** argv) {
// variable declarations
#ifndef READ_FROM_FLAG

    long long int i;
    long long int x;
    long long int y;
#endif

    // variable declarations

    // Buffered File stream.
    char modelFileBuffer[2048];
    memset(modelFileBuffer, '\0', sizeof(modelFileBuffer));
    FILE* fptr = fopen("models.txt", "w");
    setvbuf(fptr, modelFileBuffer, _IOLBF, 2048);

    FILE* inputs = fopen("inputs/inputs_78.txt", "a");
    setvbuf(inputs, modelFileBuffer, _IOLBF, 2048);

#ifdef READ_FROM_FLAG
    fprintf(fptr, "Checker : %s : %lld, %s : %lld, %s : %lld\n", "i", i, "x", x, "y", y);

    if (INV(i, x, y)) {
        fprintf(fptr, "True\n");
    } else {
        fprintf(fptr, "False\n");
    }
    assert(0);
#endif

    int reach_flag = 0;
    for (;;) {
        // Initialize HonggFuzz
        size_t len;
        const int16_t* honggBuf;
        HF_ITER(&honggBuf, &len);
        counter++;

        // Populate with Inputs
        long long int choices = honggBuf[10];

#ifndef READ_FROM_FLAG
        long long int i = honggBuf[0];
        long long int x = honggBuf[1];
        long long int y = honggBuf[2];
#endif

        char vars[128];
        memset(vars, '\0', sizeof(vars));
        snprintf(vars, 128, "%s : %lld, %s : %lld, %s : %lld\n", "i", i, "x", x, "y", y);

        fprintf(inputs, "%lld, %lld, %lld, %lld\n", i, x, y, choices);

        // Translate()
        if (choices > 10000) {
            (i = 0);
            assume((x >= 0));
            assume((y >= 0));
            assume((x >= y));
            precount++;
            // fprintf(fptr, "Pre\n");
            // precheck
            precheck(fptr, vars, i, x, y);
        } else {
            // loop-check program
            assume((loopflag + postflag < 2));
            assume(INV(i, x, y));

            // Loop Condition
            if ((choices > 2500)) {
                // K-Bounded Exploration
                int unroll = UNROLL_LIMIT;
                while ((choices > 2500) && unroll--) {
                    assume((loopflag == 0));
                    long long int temp_i = i;
                    long long int temp_x = x;
                    long long int temp_y = y;

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
                    loopcheck(fptr, vars, temp_i, temp_x, temp_y, i, x, y);
                }
            } else {
                // post-check program
                assume((postflag == 0));
                postcount++;
                // fprintf(fptr, "Post\n");

                // post-condition
                if ((i < y)) {
                    postcheck(fptr, vars, ((0 <= i)), i, x, y)
                }
            }
        }

        // Print the counters if no flags are hit
        if (preflag + loopflag + postflag == 0 && counter == 100) {
            fprintf(fptr, "%s : %lld, %s : %lld, %s : %lld\n", "precount", precount, "loopcount",
                    loopcount, "postcount", postcount);
            counter = 0;
        }

        // Close FILE with assert(0);
        if (preflag + loopflag + postflag >= 3) {
            fclose(fptr);
            assert(0);
        }
    }

    // Regular Close FILE
    fclose(fptr);
    return 0;
}
