#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "config.h"
#include "math/MathFunctions.h"
#include "api/optional.h"

int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("%s Version %d.%d\n",
            argv[0],
            voice_im_VERSION_MAJOR,
            voice_im_VERSION_MINOR);

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
