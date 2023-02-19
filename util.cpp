#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;


extern map<string, int> word_count;
extern vector<pair<int, string>> all_words;
extern vector<string> words;



int read_file(const char *filename){
    FILE *file;
    if(!(file = fopen(filename, "r"))){
        perror("open file for reading faild");
    }
    string word; word.resize(30);
    int cnt;
    while(fscanf(file, "%s%d", &word[0], &cnt) == 2){
        word_count[word] += cnt;
    }
    fclose(file);
    return 0;
}

int save_file(const char *filename){
    FILE *file;
    if(!(file = fopen(filename, "w"))){
        perror("open file for writing faild");
    }
    for(auto [cnt, word]: all_words){
        fprintf(file, "%s %d\n", word.c_str(), cnt);
    }
    fclose(file);
    return 0;
}

int read_all_words(const char *filename){
    FILE *file;
    if(!(file = fopen(filename, "r"))){
        perror("open words file for reading faild");
    }
    char word[30];
    while(fscanf(file, "%s", word) == 1){
        words.push_back(word);
    }
    fclose(file);
    return 0;
}

bool check_word(string word){
    for(int i=0; i<(int)words.size(); i++)
        if(words[i].size() == word.size()){
            bool flag = true;
            for(int j=0; j<(int)word.size(); j++)
                if(words[i][j] != word[j])
                    flag = false;
            if(flag) return true;
        }
    return false;
}