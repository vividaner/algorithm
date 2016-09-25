//
//  Wiggle_Sort.h
//  algorithm
//
//  Created by DanMiao on 9/23/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef Wiggle_Sort_h
#define Wiggle_Sort_h

void wiggleSort(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    for(int i = 2; i < nums.size(); i=i+2)
         swap(nums[i], nums[i-1]);
    
}

#endif /* Wiggle_Sort_h */
