// (다시 풀어볼 문제) Programmers Lv 2. 멀쩡한 사각형
// https://school.programmers.co.kr/learn/courses/30/lessons/62048?language=cpp#
// N*M 크기의 사각형을 대각선으로 자를 때, 반드시 가로는 N만큼 세로는 M만큼 가야하고 (자를 때 최대 가로가 N이고 세로가 M이기에),
// 가로의 출발점과 세로의 출발점이 같으므로 -1을 해야한다. -> (N+M-1)
// w와 h가 int로 주어졌다는 점도 함정.

#include <bits/stdc++.h>

#define ll long long

using namespace std;

long long solution(int w,int h) {
    ll answer = 1;
    answer = ((ll)w*(ll)h) - ((ll)w+(ll)h-(ll)gcd(w,h));
    
    return answer;
}