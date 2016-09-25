//
//  TrailingZeroe.h
//  algorithm
//
//  Created by DanMiao on 1/4/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef TrailingZeroe_h
#define TrailingZeroe_h
int trailingZeroes(int n) {
    int factor = 5;
    int result = 0;
    while(factor <= n)
    {
        int tem;
        tem = n/factor;
        result += tem * (factor/5);
        factor = factor * 5;
    }
    
    return result;
}

#endif /* TrailingZeroe_h */
