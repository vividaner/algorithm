//
//  BitwiseAnd.h
//  algorithm
//
//  Created by DanMiao on 12/15/15.
//  Copyright © 2015 DanMiao. All rights reserved.
//

#ifndef BitwiseAnd_h
#define BitwiseAnd_h

#include <math.h>

int rangeBitwiseAnd(int m, int n) {
    int* label = new int[sizeof(int)];
    
    for(int i = 0; i < sizeof(int); i++)
    {
        label[i] = 1;
    }
    
    int gap = n-m;
    int num = log2((double)gap)+1;
    int sig, tem, pos;
    for(int i = 0; i < num; i++)
    {
        pos = i;
        sig = 1;
        sig = sig << i;
        tem = m & sig;
        label[pos++] = 0;
        while(tem == 1)
        {
            sig = sig << 1;
            tem = m & sig;
            label[pos++] = 1;
        }
    }
    
    int label_int = 0;
    for(int i = 0; i < sizeof(int); i++)
    {
        label_int += label[i];
        label_int = label_int << 1;
    }
    
    return label_int & m;
}
#endif /* BitwiseAnd_h */
