//
//  ContainDuplicate3.h
//  algorithm
//
//  Created by DanMiao on 1/12/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef ContainDuplicate3_h
#define ContainDuplicate3_h
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(nums.size() < t)
    {
        for(int i = 0; i < nums.size(); i++)
            for(int j = i+1; j < nums.size(); j++)
            {
                if(abs(nums[i] - nums[j]) <= t && j - i <= k)
                    return true;
            }
        return false;
    }
    else
    {
        unordered_map<int, vector<int>> record;
        for(int i = 0; i < nums.size(); i++)
        {
            if(record.find(nums[i]) == record.end())
                record[nums[i]].push_back(i);
            
            for(int m = -t; m <=t; m++)
            {
                if(record.find(nums[i] + m) != record.end())
                {
                    for(auto j : record[nums[i] + m])
                    {
                        if(i != j && abs(i-j) <= k)
                            return true;
                    }
                }
            }
        }
        return false;
    }
}

#endif /* ContainDuplicate3_h */
