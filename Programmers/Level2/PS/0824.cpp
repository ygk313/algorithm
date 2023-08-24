// Programmers Lv 2. 쿼드 압축 후 세기
// https://school.programmers.co.kr/learn/courses/30/lessons/68936

// 재귀를 활용해 해결하는 문제.

#include <bits/stdc++.h>

using namespace std;

int quard[1025][1025];
int ans[2] = {0,};

bool chk(int x, int y, int n){
    
    bool flag = true;

    for(int i= x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if (quard[x][y] != quard[i][j]) {
                flag = false;
                break;
            }
        }
    }
    
    return flag;
}

void recursive(int x, int y, int n){
    
    if (chk(x, y, n)){
        ans[quard[x][y]]++;
        return;
    }
    
    if (n == 1){
        ans[quard[x][y]]++;
        return;
    }
    
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            recursive(x+i*n/2, y+j*n/2, n/2);
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    for(int i=0; i<arr.size(); i++)
        for(int j=0; j<arr[0].size(); j++)
            quard[i][j] = arr[i][j];

    recursive(0, 0, arr.size());
    
    answer.push_back(ans[0]);
    answer.push_back(ans[1]);

    return answer;
}