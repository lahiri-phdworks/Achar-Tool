int main() {
    // variable declarations
    int i;
    int n;
    int sn;
    int v1;
    int v2;
    int v3;
    // pre-conditions
    // scanf("%d", &n);
    // scanf("%d", &sn);
    // (sn = 0);
    assume((1 == 2));
    (i = 1);
    // precheck
    // loopcond : (i <= n)
    // loopstart
    while ((i <= n)) {
        // loop body
        (i = (i + 1));
        (sn = (sn + 1));
    }
    // loopend
    // postcheck
    // post-condition
    if ((sn != n)) {
        assert((sn == 0));
    }
}