#include "my_hash.h"

void hash_ctor(hash_table* table, int size, int (*hash)(const char* key, int size))
{
    table->size = size;
    table->hash = hash;
    table->data = (hash_node**) calloc(size, sizeof(hash_node));

    assert_table(table);

    return;
}

int assert_table(hash_table* table)
{
    assert(table);
    assert(table->size);
    assert(table->data);
    assert(table->hash);

    return 1;
}

void hash_insert(hash_table* table, const char* key)
{
    assert_table(table);
    assert(key);

    int hash = table->hash(key, table->size);

    hash_node* new_node = (hash_node*) calloc(1, sizeof(hash_node));
    assert(new_node);

    new_node->next = NULL;
    new_node->key = key;

    if(!(table->data[hash]))
    {
        table->data[hash] = new_node;
    }
    else
    {
        hash_node* curr = table->data[hash];
        hash_node* next = (table->data[hash])->next;

        while(next)
        {
            curr = curr->next;
            next = curr->next;
        }

        curr->next = new_node;
    }

   return;
}

int hash_find(hash_table* table, const char* key)
{
    assert_table(table);
    assert(key);

    int hash = table->hash(key, table->size);

    hash_node* next =  table->data[hash];

    while(!strcmp(next->key, key))
    {
        if(!(next->next))
        {
            printf("Not found\n");
            return 0;
        }
        else
        {
            next = next->next;
        }
    }

    return 1;
}

void hash_dtor(hash_table* table)
{
    assert_table(table);

    for(int i = 0; i < table->size; i++)
    {
        if(table->data[i])
        {
            hash_node* curr = table->data[i];
            hash_node* next = NULL;

            while(curr)
            {
                next = curr->next;
                free(curr);
                curr = next;
            }
        }
    }

    free(table->data);

    return;
}
