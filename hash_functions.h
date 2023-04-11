#pragma once

int assert_hash_arg(const char* key, int size);

unsigned char my_rotl(unsigned char num, unsigned char count);

unsigned char my_rotr(unsigned char num, unsigned char count);

int hash_const(const char* key, int size);

int hash_first(const char* key, int size);

int hash_len(const char* key, int size);

int hash_sum(const char* key, int size);