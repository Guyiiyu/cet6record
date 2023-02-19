#ifndef __UTIL_H__
#define __UTIL_H__

#include <string>

using namespace std;

int read_file(const char *filename);
int save_file(const char *filename);
int read_all_words(const char *filename);
bool check_word(string word);

#endif