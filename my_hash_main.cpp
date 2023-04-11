#include "my_hash.h"
#include "hash_functions.h"

int main()
{
    hash_table table;
    hash_ctor(&table, TABLE_SIZE, &hash_first);

    hash_insert(&table, "torch");
    hash_insert(&table, "danetorcj");
    hash_insert(&table, "zarembo");
    hash_insert(&table, "moshkov");
    hash_insert(&table, "liarsky");
    hash_insert(&table, "pavluchenko");
    hash_insert(&table, "dvornik");
    hash_insert(&table, "amomogus");

    hash_dtor(&table);

    return 0;
}
