#include "my_hash.h"

int assert_hash_arg(const char* key, int size)
{
    assert(key);
    assert(size);

    return 1;
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