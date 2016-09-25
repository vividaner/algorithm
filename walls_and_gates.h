//
//  walls_and_gates.h
//  algorithm
//
//  Created by DanMiao on 9/23/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef walls_and_gates_h
#define walls_and_gates_h


void wallsAndGates(vector<vector<int>>& room)
{
    int m = room.size();
    int n = room[0].size();
    queue<pair<int, int>>q;
    vector<vector<int>> dirs{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for(int y = 0; y < m; y++)
    {
        for(int x = 0; x < n; x++)
        {
            if(room[y][x] == 0)
                q.push({y,x});
        }
    }
    while(!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++)
        {
            int r = i+dirs[k][0];
            int s = j+dirs[k][1];
            if(r < 0 || r >= m || s < 0 || s >= n || room[r][s] < room[i][j]+1)
                continue;
            room[r][s] = room[i][j] + 1;
            q.push({r,s});
            
        }
    }
}

#endif /* walls_and_gates_h */
