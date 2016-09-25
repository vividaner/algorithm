//
//  Fliggame.h
//  algorithm
//
//  Created by DanMiao on 9/23/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef Fliggame_h
#define Fliggame_h

vector<string> generatePossibleNextMoves(string s)
{
    vector<string> result;
    for(int i = 0; i < s.size()-1; i++)
    {
        if(s[i] == '+' && s[i+1] == '+')
        {
            s[i] = '-';
            s[i+1] = '-';
            result.push_back(s);
            s[i] = '+';
            s[i+1] = '+';
        }
    }
    
    return result;
}

bool canWin(string s)
{
    bool canWinValue = false;
    for(int i = 0; i < s.size()-1; i++)
    {
        if(s[i] == '+' && s[i+1] == '+')
        {
            s[i] = '-';
            s[i+1] = '-';
            
            if(!canWin(s))
                return true;
            s[i] = '+';
            s[i+1] = '+';
        }
    }
    return false;
}


#endif /* Fliggame_h */
