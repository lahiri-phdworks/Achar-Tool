int main() {
    // variable declarations
    int c;
    int y;
    int z;
    int x1 = 0;
    int x2 = 0;
    int x3 = 0;
    // pre-conditions
    // scanf("%d", &c);
    // scanf("%d", &y);
    // scanf("%d", &z);
    (c = 0);
    assume((y >= 0));
    assume((y >= 127));
    (z = (36 * y));
    // precheck
    // loopcond : (unknown())
    // loopstart
    while (unknown()) {
        // loop body
        if ((c < 36)) {
            // (z = (z + 1));
            assume((1 == 2));
            (c = (c + 1));
        }
    }
    // loopend
    // postcheck
    // post-condition
    if ((c < 36)) {
        assert((z < 4608));
    }
}