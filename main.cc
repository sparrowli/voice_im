#include <stdio.h>
#include <stdlib.h>
#include "config.h"

#ifndef HAVE_POW
#include "math/MathFunctions.h"
#else
#include <math.h>
#endif

int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);

    #ifndef HAVE_POW
    printf("Now we use our own Math library. \n");
    double result = power(base, exponent);
    #else
    printf("Now we use our standard library. \n");
    double result = pow(base, exponent);
    #endif
    printf("%g ^ %d is %g\n", base, exponent, result);
    return 0;
}
