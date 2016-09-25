//
//  Bull_cow.h
//  algorithm
//
//  Created by DanMiao on 12/22/15.
//  Copyright © 2015 DanMiao. All rights reserved.
//

#ifndef Bull_cow_h
#define Bull_cow_h
#include <unordered_map>
using namespace std;

string getHint(string secret, string guess) {
    int bull_num = 0;
    int cow_num = 0;
    unordered_map<int, int> record;
    vector<bool> flag;
    for(unsigned int i = 0; i < secret.size(); i++)
    {
        if(secret[i] == guess[i])
        {
            bull_num++;
            flag.push_back(true);
        }
        else
            flag.push_back(false);
    }
    
    for(unsigned int i = 0; i < secret.size(); i++)
    {
        if(flag[i] == false)
        {
            record[secret[i]]++;
        }
    }
    
    for(unsigned int i = 0; i < guess.size(); i++)
    {
        if(record.find(guess[i]) != record.end() && record[guess[i]] > 0)
        {
            record[guess[i]]--;
            cow_num++;
        }
    }
    
    
    string result;
    result.push_back('0' + bull_num);
    result.push_back('A');
    result.push_back('0' + cow_num);
    result.push_back('B');
    
    return result;
}

#endif /* Bull_cow_h */
