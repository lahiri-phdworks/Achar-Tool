int main() {
    // variable declarations
    int x;
    int y;
    int n;
    int v1;
    int v2;
    int v3;
    // pre-conditions
    // scanf("%d", &x);
    // scanf("%d", &y);
    // scanf("%d", &n);
    (x = 1);
    // precheck
    // loopcond : (x <= n)
    // loopstart
    while (x <= n) {
        // loop body
        y = n - x;
        x = x + 1;
    }
    // loopend
    // postcheck
    // post-condition
    if (n > 0) {
        assert(y < n);
    }
}
