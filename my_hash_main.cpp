#include "my_hash.h"
#include "hash_functions.h"
#include "my_read.h"

const char* FILENAME = "shakespeare.txt";

int main()
{
    int lines_found = 0;
    char* text;
    char** strings = prepare_text(FILENAME, &lines_found, &text);

    for(int i = 0; i < lines_found; i++) 
    {
        char* t = strings[i];
        printf("%d. %s\n", i, t);
    }

    free(text);
    free(strings);

    // hash_table table;
    // hash_ctor(&table, TABLE_SIZE, &hash_rotr);

    // hash_insert(&table, "torch");
    // hash_insert(&table, "danetorcj");
    // hash_insert(&table, "zarembo");
    // hash_insert(&table, "moshkov");
    // hash_insert(&table, "liarsky");
    // hash_insert(&table, "pavluchenko");
    // hash_insert(&table, "dvornik");
    // hash_insert(&table, "amomogus");

    // hash_dtor(&table);

    return 0;
}
