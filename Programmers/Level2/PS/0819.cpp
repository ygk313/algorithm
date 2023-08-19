// Programmers Lv 2. 미로탈출
// https://school.programmers.co.kr/learn/courses/30/lessons/159993
// 출발점 -> 레버, 레버 -> 탈출구 아이디어와 BFS 활용하기.
// BFS는 최단 거리를 보장함.

#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int visitedLever[101][101];
int visited[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<string> maps) {    
    pair<int, int> s, l, e;
    
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[0].size(); j++){
            visitedLever[i][j] = visited[i][j] = -1;
            if (maps[i][j] == 'S'){
                s.X = i;
                s.Y = j;
            }
            else if (maps[i][j] == 'E'){
                e.X = i;
                e.Y = j;
            }
            else if (maps[i][j] == 'L'){
                l.X = i;
                l.Y = j;
            }
        }
    }
    
    queue<pair<int, int>> Q;
    Q.push(s);
    visitedLever[s.X][s.Y] = 0;
    
    while(!Q.empty()){
        
        auto cur = Q.front(); Q.pop();
        
        for(int d=0; d<4; d++){
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];
            
            if (nx < 0|| nx >= maps.size() || ny < 0 || ny >=maps[0].size()) continue;
            if (maps[nx][ny] == 'X' || visitedLever[nx][ny] != -1) continue;
            Q.push({nx, ny});
            visitedLever[nx][ny] = visitedLever[cur.X][cur.Y] + 1;
        }
        
    }
    
    if (visitedLever[l.X][l.Y] == -1) return -1;

    Q.push(l);
    visited[l.X][l.Y] = visitedLever[l.X][l.Y];
    
    while(!Q.empty()){
        
        auto cur = Q.front(); Q.pop();
        
        for(int d=0; d<4; d++){
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];
            
            if (nx < 0|| nx >= maps.size() || ny < 0 || ny >=maps[0].size()) continue;
            if (maps[nx][ny] == 'X' || visited[nx][ny] != -1) continue;
            Q.push({nx, ny});
            visited[nx][ny] = visited[cur.X][cur.Y] + 1;
        }
        
    }
    
    return visited[e.X][e.Y];
}