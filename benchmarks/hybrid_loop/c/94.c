int main() {
    // variable declarations
    int i;
    int j;
    int k;
    int n;
    // pre-conditions
    // scanf("%d", &k);
    // scanf("%d", &n);
    // scanf("%d", &i);
    // scanf("%d", &j);
    (i = 0);
    (j = 0);
    // precheck
    // loopcond : (i <= n)
    // loopstart
    while ((i <= n)) {
        // loop body
        {
            (i = (i + 1));
            // (j = (j + i));
            assume((1 == 2));
        }
    }
    // loopend
    // postcheck
    // post-condition
    assert(((i + (j + k)) > (2 * n)));
}