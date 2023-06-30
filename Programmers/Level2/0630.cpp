// Level 2 - 배달 https://school.programmers.co.kr/learn/courses/30/lessons/12978
#include <bits/stdc++.h>

using namespace std;

int nums[51] ;
vector<pair<int,int>> v[51];
queue<pair<int, int>> q;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 1;
    fill(nums, nums+51, 500001);
    
   //도로 정보 저장.
    for(auto x: road){
       v[x[0]].push_back({x[1],x[2]});
       v[x[1]].push_back({x[0],x[2]});
    }

    //1번 마을과 연결된 마을 저장.
    for(auto x: v[1]){
        q.push(x);
        nums[x.first] = min(nums[x.first], x.second);
    }
    //1번 마을로부터 타 마을 까지의 거리 저장.
    while (!q.empty()){
        auto l = q.front(); q.pop();
        
        for(auto point: v[l.first]){
            if(point.first == 1) continue;
            if (nums[point.first] < l.second + point.second) continue;
            q.push({point.first, l.second + point.second});
            nums[point.first] = l.second + point.second;
        }
    }
    
    for(int i=2; i<=N; i++){
        if (nums[i] <= K) answer++;
    }
    return answer;
}