#pragma once

#include <stdlib.h>

// generic AUTO macro
#define AUTO(type) \
    type*__attribute__((cleanup(auto_cleanup_##type)))

// specialized AUTO macros
#define AUTO_SIGNED_CHAR \
    signed char*__attribute__((cleanup(auto_cleanup_signed_char)))

void auto_cleanup_signed_char(signed char** ptr) { free(*ptr); }

#define AUTO_UNSIGNED_CHAR \
    unsigned char*__attribute__((cleanup(auto_cleanup_unsigned_char)))

void auto_cleanup_unsigned_char(unsigned char** ptr) { free(*ptr); }

#define AUTO_CHAR \
    char*__attribute__((cleanup(auto_cleanup_char)))

void auto_cleanup_char(char** ptr) { free(*ptr); }

#define AUTO_SHORT_INT \
    short int*__attribute__((cleanup(auto_cleanup_short_int)))

void auto_cleanup_short_int(short int** ptr) { free(*ptr); }

#define AUTO_UNSIGNED_SHORT_INT \
    unsigned short int*__attribute__((cleanup(auto_cleanup_unsigned_short_int)))

void auto_cleanup_unsigned_short_int(unsigned short int** ptr) { free(*ptr); }

#define AUTO_INT \
    int*__attribute__((cleanup(auto_cleanup_int)))

void auto_cleanup_int(int** ptr) { free(*ptr); }

#define AUTO_UNSIGNED_INT \
    unsigned int*__attribute__((cleanup(auto_cleanup_unsigned_int)))

void auto_cleanup_unsigned_int(unsigned int** ptr) { free(*ptr); }

#define AUTO_LONG_INT \
    long int*__attribute__((cleanup(auto_cleanup_long_int)))

void auto_cleanup_long_int(long int** ptr) { free(*ptr); }

#define AUTO_UNSIGNED_LONG_INT \
    unsigned long int*__attribute__((cleanup(auto_cleanup_unsigned_long_int)))

void auto_cleanup_unsigned_long_int(unsigned long int** ptr) { free(*ptr); }

#define AUTO_LONG_LONG_INT \
    long long int*__attribute__((cleanup(auto_cleanup_long_long_int)))

void auto_cleanup_long_long_int(long long int** ptr) { free(*ptr); }

#define AUTO_UNSIGNED_LONG_LONG_INT \
    unsigned long long int* \
    __attribute__((cleanup(auto_cleanup_unsigned_long_long_int)))

void auto_cleanup_unsigned_long_long_int(unsigned long long int** ptr)
{ free(*ptr); }

#define AUTO_FLOAT \
    float*__attribute__((cleanup(auto_cleanup_float)))

void auto_cleanup_float(float** ptr) { free(*ptr); }

#define AUTO_DOUBLE \
    double*__attribute__((cleanup(auto_cleanup_double)))

void auto_cleanup_double(double** ptr) { free(*ptr); }

#define AUTO_LONG_DOUBLE \
    long double*__attribute__((cleanup(auto_cleanup_long_double)))

void auto_cleanup_long_double(long double** ptr) { free(*ptr); }
