#include "my_hash.h"
#include "my_read.h"

const char* WORDS_FILENAME = "shakespeare.txt";
const char* OUTPUT_FILENAME = "res.csv";

int main()
{
    int lines_found = 0;
    char* text;
    const char** words = prepare_text(WORDS_FILENAME, &lines_found, &text);

    do_tests(lines_found, words, OUTPUT_FILENAME);

    free(text);
    free(words);

    return 0;
}
