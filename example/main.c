#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/auto.h"

typedef struct 
{
    int a;
    float b;
}
custom_t;

typedef custom_t* custom_h;

void auto_cleanup_custom_t(custom_h* handle)
{
    free(*handle);
    *handle = NULL;
}

void fill_custom(custom_h handle)
{
    handle->a = 42;
    handle->b = 3.14f;
}

void print_custom(custom_h handle)
{
    printf("%d, %f\n", handle->a, handle->b);
}

void custom_type_test(void)
{
    AUTO(custom_t) handle = malloc(sizeof(custom_t));

    fill_custom(handle);

    print_custom(handle);
}

void string_test(void)
{
    size_t const size = 50;
    AUTO_CHAR str = malloc(size);

    strncpy(str, "hello, world", size);

    printf("str: %s\n", str);
}

void array_test(void)
{
    size_t const size = 50;
    AUTO_UNSIGNED_INT array = malloc(size * sizeof(unsigned int));

    for (size_t i = 0; i < size; ++i)
        array[i] = (unsigned int)i;

    for (size_t i = 0; i < size; ++i)
        printf("%u ", array[i]);
    puts("");
}

void double_trouble(void)
{
    size_t const size = 50;
    AUTO_DOUBLE array = malloc(size * sizeof(double));

    {
        double item = 0;
        for (size_t i = 0; i < size; ++i, item += .1)
            array[i] = item;
    }

    for (size_t i = 0; i < size; ++i)
        printf("%lf ", array[i]);
    puts("");
}

int main(void)
{
    string_test();

    array_test();

    double_trouble();

    custom_type_test();

    return 0;
}
