#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int32_t input;
    int base;
    const char* expected;
} TestCase;

char toHexDigit(int n) {
    if (n < 10)
        return '0' + n;
    else
        return 'A' + (n - 10);
}
    char * itoa(int number,int base){//doesent work with freeze, allocates a lot of space more to handle lower bases using more digits
    //Buffer allocation
    int is_negative = 0; //I need to handle the partial 
    int digits_number = 34;
    char *buf = malloc(digits_number);
    int digits;
    int i = digits_number -1 ;
    if (number == INT_MIN){
        if (base == 2)
            strcpy(buf,"-10000000000000000000000000000000");
        if (base == 8)
            strcpy(buf,"-20000000000");
        if (base == 10)
            strcpy(buf, "-2147483648");//I discovered the existence of this by asking chat gpt questions
        if(base==16)
            strcpy(buf,"-80000000");

        return buf;                  
    }
    buf[i--] = '\0';

    if (number < 0){
        is_negative = 1;
        number = -number;//Today I learnt complement 2 notation
    }
    if (number == 0) {
        buf[i] = '0';
        return buf + i;//I dont do a + 1 because I'm not decrementing i here
    }
    while (number > 0){
        digits = number % base;
        number = number / base;
        if (base == 16){
            buf[i--] = toHexDigit(digits);
        }
        else
            buf[i--] = '0' + digits;
    }
    if (is_negative){
        buf[i--] = '-';
    }

  return buf + i + 1;

}
int main(){
   


    TestCase tests[] = {
        // Decimal
        {0, 10, "0"},
        {123, 10, "123"},
        {-456, 10, "-456"},
        {INT_MAX, 10, "2147483647"},
        {INT_MIN, 10, "-2147483648"},

        // Hexadecimal
        {0, 16, "0"},
        {255, 16, "FF"},
        {-255, 16, "-FF"},
        {INT_MAX, 16, "7FFFFFFF"},
        {INT_MIN, 16, "-80000000"},

        // Octal
        {0, 8, "0"},
        {64, 8, "100"},
        {-64, 8, "-100"},
        {INT_MAX, 8, "17777777777"},
        {INT_MIN, 8, "-20000000000"},

        // Binary
        {0, 2, "0"},
        {5, 2, "101"},
        {-5, 2, "-101"},
        {INT_MAX, 2, "1111111111111111111111111111111"},
        {INT_MIN, 2, "-10000000000000000000000000000000"},
    };
    int n_tests = sizeof(tests)/sizeof(TestCase);
    int failures = 0;

    for(int i=0; i<n_tests; i++) {
        char* result = itoa(tests[i].input, tests[i].base);

        if(strcmp(result, tests[i].expected) != 0) {
            printf("Test %d FAILED: input=%d, base=%d, got='%s', expected='%s'\n",
                   i, tests[i].input, tests[i].base, result, tests[i].expected);
            failures++;
        } else {
            printf("Test %d PASSED: input=%d, base=%d -> '%s'\n",
                   i, tests[i].input, tests[i].base, result);
        }
    }

    if(failures == 0)
        printf("All tests passed!\n");
    else
        printf("%d test(s) failed.\n", failures);
   

}  