# Programmers Lv 2. 후보키
# https://school.programmers.co.kr/learn/courses/30/lessons/42890
# 파이썬을 쓸 때는 파이써닉한 방법을 생각해보기. 
# 유일성과 최소성 확인 시, 최소성에서 주의할 점.
# 04, 014를 비교할 때 04가 들어가 있지만 붙어 있지 않기 때문에 걸러내지 못할 수 있음.

from itertools import combinations

def solution(relation):
    answer = 0
    
    row, col = len(relation), len(relation[0])
    candidates = []
    
    for i in range(1, col+1):
        candidates.extend(combinations([x for x in range(col)], i))
    
    unique = []
    for candidate in candidates:
        temp = [tuple(r[i] for i in candidate) for r in relation]
        
        # 유일성 확인
        if len(set(temp)) == row:
            check = True
            for u in unique:
                # 최소성 확인
                if set(u).issubset(set(candidate)):
                    check = False
                    break
            if check:
                unique.append(candidate)
    answer = len(unique)
    return answer