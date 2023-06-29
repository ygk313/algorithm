// 프로그래머스 Level 2 - 행렬 테두리 회전하기 : https://school.programmers.co.kr/learn/courses/30/lessons/77485
#include <bits/stdc++.h>

using namespace std;

int board[101][101];
int BackupBoard[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int cnt = 1;
    
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            board[i][j] = cnt;
            BackupBoard[i][j] = cnt;
            cnt++;
        }
    }
    
    for(auto v: queries){
        int x1 = v[0], y1 = v[1], x2=v[2], y2=v[3];
        int mini = 10001;
        
        // right x1
        for(int y=y1; y<y2; y++){
            board[x1][y+1] = BackupBoard[x1][y];
            mini = min(mini, board[x1][y+1]);
        }
        // down - y2
        for(int x=x1; x<x2; x++){
            board[x+1][y2] = BackupBoard[x][y2];
            mini = min(mini, board[x+1][y2]);
        }
        // left - x2
        for(int y=y2; y>y1; y--){
            board[x2][y-1] = BackupBoard[x2][y];
            mini = min(mini, board[x2][y-1]);
        }
        //up - y1
        for(int x=x2; x>x1; x--){
            board[x-1][y1] = BackupBoard[x][y1];
            mini = min(mini, board[x-1][y1]);
        }
        //copy
        for(int i=1; i<=rows; i++){
            for(int j=1; j<=columns; j++){
            BackupBoard[i][j] = board[i][j];
            }
        }
        
        answer.push_back(mini);
    }
    return answer;
}