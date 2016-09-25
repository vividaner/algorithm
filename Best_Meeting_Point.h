//
//  Best_Meeting_Point.h
//  algorithm
//
//  Created by DanMiao on 9/23/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef Best_Meeting_Point_h
#define Best_Meeting_Point_h

int minTotalDistance(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    
    vector<int> row_pos;
    vector<int> col_pos;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == 1)
            {
                row_pos.push_back(i);
                col_pos.push_back(j);
            }
        }
    }
    sort(col_pos.begin(), col_pos.end());
    int c = col_pos.size();
    int x = col_pos[c/2];
    int y = row_pos[c/2];
    int res = 0;
    for(int i = 0; i < c; i++)
    {
        res += abs(col_pos[i] - x);
        res += abs(row_pos[i] - y);
    }
    
    return res;
}

#endif /* Best_Meeting_Point_h */
