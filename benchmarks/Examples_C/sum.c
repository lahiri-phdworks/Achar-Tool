#include <assert.h>
#include <stdlib.h>
#define assume(cond) \
    if (!(cond)) exit(0);
// Sum of Squares Example.
long long int foo(long long int sum, long long int i) {
    long long int product = 0;
    __asm__ __volatile__("imull %[d]\n" : [rtn] "=A"(product) : [a] "a"(i), [d] "rm"(i));
    return sum + product;
}

// foo() is opaque operation.
int main() {
    // variable declarations
    int i;
    int n;
    int sum;
    int foo_arg1_sum, foo_arg2_i;
    //  pre-conditions
    //  scanf("%d", &i);
    //  scanf("%d", &n);
    //  scanf("%d", &sum);
    assume((n >= 0));
    assume((i == 0));
    assume((sum == 0));
    // precheck
    // loopcond : (i < n)
    // loopstart
    while ((i < n)) {
        // loop body
        i = i + 1;
        sum = foo(sum, i);
        // For SMTLIB ->
        // sum = foo_arg1_sum + foo_arg2_i;
    }
    // loopend
    // postcheck
    // post-condition
    assert((sum == ((n * (n + 1) * (2 * n + 1)) / (6))));
}
