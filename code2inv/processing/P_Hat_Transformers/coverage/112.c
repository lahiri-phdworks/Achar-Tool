
/*
 * P-Hat Transformation
 * Coverage
 * for 112.c file
 */

#include <112.h>
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

#define INV(i, n, sn, v1, v2, v3) PHI

long long unsigned int counter = 0;
int preflag = 0, loopflag = 0, postflag = 0;
long long unsigned int precount = 0, loopcount = 0, postcount = 0;

// COMMENT : Precheck function
void precheck(FILE* fptr, char* modelFileBuffer, long long int i, long long int n, long long int sn,
              long long int v1, long long int v2, long long int v3) {
    int f = preflag;
    setflag(INV(i, n, sn, v1, v2, v3), preflag);
    if (f == 0 && preflag == 1) {
        fprintf(fptr, "Pre : %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld\n",
                "i", i, "n", n, "sn", sn, "v1", v1, "v2", v2, "v3", v3);

        assert(0);
    }
}

// COMMENT : Loopcheck function
void loopcheck(FILE* fptr, char* modelFileBuffer, long long int temp_i, long long int temp_n,
               long long int temp_sn, long long int temp_v1, long long int temp_v2,
               long long int temp_v3, long long int i, long long int n, long long int sn,
               long long int v1, long long int v2, long long int v3) {
    int f = loopflag;
    setflag(INV(i, n, sn, v1, v2, v3), loopflag);
    if (f == 0 && loopflag == 1) {
        fprintf(
            fptr, "LoopStart : %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld\n",
            "i", temp_i, "n", temp_n, "sn", temp_sn, "v1", temp_v1, "v2", temp_v2, "v3", temp_v3);
        fprintf(fptr,
                "LoopEnd : %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld\n", "i",
                i, "n", n, "sn", sn, "v1", v1, "v2", v2, "v3", v3);

        assert(0);
    }
}

// COMMENT : Postcheck Macro
#define postcheck(fptr, modelFileBuffer, cond, i, n, sn, v1, v2, v3) \
    \ 
{                                                               \
        \ 
    int f = postflag;                                                \
        \ 
   setflag(cond, postflag);                                          \
        \ 
    if (f == 0 && postflag == 1) {                                   \
            \ 
        fprintf(fptr, "Post : %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld\n", \ 
 "i",                                                                \
                i, "n", n, "sn", sn, "v1", v1, "v2", v2, "v3", v3);  \
            assert(0);                                               \
        \ 
}                                                           \
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
    long long int n = atoi(argv[2]);
    long long int sn = atoi(argv[3]);
    long long int v1 = atoi(argv[4]);
    long long int v2 = atoi(argv[5]);
    long long int v3 = atoi(argv[6]);
    long long int choices = atoi(argv[7]);

    char vars[128];
    memset(vars, '\0', sizeof(vars));
    snprintf(vars, 128, "%s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld, %s : %lld\n", "i",
             i, "n", n, "sn", sn, "v1", v1, "v2", v2, "v3", v3);

    // Translate()
    if (choices > 10000) {
        prebody_f1(choices, i, n, sn, v1, v2, v3);

        precount++;
        // fprintf(fptr, "Pre\n");
        // precheck
        precheck(fptr, vars, i, n, sn, v1, v2, v3);
    } else {
        // loop-check program
        assume((loopflag + postflag < 2));
        assume(INV(i, n, sn, v1, v2, v3));

        // Loop Condition
        if ((i <= n)) {
            // K-Bounded Exploration
            int unroll = UNROLL_LIMIT;
            while ((i <= n) && unroll--) {
                assume((loopflag == 0));
                long long int temp_i = i;
                long long int temp_n = n;
                long long int temp_sn = sn;
                long long int temp_v1 = v1;
                long long int temp_v2 = v2;
                long long int temp_v3 = v3;

                loopbody_f2(choices, i, n, sn, v1, v2, v3);

                loopcount++;
                loopcheck(fptr, vars, temp_i, temp_n, temp_sn, temp_v1, temp_v2, temp_v3, i, n, sn,
                          v1, v2, v3);
            }
        } else {
            // post-check program
            assume((postflag == 0));
            postcount++;
            // fprintf(fptr, "Post\n");

            // post-condition
            if ((sn != n)) {
                postcheck(fptr, vars, ((sn == 0)), i, n, sn, v1, v2, v3)
            }
        }
    }

    // Regular Close FILE
    fclose(fptr);
    return 0;
}
