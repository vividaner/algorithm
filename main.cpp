//
//  main.cpp
//  algorithm
//
//  Created by DanMiao on 5/29/15.
//  Copyright (c) 2015 DanMiao. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include "MultiplyString.h"
#include "BitwiseAnd.h"
#include "LongestIncreasingSub.h"
#include "Bull_cow.h"
#include "BulbSwitcher.h"
#include "RemoveDupLetter.h"
#include "MiniStack.h"
#include "WordPattern.h"
#include "SummaryRange.h"
#include "TrailingZeroe.h"
#include "SurroundedRegion.h"
#include "ContainDuplicate3.h"
#include "Calculator.h"
#include "MinWindow.h"
#include "Sort.h"
#include "HashTable.h"
#include "Tree.h"
#include "multipleinheritance.h"
#include "Fliggame.h"
#include "Paint_Fence.h"
#include "Wiggle_Sort.h"

using namespace std;
#include <vector>

struct Interval {
         int start;
         int end;
         Interval() : start(0), end(0) {}
         Interval(int s, int e) : start(s), end(e) {}
     };

bool myfunction(Interval& a, Interval& b)
{
    return a.start < b.start;
}


int findinsert_start(vector<Interval>& intervals, Interval newInterval)
{
    int start = 0;
    int end = intervals.size()-1;
    int mid, target = newInterval.start;
    while(start <= end)
    {
        mid = start + (end-start)/2;
        if(intervals[mid].start == target)
            return mid;
        else if(intervals[mid].start < target)
            start = mid+1;
        else
            end = mid-1;
    }
    if(intervals[mid].start < target)
        mid++;
    return mid;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    if(intervals.size() == 0)
    {
        intervals.insert(intervals.begin(), newInterval);
        return intervals;
    }
    
    if(intervals[0].start > newInterval.end)
    {
        intervals.insert(intervals.begin(), newInterval);
        return intervals;
    }
    
    if(intervals[intervals.size()-1].end < newInterval.start)
    {
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
    
    int pos_start = findinsert_start(intervals, newInterval);
    
    if(pos_start == 0 && newInterval.start > intervals[max(pos_start-1, 0)].end)
    {
        intervals.insert(intervals.begin() + pos_start, newInterval);
    }
    else
    {
        intervals[pos_start-1].end = newInterval.end;
    }
    
    int target = intervals[pos_start].end;
    int i = pos_start+1;
    while(i < intervals.size())
    {
        if(target > intervals[i].end)
        {
            intervals.erase(intervals.begin()+i);
        }
        else if(target >= intervals[i].start)
        {
            intervals[i-1].end = intervals[i].end;
            intervals.erase(intervals.begin()+i);
            break;
        }
        else
        {
            break;
        }
    }
    
    return intervals;
}

vector<Interval> merge(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), myfunction);
    return intervals;
}

