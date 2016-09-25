//
//  MultiplyString.h
//  algorithm
//
//  Created by DanMiao on 12/14/15.
//  Copyright © 2015 DanMiao. All rights reserved.
//

#ifndef MultiplyString_h
#define MultiplyString_h
using namespace std;

string multiply(string num1, string num2) {
    bool label1 = false;
    bool label2 = false;
    bool label;
    int start1 = 0;
    int start2 = 0;
    int value1 = 0;
    int value2 = 0;
    int value_set = 0;
    int value_setadd = 0;
    int mul_value;
    string result;
    if(num1.size() == 0 || num2.size() == 0)
        return result;
    if(num1[0] == '-')
    {
        label1 = true;
        start1 = 1;
        num1.erase(num1.begin());
    }
    if(num2[0] == '-')
    {
        label2 = true;
        start2 = 1;
        num2.erase(num2.begin());
    }
    if((label1 && !label2) || (!label1 && label2))
        label = true;
    else
        label = false;
    reverse(begin(num1), end(num1));
    reverse(begin(num2), end(num2));
    for(int i = 0; i < num2.size(); i++)
    {
        value2 = num2[i] - '0';
        for(int j = 0; j < num1.size(); j++)
        {
            value1 = num1[j] - '0';
            mul_value = value1 * value2 + value_set;
            if(mul_value > 10)
            {
                value_set = 1;
                mul_value -= 10;
            }
            else
                value_set = 0;
            if(i+j >= result.size())
                result.push_back(mul_value + '0');
            else
            {
                int add = result[i+j] - '0' + mul_value + value_setadd;
                if(add > 10)
                {
                    add -= 10;
                    value_setadd = 1;
                    result[i+j] = add + '0';
                }
                else
                {
                    result[i+j] = add + '0';
                    value_setadd = 0;
                }
            }
        }
    }
    if(value_setadd == 1)
        result.push_back('1');
    if(label)
        result.push_back('-');
    reverse(begin(result), end(result));
    
    return result;
    
    
}

#endif /* MultiplyString_h */
