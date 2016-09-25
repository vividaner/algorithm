//
//  RemoveDupLetter.h
//  algorithm
//
//  Created by DanMiao on 12/23/15.
//  Copyright © 2015 DanMiao. All rights reserved.
//

#ifndef RemoveDupLetter_h
#define RemoveDupLetter_h
bool Invector(char &s, string &t)
{
    for(auto k:t)
    {
        if(k == s)
            return true;
    }
    return false;
}
string removeDuplicateLetters(string s) {
    string result;
    int* record = new int[26];
    memset(record, 0, sizeof(int)*26);
    
    for(int i = 0; i < s.size(); i++)
    {
        record[s[i]-'a']++;
    }
    
    char flag;
    string::iterator it;
    for(int i = 0; i < s.size(); i++)
    {
        flag = s[i];
        record[flag-'a']--;
        if(result.size() == 0)
        {
            result.push_back(flag);
            continue;
        }
        
        it = result.end();
        it--;
        char test = *it;
        if(Invector(flag, result))
            continue;
        if(test > flag && record[test-'a'] > 0)
        {
            result.erase(it);
            result.push_back(flag);
        }
        else
        {
            result.push_back(flag);
        }
        
    }
    
    
    return result;
}

#endif /* RemoveDupLetter_h */
