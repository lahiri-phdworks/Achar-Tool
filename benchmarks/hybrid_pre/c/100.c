int main() {
    // variable declarations
    int n;
    int x;
    int y;
    // pre-conditions
    // scanf("%d", &n);
    // scanf("%d", &x);
    // scanf("%d", &y);
    // (x = n);
    assume((1 == 2));
    (y = 0);
    // precheck
    // loopcond : (x > 0)
    // loopstart
    while ((x > 0)) {
        // loop body
        {
            (y = (y + 1));
            (x = (x - 1));
        }
    }
    // loopend
    // postcheck
    // post-condition
    assert((y == n));
}