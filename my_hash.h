#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "hash_functions.h"

const int TABLE_SIZE = 20;

typedef struct _hash_node
{
    const char* key;
    struct _hash_node* next;
} hash_node;

typedef struct 
{
    hash_node** data;
    int size;
    int (*hash)(const char* key, int size);
} hash_table;

void hash_ctor(hash_table* table, int size, int (*hash)(const char* key, int size));

int assert_table(hash_table* table);

void hash_insert(hash_table* table, const char* key);

int hash_find(hash_table* table, const char* key);

void hash_dtor(hash_table* table);

int hash_count(hash_table* table, int index);

void do_tests(int n_lines, const char** words, const char* output_filename);

void test_hash(int (*hash)(const char* key, int size), const char* name, int n_lines, const char** words, FILE* output);
