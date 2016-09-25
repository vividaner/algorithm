//
//  Search.h
//  algorithm
//
//  Created by DanMiao on 8/18/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef Search_h
#define Search_h

bool BinarySearch(int a[], int Num, int x)
{
    int start = 0;
    int end = Num-1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(a[mid] == x)
            return true;
        else if(a[mid] < x)
            start = mid+1;
        else
            end = mid-1;
    }
    return false;
}

#endif /* Search_h */
