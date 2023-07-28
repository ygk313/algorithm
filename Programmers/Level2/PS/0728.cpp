// Programmers Lv 2. 게임 맵 최단 거리
// https://school.programmers.co.kr/learn/courses/30/lessons/1844
// 전형적인 BFS 문제

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int board[102][102];
int visited[102][102];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<vector<int> > maps)
{
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    
    while (!q.empty()){
        
        auto cur = q.front(); q.pop();
        
        for(int k=0; k<4; k++){
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];
            
            if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size()) continue;
            if (visited[nx][ny] != 0 || maps[cur.X][cur.Y] == 0) continue;
            
            q.push({nx, ny});
            visited[nx][ny] = visited[cur.X][cur.Y] + 1;
        }
    
    }
    
    if (visited[maps.size()-1][maps[0].size()-1] == 0) return -1;
    else return visited[maps.size()-1][maps[0].size()-1];
}