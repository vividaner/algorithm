//
//  MinWindow.h
//  algorithm
//
//  Created by DanMiao on 1/17/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef MinWindow_h
#define MinWindow_h

string minWindow(string s, string t) {
    int srcCount[256] = {0};
    int FoundCount[256] = {0};
    int FoundNum = 0;
    int leftwin = -1, rightwin = s.size();
    
    for(int i = 0; i < t.size(); i++)
        srcCount[t[i]]++;
    int start;
    for(int i = 0, start = 0; i < s.size(); i++)
    {
        if(srcCount[s[i]] != 0)
        {
            FoundCount[s[i]]++;
            if(FoundCount[s[i]] <= srcCount[s[i]])
                FoundNum++;
        }
        if(FoundNum == t.size())
        {
            while(srcCount[s[start]] == 0 || FoundCount[s[start]] > srcCount[s[start]])
            {
                if(srcCount[s[start]] != 0)
                    FoundCount[s[start]]--;
                start++;
            }
            if(i-start < rightwin-leftwin)
            {
                rightwin = i;
                leftwin = start;
            }
            
            FoundCount[s[start]]--;
            FoundNum--;
            start++;
        }
    }
    return leftwin == -1 ? "" : s.substr(leftwin, rightwin-leftwin+1);
}

#endif /* MinWindow_h */
