# Programmers Lv 2. 광물 캐기
# https://school.programmers.co.kr/learn/courses/30/lessons/172927#
# 그리디 문제인데 접근 잘 못 한듯..! 나중에 다시 풀어보깅

answer = 100000
def check(tmp, values):
    table = [[1,1,1], [5, 1, 1], [25, 5, 1]]
    total = 0

    for i in range(len(tmp)):
        tot = 0

        for j in range(3):
            tot += table[tmp[i]][j] * values[i][j]
        total += tot
    return total

def recr(tmp, n, p, values):
    global answer

    if sum(p) == 0 or len(tmp) == n:
        answer = min(answer, check(tmp, values))
        return

    for x in range(3):
        if p[x] == 0: continue
        tmp.append(x)
        p[x]-=1
        recr(tmp,n,p, values)
        r = tmp.pop()
        p[r] +=1

def solution(picks, minerals):

    n = len(minerals)//5
    if len(minerals)%5 != 0: n+=1

    values = []
    v = [0,0,0]

    for i in range(1, len(minerals)+1):
        if minerals[i-1] == "diamond":
            v[0]+=1
        elif minerals[i-1] == "iron":
            v[1]+=1
        else: 
            v[2]+=1
        if i % 5 == 0:
            values.append(v) 
            v = [0,0,0]
    if len(minerals)%5 != 0:
        values.append(v)

    recr([], n, picks, values)
    return answer


# 그리디를 이용해 떠올린 다시 떠올린 풀이
# 피로도가 높은 순서대로 정렬하고 피로도가 낮은 곡괭이 순서대로 쓰기.
# 5의 배수였던게 그리디인 힌트였을 수도!
def solution(picks, minerals):
    answer = 0
    table = [[1,1,1], [5, 1, 1], [25, 5, 1]]
    
    if len(minerals) > sum(picks):
        minerals = minerals[:sum(picks)*5]
    
    minerals_list = []
    x = [0,0,0]
    
    for i in range(1, len(minerals)+1):
        if minerals[i-1] == "diamond": x[0]+=1
        elif minerals[i-1] == "iron": x[1]+=1
        else: x[2] +=1
        
        if i%5 == 0:
            minerals_list.append(x)
            x = [0,0,0]
    if len(minerals)%5 != 0:
        minerals_list.append(x)
    
    minerals_list.sort(key=lambda x: (-x[0], -x[1], -x[2]))
    
    for m in minerals_list:
        d, i, s = m
        
        for p in range(len(picks)):
            
            if p == 0 and picks[p] > 0:
                picks[p] -=1
                answer += d + i + s
                break
            elif p == 1 and picks[p] > 0:
                picks[p] -= 1
                answer += 5*d + i + s
                break
            elif p == 2 and picks[p] > 0:
                picks[p] -=1
                answer += 25*d + 5*i + s
                break
    return answer