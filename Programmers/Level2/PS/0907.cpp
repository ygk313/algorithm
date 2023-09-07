// Programmers Lv 2. N-Queen
// https://school.programmers.co.kr/learn/courses/30/lessons/12952?language=cpp#
// 백트래킹 문제 - 어떤 상황에서는 더 이상 진행하지 않도록 조건을 건다.

#include <bits/stdc++.h>

using namespace std;

int num = 0;
int answer = 0;
vector<pair<int, int>> v;

bool checking(int x, int y){
    
    if (v.empty()) return true;
    
    for(auto cur: v){
        if (cur.second == y) return false;
        if (abs(x-cur.first) == abs(y-cur.second)) return false;
    }
    
    return true;
}

void recursive(int x){
    
    if (x == num){
        answer++;
        return;
    }
    
    for(int j=0; j<num; j++){
        
        if (checking(x, j)){
            v.push_back({x,j});
            recursive(x+1);
            v.pop_back();
        }
    }
}

int solution(int n) {
    num = n;
    recursive(0);
    return answer;
}