int main() {
    // variable declarations
    int x;
    int size;
    int y;
    int z;
    // pre-conditions
    // scanf("%d", &size);
    // scanf("%d", &x);
    // scanf("%d", &y);
    // scanf("%d", &z);
    (x = 0);
    // precheck
    // loopcond : (x < size)
    // loopstart
    while (x < size) {
        // loop body
        x += 1;
        if (z <= y) {
            y = z;
        }
    }
    // loopend
    // postcheck
    // post-condition
    if (size > 0) {
        assert(z >= y);
    }
}