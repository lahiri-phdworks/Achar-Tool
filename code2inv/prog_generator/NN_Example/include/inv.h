#define INPLACE 1
#define PHI                                                          \
    ((index <= n) &&                                                 \
     ((sum >= ((5 * ((index / 10) - 1) * (index / 10)) +             \
               ((index / 10) * (index - 10 * (index / 10))) - 9)) && \
      (sum <= ((5 * ((index / 10) - 1) * (index / 10)) +             \
               ((index / 10) * (index - 10 * (index / 10))) + 9))))  // generated by code2inv