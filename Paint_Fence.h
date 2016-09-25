//
//  Paint_Fence.h
//  algorithm
//
//  Created by DanMiao on 9/23/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef Paint_Fence_h
#define Paint_Fence_h


int numWays(int n, int k)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return k;
    int same = 0;
    int diff = k;
    for(int i = 1; i < n; i++)
    {
        int t = diff;
        diff = (same + diff)*(k-1);
        same = t;
    }
    return same+diff;
}

int numWays2(int n, int k)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return k;
    int* record = new int[n];
    fill_n(record, n*n, 0);
    record[0] = k;
    record[1] = k*k;
    for(int i = 2; i < n; i++)
        record[i] = (k-1)*(record[i-1] + record[i-2]);
    return record[n-1];
}

#endif /* Paint_Fence_h */
