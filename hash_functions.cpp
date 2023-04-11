#include "my_hash.h"

const unsigned int bits_8 = 8;

int assert_hash_arg(const char* key, int size)
{
    assert(key);
    assert(size);

    return 1;
}

unsigned char my_rotl(unsigned char num, unsigned char count)
{
    unsigned int r = count % bits_8;

    return (num << r) | (num >> (bits_8 - r));
}

unsigned char my_rotr(unsigned char num, unsigned char count)
{
    unsigned int r = count % bits_8;

    return (num >> r) | (num << (bits_8 - r));
}

int hash_const(const char* key, int size)
{
    assert_hash_arg(key, size);

    return 1;
}

int hash_first(const char* key, int size)
{
    assert_hash_arg(key, size);

    return *key % size;
}

int hash_len(const char* key, int size)
{
    assert_hash_arg(key, size);

    return strlen(key) % size;
}

int hash_sum(const char* key, int size)
{
    assert_hash_arg(key, size);

    int sum = 0;

    while(*key)
    {
        sum += *key;

        key++;
    }

    return sum % size;
}