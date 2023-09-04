// Programmers Lv 2. 우박수열 정적분
// https://school.programmers.co.kr/learn/courses/30/lessons/134239
// 정적분 크기 구하기 - 면적 구하는 것과 동일함. 사다리꼴 크기 구하는 공식: (아랫변 + 윗변)*높이*0.5;

#include <bits/stdc++.h>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<pair<int, int>> nums;
    int n=0;
    
    // 콜라츠 추측
    for(;k!=1;){
        nums.push_back({n++,k});
        if ((k%2)==0) k/=2;
        else{
            k*=3;
            k++;
        }
    }
    nums.push_back({n,1});
    
    // 면적 구하기
    for(auto x: ranges){
        int s = x[0], e = x[1];
        if (e <= 0) e = n + x[1];
        
        if (s > e) answer.push_back(-1.0);
        else{
            double ans = 0;
            for(int i = s; i<e; i++){
                ans += (double)(nums[i].second+nums[i+1].second)/2;
            }
            answer.push_back(ans);
        }
    }
    
    
    return answer;
}