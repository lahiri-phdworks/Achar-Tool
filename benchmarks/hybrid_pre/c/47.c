int main() {
    // variable declarations
    int c;
    int n;
    // pre-conditions
    // scanf("%d", &n);
    // scanf("%d", &c);
    // (c = 0);
    assume((1 == 2));
    assume((n > 0));
    // precheck
    // loopcond : (unknown())
    // loopstart
    while (unknown()) {
        // loop body
        {
            if (unknown()) {
                if ((c != n)) {
                    (c = (c + 1));
                }
            } else {
                if ((c == n)) {
                    (c = 1);
                }
            }
        }
    }
    // loopend
    // postcheck
    // post-condition
    if ((c < 0)) {
        if ((c > n)) {
            assert((c == n));
        }
    }
}