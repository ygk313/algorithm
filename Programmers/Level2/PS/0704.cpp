// Programmers Lv 3. 가장 큰 정사각형 찾기 
// https://school.programmers.co.kr/learn/courses/30/lessons/12905?language=cpp#

// 모든 게 0 인 경우 처리 필요
#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
bool zeroFlag = true;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int row = board.size(), col = board[0].size();
    int maxi = 1;
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            dp[i][j] = board[i][j];
            if (dp[i][j] == 1) zeroFlag = false;
        }
    }
    
    if (zeroFlag) return 0;
    
    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            if (dp[i][j] == 0) continue;
            
            dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]))+1;
            maxi = max(maxi, dp[i][j]);
        }
    }
    
    answer = maxi * maxi;
    return answer;
}