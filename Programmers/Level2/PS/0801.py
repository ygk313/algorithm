# Programmers Lv 2. 문자열 압축
# https://school.programmers.co.kr/learn/courses/30/lessons/60057

def solution(s):
    answer = len(s)
    
    for i in range(1, len(s)//2 + 1):
        st = []
        idx = 0
        
        while idx + i <= len(s):
            if len(st) == 0:
                st.append([1, s[idx:idx+i]])
            else:
                if st[-1][1] == s[idx:idx+i]:
                    st[-1][0]+=1
                else:
                    st.append([1, s[idx:idx+i]])
            idx += i
        st.append([1, s[idx:]])
        
        string = ""
        for n, x in st:
            if n > 1: string += str(n)+x
            else: string += x
            
        answer = min(answer, len(string))
        
    return answer