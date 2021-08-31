#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

    //declares integer, float and double variables,
    //and assign maximum values

    int intgr = INT_MAX;
    float flt = FLT_MAX;
    double dbl = DBL_MAX;

    //Print sizes and values of each variable
    printf("maximum value of int: %d  size of int: %lu\n", intgr, sizeof(intgr));
    printf("maximum value of float: %f  size of float: %lu\n", flt, sizeof(flt));
    printf("maximum value of double: %lf  size of double: %lu\n", dbl, sizeof(dbl));

    return 0;
}
