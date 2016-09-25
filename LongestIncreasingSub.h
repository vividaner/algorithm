//
//  LongestIncreasingSub.h
//  algorithm
//
//  Created by DanMiao on 12/17/15.
//  Copyright © 2015 DanMiao. All rights reserved.
//

#ifndef LongestIncreasingSub_h
#define LongestIncreasingSub_h
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    //int *pRecord = new int[nums.size()];
    int pRecord[nums.size()];
    for(unsigned int i = 0; i < nums.size(); i++)
        pRecord[i] = 1;
    for(unsigned int i = 0; i < nums.size(); i++)
    {
        int maxlen = 1;
        for(unsigned int j = 0; j < i; j++)
        {
            if((nums[i] > nums[j]) && ((pRecord[j] + 1) > maxlen))
            {
                maxlen = pRecord[j] + 1;
            }
        }
        pRecord[i] = maxlen;
    }
    
    int result = 0;
    for(unsigned int i = 0; i < nums.size(); i++)
    {
        if(pRecord[i] > result)
            result = pRecord[i];
    }
    return result;
}
#endif /* LongestIncreasingSub_h */
