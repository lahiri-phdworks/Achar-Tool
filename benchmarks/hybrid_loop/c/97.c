int main() {
    // variable declarations
    int i;
    int j;
    int x;
    int y;
    // pre-conditions
    // scanf("%d", &i);
    // scanf("%d", &y);
    // scanf("%d", &j);
    // scanf("%d", &x);
    (j = 0);
    (i = 0);
    (y = 2);
    // precheck
    // loopcond : (i <= x)
    // loopstart
    while ((i <= x)) {
        // loop body
        {
            (i = (i + 1));
            // (j = (j + y));
            assume((1 == 2));
        }
    }
    // loopend
    // postcheck
    // post-condition
    if ((y == 1)) {
        assert((i == j));
    }
}