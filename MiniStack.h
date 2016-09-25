//
//  Header.h
//  algorithm
//
//  Created by DanMiao on 12/28/15.
//  Copyright © 2015 DanMiao. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <stack>

class MinStack {
private:
    stack<int> Data;
    stack<int> MiniRecord;
public:
    void push(int x) {
        Data.push(x);
        if(MiniRecord.empty() || x < MiniRecord.top())
            MiniRecord.push(x);
    }
    
    void pop() {
        if(!Data.empty())
        {
            int tem = Data.top();
            Data.pop();
            if(tem == MiniRecord.top())
                MiniRecord.pop();
        }
    }
    
    int top() {
        return Data.top();
    }
    
    int getMin() {
        return MiniRecord.top();
    }
};

#endif /* Header_h */
