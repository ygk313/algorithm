# Programmers Lv 2. 수식 최대화
# https://school.programmers.co.kr/learn/courses/30/lessons/67257

from itertools import permutations
import copy

def solution(expression):
    answer = 0
    
    # 1. 존재하는 연산자 찾기     
    operator = []
    if '*' in expression: 
        operator.append('*')
    if '+' in expression: 
        operator.append('+')
    if '-' in expression: 
        operator.append('-')
        
    # 2. 파싱하기  
    exp = []
    nums = ""
    for i in expression:
        if i in operator:
            exp.append(int(nums))
            exp.append(i)
            nums = ""
        else:
            nums += i
    if len(nums) != 0:
        exp.append(int(nums))
    
    # 3. 경우의 수에 따른 계산 실행   
    for x in permutations(operator):
        tmp = copy.deepcopy(exp)
        for op in x:
            idx = 0
            s = []
            
            while idx < len(tmp):
                if tmp[idx] == op:
                    idx+=1
                    if op == '+':
                        tot = s.pop() + tmp[idx]
                    elif op == '-':
                        tot = s.pop() - tmp[idx]
                    else:
                        tot = s.pop() * tmp[idx]
                    s.append(tot)
                else:
                    s.append(tmp[idx])
                idx+=1
        
            tmp = copy.deepcopy(s)
        answer = max(answer, abs(s[0]))
        
    return answer