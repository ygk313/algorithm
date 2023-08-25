// Programmers Lv 2. 할인 행사
// https://school.programmers.co.kr/learn/courses/30/lessons/131127

#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> w;
    for(int i=0; i<number.size(); i++) w[want[i]] = number[i];
    
    for(int i=0; i<discount.size()-9; i++){
        map<string, int> tmp;
        bool flag = true;
        
        for(int j=0; j<10; j++) tmp[discount[i+j]]++;
        for(auto k: want){
            if (w[k] != tmp[k]){
                flag = false;
                break;
            }
        }
        if (flag) answer++;
    }
    return answer;
}