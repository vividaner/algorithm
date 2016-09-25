//
//  RearrangeString.h
//  algorithm
//
//  Created by DanMiao on 9/24/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef RearrangeString_h
#define RearrangeString_h
string rearrangeString(string str, int k)
{
    string res;
    if(k == 0)
        return str;
    int n = str.size();
    unordered_map<char, int> m;
    priority_queue<pair<int, char>> q;
    for(auto a : str)
        m[a]++;
    for(auto it : m)
        q.push(make_pair(it.second, it.first));
    while(!q.empty())
    {
        vector<pair<int, char>> tem;
        int cnt = min(k, n);
        for(int i = 0; i < cnt; i++)
        {
            if(q.empty())
                return "";
            auto t = q.top();
            q.pop();
            res.push_back(t.second);
            if(--t.first > 0)
                v.push_back(t);
            n--;
        }
        for(auto a : v)
            q.push(a);
    }
    return res;
}

#endif /* RearrangeString_h */
