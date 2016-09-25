//
//  HashTable.h
//  algorithm
//
//  Created by DanMiao on 8/16/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

const int MAX_WORD_LEN = 10;
using namespace std;
#include <map>

void Dictionary()
{
    char line[MAX_WORD_LEN * 2 + 1];
    char s1[MAX_WORD_LEN + 1];
    char s2[MAX_WORD_LEN + 1];
    map<string, string> dict;
    while(gets(line) && line[0] != 0)
    {
        sscanf(line, "%s %s", s1, s2);
        dict[s2] = s1;
    }
     while(gets(line))
     {
         if(dict[line].length() == 0)
             puts("eh");
         else
             printf("%s\n", dict[line].c_str());
     }
}


void MindistanceinWords()
{
    map<string, int> dict;
    int mindistance = MAX_INPUT;
    char line[2 * MAX_WORD_LEN + 1];
    char s[2 * MAX_WORD_LEN + 1];
    int index = 1;
    while(gets(line) && line[0] != 0)
    {
        sscanf(line, "%s", s);
        if(dict[s] == 0)
            dict[s] = index;
        else
        {
            if(index - dict[s] < mindistance)
                mindistance = index - dict[s];
            dict[s] = index;
        }
        index++;
    }
    cout << mindistance << endl;
}

bool can_string_be_palindrome(const string &s)
{
    unordered_map<char, int> hash;
    for_each(s.begin(), s.end(), [&hash](const char &c){++hash[c];});
    int odd_count = 0;
    for(const pair<char, int> &p : hash)
    {
        if(p.second & 1 && ++odd_count > 1)
            break;
    }
    return odd_count <=1;
}


bool anoymous_letter(const string &L, const string &M)
{
    unordered_map<char, int> hash;
    for(int i = 0; i < L.size(); i++)
        hash[L[i]]++;
    
    for(const char &c : M)
    {
        auto it = hash.find(c);
        if(it != hash.end())
        {
            it->second--;
            if(it->second == 0)
                hash.erase(it);
        }
        else
            return false;
    }
    return hash.empty();
}

#endif /* HashTable_h */
