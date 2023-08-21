// Programmers Lv 2. 혼자 놀기의 달인
// https://school.programmers.co.kr/learn/courses/30/lessons/131130
// cycle의 개수를 확인하는 문제

#include <bits/stdc++.h>

using namespace std;

bool cyclic[101];
vector<int> compare;
int solution(vector<int> cards) {
    int answer = 1;
    
    for(int i=0; i<cards.size(); i++){
        if (i+1 == cards[i]) {
            cyclic[i+1]=true;
            compare.push_back(1);
        }
    }
    
    
    for(int i=0; i<cards.size(); i++){
        if (cyclic[cards[i]]) continue;
        
        auto cur = cards[i];
        int cnt = 0;
    
        while(!cyclic[cur]){
            
            cyclic[cur] = true;
            cur = cards[cur-1];
            cnt++;
        }
        compare.push_back(cnt);

    }
    
    if (compare.size() < 2) return 0;
    
    sort(compare.begin(), compare.end(), greater<int>());
    answer = compare[0]*compare[1];
    return answer;
}