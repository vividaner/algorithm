//
//  SummaryRange.h
//  algorithm
//
//  Created by DanMiao on 12/30/15.
//  Copyright © 2015 DanMiao. All rights reserved.
//

#ifndef SummaryRange_h
#define SummaryRange_h

void SortNum(string &record, int num)
{
    int tem;
    long long absnum;
    string inverse;
    if(num == 0)
    {
        record.push_back('0');
        return;
    }
    else if(num > 0)
    {
        while(num > 0)
        {
            tem = num%10;
            num = num/10;
            inverse.push_back('0' + tem);
        }
    }
    else
    {
        record.push_back('-');
        absnum = -num;
        while(absnum > 0)
        {
            tem = absnum%10;
            absnum = absnum/10;
            inverse.push_back('0' + tem);
        }
    }
    for(int i = inverse.size()-1; i >= 0; i--)
        record.push_back(inverse[i]);
}
vector<string> summaryRanges(vector<int>& nums) {
    string result_one;
    vector<string> result;
    int begin, end;
    if(nums.size() == 0)
        return result;
    begin = nums[0];
    end = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] == end+1)
            end = nums[i];
        else
        {
            if(begin != end)
            {
                SortNum(result_one, begin);
                result_one.push_back('-');
                result_one.push_back('>');
                SortNum(result_one, end);
                result.push_back(result_one);
                result_one.clear();
            }
            else
            {
                SortNum(result_one, begin);
                result.push_back(result_one);
                result_one.clear();
            }
            begin = nums[i];
            end = nums[i];
        }
    }
    if(begin != end)
    {
        SortNum(result_one, begin);
        result_one.push_back('-');
        result_one.push_back('>');
        SortNum(result_one, end);
        result.push_back(result_one);
        result_one.clear();
    }
    else
    {
        SortNum(result_one, begin);
        result.push_back(result_one);
        result_one.clear();
    }
    return result;
}
#endif /* SummaryRange_h */