bool findnext(vector<vector<char>>& board, string& s, int start_index, int pos_y, int pos_x)
{
    int m = board.size();
    int n = board[0].size();
    if(start_index == s.size())
        return true;
    char tem = board[pos_y][pos_x];
    board[pos_y][pos_x] = '.';
    bool record = false;
    
    if(pos_y < m-1 && s[start_index] == board[pos_y+1][pos_x])
        record = record || findnext(board, s, start_index+1, pos_y+1, pos_x);
    
    if(pos_y > 0 && s[start_index] == board[pos_y-1][pos_x])
        record = record || findnext(board, s, start_index+1, pos_y-1, pos_x);
    
    if(pos_x < n-1 && s[start_index] == board[pos_y][pos_x+1])
        record = record || findnext(board, s, start_index+1, pos_y, pos_x+1);
    
    if(pos_x > 0&& s[start_index] == board[pos_y][pos_x-1])
        record = record || findnext(board, s, start_index+1, pos_y, pos_x-1);
    board[pos_y][pos_x] = tem;
    
    return record;
}
bool isIntheBoard(vector<vector<char>>& board, string& s)
{
    int m = board.size();
    int n = board[0].size();
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == s[0] && findnext(board, s, 1, i, j))
                return true;
        }
    }
    return false;
    
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> result;
    int m = board.size();
    if(m == 0)
        return result;
    int n = board[0].size();
    if(n == 0)
        return result;
    
    for(auto s : words)
    {
        if(s.size() > 0 && isIntheBoard(board, s))
        {
            bool isDuplicate = false;
            for(auto k : result)
            {
                if(k == s)
                {
                    isDuplicate = true;
                    break;
                }
            }
            if(!isDuplicate)
                result.push_back(s);
        }
        
    }
    
    return result;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> q;
    for(int i = 0; i < nums.size(); i++)
    {
        if(!q.empty() && q.front() == i-k)
        {
            result.push_back(nums[q.front()]);
            q.pop_front();
        }
        while(!q.empty() && nums[q.back()] < nums[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    if(!q.empty())
        result.push_back(nums[q.front()]);
    
    return result;
    
}




bool isMatchSearch(string& s, string& p, int ss, int ps)
{
    if(ss == s.size() && ps == p.size())
        return true;
    if(ss >= s.size() || ps >= p.size())
        return false;
    
    if(p[ps] != '*' && p[ps] != '.')
    {
        if(s[ss] == p[ps])
            return isMatchSearch(s, p, ss+1, ps+1);
        else if(ps < p.size()-1 && p[ps+1] == '*')
            return isMatchSearch(s, p, ss, ps+2);
        else
            return false;
    }
    else if(p[ps] == '.')
    {
        return isMatchSearch(s, p, ss+1, ps+1);
    }
    else
    {
        if(p[ps-1] != s[ss] && p[ps-1] != '.')
            return false;
        else
        {
            char target = s[ss];
            for(int i = ss; i <= s.size(); i++)
            {
                if(isMatchSearch(s, p, i, ps+1))
                    return true;
            }
            return false;
        }
    }
}

bool isMatch(string s, string p) {
    return isMatchSearch(s, p, 0, 0);
}



void keepmidnum()
{
    vector<int> data = {4, 5, 1, 3, 2, 6, 0};
    vector<int> record;
    priority_queue<int> q;
    for(int i = 0; i < data.size(); i++)
    {
        q.push(data[i]);
        
    }
}





int lengthOfLongestSubstringKDistinct(string s, int k) {
    int start = 0;
    int end = 0;
    int max_len = 0;
    unordered_map<char, int> record;
    for(int i = 0; i < s.size(); i++)
    {
        record[s[i]]++;
        end = i;
        if(record.size() > k)
        {
            while(record.size() > k && start < end)
            {
                record[s[start]]--;
                if(record[s[start]] == 0)
                    record.erase(s[start]);
                start++;
            }
        }
        if(end-start+1 > max_len)
            max_len = end-start+1;
    }
    return max_len;

}

bool checktable(unordered_map<char, int>& t, int k, bool& allinvalid)
{
    bool valid = true;
    allinvalid = true;
    for(auto i : t)
    {
        if(i.second < k)
            valid = false;
        else
            allinvalid = false;
    }
    return valid;
}
int longestSubstring(string s, int k) {
    int max_len = 0;
    if(s.size() == 0)
        return 0;
    unordered_map<char, int> record;
    for(auto i:s)
        record[i]++;
    bool allinvalid;
    if(checktable(record, k, allinvalid))
        return (int)s.size();
    if(allinvalid)
        return 0;
    else
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(record[s[i]] < k)
            {
                if(i > 0)
                    max_len = max(max_len, longestSubstring(s.substr(0,i), k));
                if(i < s.size()-1)
                    max_len = max(max_len, longestSubstring(s.substr(i+1, s.size()-i-1),k));
            }
        }
        return max_len;
    }
}

vector<int> countSmaller(vector<int>& nums) {
    vector<int> buf(nums);
    vector<int> result;
    if(nums.size() == 0)
        return result;
    sort(buf.begin(), buf.end());
    unordered_map<int, int> record;
    record[buf[0]] = 0;
    
    int previous = buf[0];
    int pre_cnt = 0;
    for(int i = 1; i < buf.size(); i++)
    {
        if(buf[i] > previous)
        {
            record[buf[i]] = i;
            previous = buf[i];
            pre_cnt = i;
        }
    }
    
    for(int i = 0; i < nums.size(); i++)
        result.push_back(record[nums[i]]);
    return result;
}

bool checkpossible(string& s, int* record)
{
    for(auto i : s)
        record[i-'a']++;
    int oddnum = 0;
    for(int k = 0; k < 26; k++)
    {
        if(record[k] & 1)
            oddnum++;
    }
    if(oddnum > 1)
        return false;
    else
        return true;
}


bool checkempty(int* record)
{
    for(int i = 0; i < 26; i++)
    {
        if(record[i] != 0)
            return false;
    }
    return true;
}
void generateallresult(vector<string>& result, string& path, int* record)
{
    if(checkempty(record))
    {
        result.push_back(path);
        return;
    }
    bool process = false;
    char tem;
    
    unordered_map<char, int>::iterator pos;
    for(int i = 0; i < 26; i++)
    {
        if(record[i] >= 2)
        {
            path.push_back('a'+i);
            path.insert(path.begin(), 'a'+i);
            tem = 'a'+i;
            record[i] -= 2;
            generateallresult(result, path, record);
            process = true;
        }
        else if(record[i] == 1)
        {
            path.insert(path.begin()+path.size()/2, 'a'+i);
            record[i]--;
            generateallresult(result, path, record);
        }
        if(process)
        {
            path.erase(path.begin());
            path.erase(path.end()-1);
            record[i] += 2;
            process = false;
        }
        
    }
}

