//
//  WordPattern.h
//  algorithm
//
//  Created by DanMiao on 12/29/15.
//  Copyright © 2015 DanMiao. All rights reserved.
//

#ifndef WordPattern_h
#define WordPattern_h

bool wordPattern(string pattern, string str) {
    string word;
    unordered_map<char, string> record;
    int i,j = 0;
    for(i = 0; i < pattern.size(); i++)
    {
        word.clear();
        while(str[j] != ' ' && j < str.size())
            word += str[j++];
        j++;
        
        if(word.size() == 0)
            return false;
        
        if(record.find(pattern[i]) == record.end())
        {
            for(auto k : record)
                if(k.second == word)
                    return false;
            record[pattern[i]] = word;
        }
        else if(record[pattern[i]] != word)
            return false;
        
    }
    if(j < str.size())
        return false;
    else
        return true;
}


bool math(unordered_map<char, string>& record, string pattern, string str, int start)
{
    return true;
}

bool wordPatternMatch(string pattern, string str)
{
    unordered_map<char, string> record;
    return math(record, pattern, str, 0);
}
#endif /* WordPattern_h */

