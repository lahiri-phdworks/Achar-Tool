int main() {
    // variable declarations
    int n;
    int v1;
    int v2;
    int v3;
    int x;
    // pre-conditions
    // scanf("%d", &x);
    // scanf("%d", &n);
    (x = n);
    // precheck
    // loopcond : (x > 0)
    // loopstart
    while ((x > 0)) {
        // loop body
        // (x = (x - 1));
        assume((1 == 2));
    }
    // loopend
    // postcheck
    // post-condition
    if ((n >= 0)) {
        assert((x == 0));
    }
}