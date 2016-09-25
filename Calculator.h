//
//  Calculator.h
//  algorithm
//
//  Created by DanMiao on 1/15/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef Calculator_h
#define Calculator_h
void recordnum(string s, vector<int> &buf)
{
    int tem = 0;
    bool load = false;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            tem = 10 * tem + s[i] - '0';
            load = true;
        }
        if((i == s.size()-1) && load)
        {
            buf.push_back(tem);
            return;
        }
        else if((s[i+1] < '0' || s[i+1] > '9') && load)
        {
            buf.push_back(tem);
            tem = 0;
        }
    }
}
void calculateMultiply(string s, vector<int> &buf)
{
    int optnum = 0;
    vector<int> record;
    vector<char> opt;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '*' || s[i] == '/')
        {
            optnum++;
            record.push_back(optnum);
            opt.push_back(s[i]);
        }
        else if(s[i] == '+' || s[i] == '-')
            optnum++;
    }
    
    for(int i = 0; i < record.size(); i++)
    {
        int index = record[i] - i;
        int opt1 = buf[index-1];
        int opt2 = buf[index];
        int result;
        if(opt[i] == '*')
            result = opt1 * opt2;
        if(opt[i] == '/')
            result = opt1/opt2;
        vector<int>::iterator it = buf.begin();
        it += index-1;
        *it = result;
        it++;
        buf.erase(it);
    }
}

void calculateAdd(string s, vector<int> &buf)
{
    if(buf.size() == 1)
        return;
    vector<int>::iterator it;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '+' || s[i] == '-')
        {
            it = buf.begin();
            int opt1 = *it;
            it++;
            int opt2 = *it;
            int result;
            if(s[i] == '+')
                result = opt1 + opt2;
            else
                result = opt1 - opt2;
            it = buf.begin();
            *it = result;
            it++;
            buf.erase(it);
        }
    }
}
int calculate(string s) {
    vector<int> buf;
    recordnum(s, buf);
    calculateMultiply(s, buf);
    calculateAdd(s, buf);
    return buf[0];
}

#endif /* Calculator_h */
