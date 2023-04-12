#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int get_file_size(FILE* stream);

char* read_text(FILE* stream);

const char** separate_text(char* text, char sep, int* lines_found);

const char** prepare_text(const char* filename, int* lines_found, char** text);