void allPalindromePermutation(string s)
{
    vector<string> result;
    string path;
    int record[26] = {0};
    if(checkpossible(s, record))
    {
        generateallresult(result, path, record);
    }
    
    for(auto i : result)
        cout << i << endl;
    cout << result.size() << endl;
    
}

bool isPalindromePermutation(string s)
{
    unordered_map<char, int> record;
    for(auto i : s)
        record[i]++;
    int oddnum = 0;
    for(auto k : record)
    {
        if(k.second % 2 != 0)
        {
            oddnum++;
        }
        if(oddnum > 1)
            return false;
    }
    return true;
}

int findmissone(int* array, int n)
{
    int left = 0;
    int right = n-1;
    int mid = 0;
    while(left <= right)
    {
        mid = left + (right-left)/2;
        
        if(array[mid] == mid)
            left = mid+1;
        else
            right = mid-1;
    }
    if(mid == array[mid])
    {
        return mid+1;
    }
    else
        return mid;
}


string longestPalindrome(string s) {
    int n = s.size();
    if(n == 0)
        return 0;
    bool record[n][n];
    int start = 0;
    fill_n(&record[0][0], n*n, false);
    int max_len = 1;
    for(int i = 0; i < n; i++)
    {
        record[i][i] = true;
        for(int j = 0; j < i; j++)
        {
            if(s[j] != s[i])
                record[j][i] = false;
            else
            {
                record[j][i] = (i-j==1)? true : record[i-1][j+1];
            }
            if(record[j][i] && i-j+1 > max_len)
            {
                max_len = i-j+1;
                start = j;
            }
        }
    }
    return s.substr(start, max_len);
}


bool skip(char& s)
{
    if((s>='a' && s<='z') || (s>='A' && s<='Z') || (s>='0' && s<='9'))
        return true;
    else
        return false;
}
bool isPalindrome(string s) {
    int n = s.size();
    if(n == 0)
        return true;
    int i = 0, j = n-1;
    int dis = 'A'-'a';
    
    while(i <= j)
    {
        while(!skip(s[i]))
            i++;
        while(!skip(s[j]))
            j--;
        if(i <= j)
        {
            if(s[i] == s[j] || s[i] - s[j] == dis || s[j] - s[i] == dis)
            {
                i++;
                j--;
            }
            else
                return false;
        }
        else
            break;
    }
    return true;
}


int minCut(string s) {
    int n = s.size();
    bool judge[n][n];
    fill_n(&judge[0][0], n*n, false);
    for(int i = 0; i < n; i++)
    {
        judge[i][i] = true;
        for(int j = 0; j < i; j++)
        {
            judge[j][i] = (s[j] == s[i]) && (i-j==1 || judge[j+1][i-1]);
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << judge[j][i];
        cout << endl;
    }
    
    int record[n+1];
    fill_n(record, n+1, INT_MAX);
    record[0] = -1;
    
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = i-1; j >= 0; j--)
        {
            if(judge[j][i-1])
            {
                record[i] = min(record[j]+1, record[i]);
            }
        }
    }
    
    return record[n];
}



int main(int argc, const char * argv[]) {
   
    
    
    string s = "aaccbbdd";
    allPalindromePermutation(s);
    
    keepmidnum();
    
    
    string beginWord = "a";
    string endWord = "c";
    unordered_set<string> data = {"a","b","c"};
    
    
    /*vector<vector<char>> board = {{'X', '0', 'X', 'X'},
                                  {'0', 'X', '0', 'X'},
                                  {'X', '0', 'X', '0'},
                                  {'0', 'X', '0', 'X'},
                                  {'X', '0', 'X', '0'},
                                  {'0', 'X', '0', 'X'}};*/
    
    /*vector<vector<char>> board = {{'X', 'X', 'X'},
                                  {'X', '0', 'X'},
                                  {'X', 'X', 'X'}};*/
    
    
    
//    int Num = 10;
//    int a[] = {3, 1, 9, 5, 23, 32, 7, 2, 15, 21};
//    void (*sort)(int*, int);
//    
//    
//    sort = ShellSort;
//    sort(a, Num);
//    for(int i = 0; i < Num; i++)
//        cout << a[i] << endl;
//    return 0;
}
