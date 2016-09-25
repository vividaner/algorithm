//
//  BulbSwitcher.h
//  algorithm
//
//  Created by DanMiao on 12/23/15.
//  Copyright © 2015 DanMiao. All rights reserved.
//

#ifndef BulbSwitcher_h
#define BulbSwitcher_h

int bulbSwitch_Rev(int n)
{
    int result = 0;
    for(int j = 1; j * j <= n; j++)
        result++;
    
    return result;
}

int bulbSwitch(int n) {
    bool* record = new bool[n];
    for(int i = 0; i < n; i++)
        record[i] = true;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; i*j-1 < n; j++)
        {
            int index = i*j-1;
            if(record[index] == true)
                record[index] = false;
            else
                record[index] = true;
        }
    }
    
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        if(record[i])
            result++;
    }
    
    delete[] record;
    return result;
}

#endif /* BulbSwitcher_h */
