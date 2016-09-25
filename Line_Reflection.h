//
//  Line_Reflection.h
//  algorithm
//
//  Created by DanMiao on 9/24/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef Line_Reflection_h
#define Line_Reflection_h

bool isReflected(vector<pair<int, int>>& points)
{
    set<pair<int, int>> st;
    int mx = INT_MIN;
    int mn = INT_MAX;
    
    for(auto a : points)
    {
        mx = max(mx, a.first);
        mn = min(mn, a.first);
        st.insert(a);
        
    }
    int sum = mx + mn;
    for(auto a : points)
        if(st.count(make_pair(sum-a.first, a.second))==0)
            return false;
    return true;
}
#endif /* Line_Reflection_h */
