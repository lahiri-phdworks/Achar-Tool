
/*
 * P-Hat Transformation
 * Coverage
 * for 119.c file
 */

#include <119.h>
#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>

#include <cstring>

extern void prebody_f1(long long int, long long int&, long long int&, long long int&);

extern void loopbody_f2(long long int, long long int&, long long int&, long long int&);

#define UNROLL_LIMIT 64

#define setflag(cond, flag) \
    if (!(cond)) flag = 1;

#define assume(cond) \
    if (!(cond)) exit(0);

#define INV(i, size, sn) PHI

long long unsigned int counter = 0;
int preflag = 0, loopflag = 0, postflag = 0;
long long unsigned int precount = 0, loopcount = 0, postcount = 0;

// COMMENT : Precheck function
void precheck(FILE* fptr, char* modelFileBuffer, long long int i, long long int size,
              long long int sn) {
    int f = preflag;
    setflag(INV(i, size, sn), preflag);
    if (f == 0 && preflag == 1) {
        fprintf(fptr, "Pre : %s : %lld, %s : %lld, %s : %lld\n", "i", i, "size", size, "sn", sn);

        assert(0);
    }
}

// COMMENT : Loopcheck function
void loopcheck(FILE* fptr, char* modelFileBuffer, long long int temp_i, long long int temp_size,
               long long int temp_sn, long long int i, long long int size, long long int sn) {
    int f = loopflag;
    setflag(INV(i, size, sn), loopflag);
    if (f == 0 && loopflag == 1) {
        fprintf(fptr, "LoopStart : %s : %lld, %s : %lld, %s : %lld\n", "i", temp_i, "size",
                temp_size, "sn", temp_sn);
        fprintf(fptr, "LoopEnd : %s : %lld, %s : %lld, %s : %lld\n", "i", i, "size", size, "sn",
                sn);

        assert(0);
    }
}

// COMMENT : Postcheck Macro
#define postcheck(fptr, modelFileBuffer, cond, i, size, sn) \
    \ 
{                                                      \
        \ 
    int f = postflag;                                       \
        \ 
   setflag(cond, postflag);                                 \
        \ 
    if (f == 0 && postflag == 1) {                          \
            \ 
        fprintf(fptr, "Post : %s : %lld, %s : %lld, %s : %lld\n", \ 
 "i",                                                       \
                i, "size", size, "sn", sn);                 \
            assert(0);                                      \
        \ 
}                                                  \
    }

int main(int argc, char** argv) {
    // variable declarations

    // Buffered File stream.
    char modelFileBuffer[2048];
    memset(modelFileBuffer, '\0', sizeof(modelFileBuffer));
    FILE* fptr = fopen("models.txt", "w");
    setvbuf(fptr, modelFileBuffer, _IOLBF, 2048);

    // variable declarations
    long long int i = atoi(argv[1]);
    long long int size = atoi(argv[2]);
    long long int sn = atoi(argv[3]);
    long long int choices = atoi(argv[4]);

    char vars[128];
    memset(vars, '\0', sizeof(vars));
    snprintf(vars, 128, "%s : %lld, %s : %lld, %s : %lld\n", "i", i, "size", size, "sn", sn);

    // Translate()
    if (choices > 10000) {
        prebody_f1(choices, i, size, sn);

        precount++;
        // fprintf(fptr, "Pre\n");
        // precheck
        precheck(fptr, vars, i, size, sn);
    } else {
        // loop-check program
        assume((loopflag + postflag < 2));
        assume(INV(i, size, sn));

        // Loop Condition
        if ((i <= size)) {
            // K-Bounded Exploration
            int unroll = UNROLL_LIMIT;
            while ((i <= size) && unroll--) {
                assume((loopflag == 0));
                long long int temp_i = i;
                long long int temp_size = size;
                long long int temp_sn = sn;

                loopbody_f2(choices, i, size, sn);

                loopcount++;
                loopcheck(fptr, vars, temp_i, temp_size, temp_sn, i, size, sn);
            }
        } else {
            // post-check program
            assume((postflag == 0));
            postcount++;
            // fprintf(fptr, "Post\n");

            // post-condition
            if ((sn != 0)) {
                postcheck(fptr, vars, ((sn == size)), i, size, sn)
            }
        }
    }

    // Regular Close FILE
    fclose(fptr);
    return 0;
}
