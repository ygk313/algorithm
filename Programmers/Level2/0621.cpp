//https://school.programmers.co.kr/learn/courses/30/lessons/154540
#include <bits/stdc++.h>

using namespace std;

bool chk[101][101];
int board[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int n = maps.size();
    int m = maps[0].size();
    
    for(int i=0; i<n; i++){
        fill(chk[i], chk[i]+100, false);
        
        for(int j=0; j<m; j++){
            if (maps[i][j] == 'X') board[i][j] = -1;
            else board[i][j] = maps[i][j] - '0';
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            
            if (board[i][j] == -1 | chk[i][j] == true) continue;
        
            queue<pair<int, int>> q;
            q.push({i,j});
            chk[i][j] = true;
            int num = board[i][j];
            
            while(!q.empty()){
                
                auto cur = q.front(); q.pop();
                for(int d = 0; d<4; d++){
                    
                    int nx = cur.first + dx[d];
                    int ny = cur.second + dy[d];
                    
                    if (nx < 0 || nx >= n|| ny < 0 || ny >= m) continue;
                    if (chk[nx][ny] == true || board[nx][ny] == -1) continue;
                    
                    q.push({nx, ny});
                    num += board[nx][ny];
                    chk[nx][ny] = true;
                    
                }
            }
            answer.push_back(num);
        }
    }
    
    if (answer.empty()) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    
    return answer;
}