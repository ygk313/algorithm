# 프로그래머스 Lv 2. 바탕화면정리 - https://school.programmers.co.kr/learn/courses/30/lessons/161990
def solution(wallpaper):
    answer = []
    
    sharpX, sharpY = [], []
    
    for i in range(len(wallpaper)):
        for j in range(len(wallpaper[i])):
            if wallpaper[i][j] == '#':
                sharpX.append(i)
                sharpY.append(j)
    
    if len(sharpX) == 1:
        return [sharpX[-1], sharpY[-1], sharpX[-1]+1, sharpY[-1]+1]
    else:
        return [min(sharpX), min(sharpY), max(sharpX)+1, max(sharpY)+1]
    return answer