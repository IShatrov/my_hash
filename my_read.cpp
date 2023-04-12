#include "my_read.h"

const int DEF_N_LINES = 100;
const int REALLOC_FACTOR = 2;

int get_file_size(FILE* stream)
{
    assert(stream);

    fseek(stream, 0, SEEK_END);
    int ans = ftell(stream);

    fseek(stream, 0, SEEK_SET);

    return ans;
}

char* read_text(FILE* stream)
{
    assert(stream);

    int len = get_file_size(stream);
    assert(len);

    char* text = (char*) calloc(len + 1, sizeof(char)); // + 1 for null terminator
    assert(text);

    fread(text, sizeof(char), len, stream);

    text[len] = '\0';

    return text;
}

const char** separate_text(char* text, char sep, int* lines_found)
{
    assert(text);

    int n_lines = DEF_N_LINES;

    const char** ans = (const char**) calloc(n_lines, sizeof(char*));
    assert(ans);

    int n_read = 0;
    char* prev = text;

    while(*text)
    {
        if(*text == sep)
        {
            *text = '\0';

            ans[n_read] = prev;
            n_read++;

            prev = text + 1;

            if(n_read == n_lines)  
            {
                n_lines *= REALLOC_FACTOR;
                ans = (const char**) realloc(ans, n_lines * sizeof(char*));
                assert(ans);
            }
        }

        text++;
    }

    if(lines_found) *lines_found = n_read;

    return ans;
}

const char** prepare_text(const char* filename, int* lines_found, char** text)
{
    assert(filename);
    assert(lines_found);
    assert(text);

    FILE* file = fopen(filename, "r");
    assert(file);

    char* txt = read_text(file);

    int n_lines = 0;
    const char** strings = separate_text(txt, '\n', &n_lines);

    fclose(file);

    *lines_found = n_lines;
    *text = txt;

    return strings;
}