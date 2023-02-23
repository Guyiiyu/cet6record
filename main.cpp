#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <ctime>

#include "util.h"

using namespace std;

map<string, int> word_count;
vector<pair<int, string>> all_words;
vector<string> words;


int main(){
    if(read_file("WordList.txt") || read_all_words("words.txt")){
        perror("program init failed");
    }
    printf("read %d words\n", (int)words.size());
    string input;
    while(input != "exit"){
        cin >> input;
        for(auto &ch:input) if(ch >= 'A' && ch <= 'Z') ch += 'a' - 'A';
        if(input == "exit") break;
        if(check_word(input)){

            word_count[input]++;
            printf("word \"%s\" added!\n", input.c_str());
        }
        else puts("Incorrect word! Please retry.");   
    }

    for(auto [word, cnt]: word_count){
        all_words.push_back({cnt, word});
    }
    sort(all_words.begin(), all_words.end());
    reverse(all_words.begin(), all_words.end());


    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int day = aTime->tm_mday;
    int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    int year = aTime->tm_year + 1900; // Year is # years since 1900
    char *bakup_filename;
    asprintf(&bakup_filename, "backup/%4d-%02d-%02d.txt", year, month, day);

    if(save_file("WordList.txt") || save_file(bakup_filename)){
        save_file("save_file.txt");
        perror("program save failed");
    }

    puts("See next time!");
    return 0;
}