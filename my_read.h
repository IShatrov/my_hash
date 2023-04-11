#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int get_file_size(FILE* stream);

char* read_text(FILE* stream);

char** separate_text(char* text, char sep, int* lines_found);