#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("limits.h\n");

    printf("\tbits in byte: %d\n", CHAR_BIT);

    printf("CHAR:\n");
    printf("\tchar size in bytes: %zu\n", sizeof(char));
    printf("\tsigned char min: %d\n\tsigned char max: %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("\tunsigned char min: %d\n\tunsigned char max: %d\n", 0, UCHAR_MAX);

    printf("SHORT:\n");
    printf("\tshort int size in bytes: %zu\n", sizeof(short int));
    printf("\tsigned short int min: %d\n\tsigned short int max: %d\n", SHRT_MIN, SHRT_MAX);
    printf("\tunsigned short int min: %d\n\tunsigned short int max: %d\n", 0, USHRT_MAX);

    printf("INT:\n");
    printf("\tint size in bytes: %zu\n", sizeof(int));
    printf("\tsigned int min: %d\n\tsigned int max: %d\n", INT_MIN, INT_MAX);
    printf("\tunsigned int min: %d\n\tunsigned int max: %u\n", 0, UINT_MAX);

    printf("LONG:\n");
    printf("\tlong int size in bytes: %zu\n", sizeof(long int));
    printf("\tsigned long int min: %ld\n\tsigned long int max: %ld\n", LONG_MIN,  LONG_MAX);
    printf("\tunsigned long int min: %d\n\tunsigned long int max: %lu\n", 0, ULONG_MAX);

    printf("LONG LONG:\n");
    printf("\tlong long int size in bytes: %zu\n", sizeof(long long int));
    printf("\tsigned long long int min: %lld\n\tsigned long long int  max: %lld\n", LLONG_MIN, LLONG_MAX);
    printf("\tunsigned long long int min: %d\n\tunsigned long long int max: %llu\n", 0, ULLONG_MAX);

    
    printf("\n\nfloat.h\n");

    printf("\nFLOAT:\n");
    printf("\tfloat size in bytes: %zu\n", sizeof(float));
    printf("\tfloat precision (decimal digits): %d\n", FLT_DIG);
    printf("\tfloat min normalized value: %e\n", FLT_MIN);
    printf("\tfloat max value: %e\n", FLT_MAX);
    printf("\tfloat min subnormal value: %e\n\n", FLT_TRUE_MIN);

    printf("DOUBLE:\n");
    printf("\tdouble size in bytes: %zu\n", sizeof(double));
    printf("\tdouble precision (decimal digits): %d\n", DBL_DIG);
    printf("\tdouble min normalized value: %e\n", DBL_MIN);
    printf("\tdouble max value: %e\n", DBL_MAX);
    printf("\tdouble min subnormal value: %e\n\n", DBL_TRUE_MIN);

    printf("LONG DOUBLE:\n");
    printf("\tlong double size in bytes: %zu\n", sizeof(long double));
    printf("\tlong double precision (decimal digits): %d\n", LDBL_DIG);
    printf("\tlong double min normalized value: %Le\n", LDBL_MIN);
    printf("\tlong double max value: %Le\n", LDBL_MAX);
    printf("\tlong double min subnormal value: %Le\n", LDBL_TRUE_MIN);

    return 0;
}
