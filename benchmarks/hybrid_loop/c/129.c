int main() {
    // variable declarations
    int x;
    int y;
    int z1;
    int z2;
    int z3;
    // pre-conditions
    // scanf("%d", &y);
    // scanf("%d", &x);
    (x = 1);
    // precheck
    // loopcond : (x < y)
    // loopstart
    while ((x < y)) {
        // loop body
        {
            // (x = (x + x));
            assume((1 == 2));
        }
    }
    // loopend
    // postcheck
    // post-condition
    assert((x >= 1));
}