// Programmers Lv 2. 숫자 카드 나누기
// https://school.programmers.co.kr/learn/courses/30/lessons/135807
// 리스트 내의 모든 수를 나눌 수 있는 가장 큰 수이기 때문에 최대 공약수 활용 문제이다.

#include <bits/stdc++.h>

using namespace std;

int answer = 0;
int gcd_A, gcd_B;

// 리스트의 최대 공약수 구하기
int get_gcd(vector<int>& array){

    int gcd_n = array[0];
    for(int i=1; i<array.size(); i++){
        gcd_n = gcd(gcd_n, array[i]);
    }
    
    return gcd_n;

}
// 조건 확인
void check(vector<int>& array, int gcd_n){
    
    bool flag = false;
    for(auto x: array){
        if (x % gcd_n == 0){
            flag = true;
            break;
        }
    }
    if (!flag) answer = max(answer, gcd_n);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    
    gcd_A = get_gcd(arrayA);
    gcd_B = get_gcd(arrayB);
    
    check(arrayB, gcd_A);
    check(arrayA, gcd_B);
    
    return answer;
}