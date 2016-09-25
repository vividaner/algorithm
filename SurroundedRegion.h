//
//  SurroundedRegion.h
//  algorithm
//
//  Created by DanMiao on 1/7/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef SurroundedRegion_h
#define SurroundedRegion_h
bool LabelRegion(vector<vector<char>>& board, int i, int j, int** record)
{
    bool result = true;
    record[i][j] = 1;
    if(i == board.size()-1 || j == board[0].size()-1 || i==0 || j==0)
        result = false;
    if(i < board.size()-1 && record[i+1][j] == 0 && board[i+1][j] == '0')
        result &= LabelRegion(board, i+1, j, record);
    if(i > 0 && record[i-1][j] == 0 && board[i-1][j] == '0')
        result &= LabelRegion(board, i-1, j, record);
    if(j < board[0].size()-1 && record[i][j+1] == 0 && board[i][j+1] == '0')
        result &= LabelRegion(board, i, j+1, record);
    if(j > 0 && record[i][j-1] == 0 && board[i][j-1] == '0')
        result &= LabelRegion(board, i, j-1, record);
    return result;
}

void RecordUnValidRegion(vector<vector<char>>& board, int** record)
{
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(record[i][j] == 1)
                record[i][j] = 2;
        }
    }
}
void UpdateRegion(vector<vector<char>>& board, int** record)
{
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(record[i][j] == 1)
            {
                record[i][j] = 0;
                board[i][j] = 'X';
            }
        }
    }
}
void solve(vector<vector<char>>& board) {
    if(board.size() == 0)
        return;
    int** record = new int*[board.size()];
    for(int i = 0; i < board.size(); i++)
        record[i] = new int[board[0].size()];
    
    for(int i = 0; i < board.size(); i++)
        for(int j = 0; j < board[0].size(); j++)
            record[i][j] = 0;
    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == '0' && record[i][j] == 0)
            {
                if(!LabelRegion(board, i, j, record))
                    RecordUnValidRegion(board, record);
                else
                    UpdateRegion(board, record);
            }
        }
    }
}

#endif /* SurroundedRegion_h */
