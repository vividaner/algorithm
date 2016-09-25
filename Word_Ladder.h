//
//  Word_Ladder.h
//  algorithm
//
//  Created by DanMiao on 9/9/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef Word_Ladder_h
#define Word_Ladder_h

int countdiff(string i, string j)
{
    int count = 0;
    for(int k = 0; k < i.size(); k++)
    {
        if(i[k] != j[k])
            count++;
    }
    return count;
}
void dfs(string beginWord, string endWord, unordered_set<string>& wordList, int& result, int count, vector<bool>& record)
{
    if(beginWord == endWord)
    {
        if(count < result)
            result = count+1;
        return;
    }
    if(wordList.size() == 0)
        return;
    string buf = beginWord;
    int i = 0;
    for(auto it = wordList.begin(); it != wordList.end(); it++, i++)
    {
        if(countdiff(beginWord, *it) == 1 && record[i])
        {
            beginWord = *it;
            count++;
            record[i] = false;
            dfs(beginWord, endWord, wordList, result, count, record);
            count--;
            record[i] = true;
            beginWord = buf;
        }
    }
    
}
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    int result = INT_MAX;
    vector<bool> record(wordList.size(), true);
    dfs(beginWord, endWord, wordList, result, 0, record);
    return result == INT_MAX ? 0 : result;
}
#endif /* Word_Ladder_h */
