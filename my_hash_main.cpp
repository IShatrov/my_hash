#include "my_hash.h"
#include "hash_functions.h"
#include "my_read.h"

int main()
{
    FILE* file = fopen("shakespeare.txt", "r");

    char* text = read_text(file);
    int n_lines = 0;
    char** strings = separate_text(text, '\n', &n_lines);

    printf("lines found: %d\n", n_lines);

    for(int i = 0; i < n_lines; i++) 
    {
        char* t = strings[i];
        printf("%d. %s\n", i, t);
    }

    free(text);
    free(strings);
    fclose(file);

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
