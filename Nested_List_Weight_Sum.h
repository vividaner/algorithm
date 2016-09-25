//
//  Nested_List_Weight_Sum.h
//  algorithm
//
//  Created by DanMiao on 9/21/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef Nested_List_Weight_Sum_h
#define Nested_List_Weight_Sum_h

int getSum(list& ni, int level)
{
    int res = 0;
    if(ni.isInteger())
        return level * ni.getInter();
    for(auto a : ni.getList())
        res += getSum(a, level+1);
}
int depthSum(vector<list>& nestedList)
{
    int res = 0;
    for(auto i : nestedList)
        res += getSum(i, 1);
    return res;
}

#endif /* Nested_List_Weight_Sum_h */
