# https://school.programmers.co.kr/learn/courses/30/lessons/17683

def change_ly(m):
    change = {'A#':'H', 'C#':'I', 'D#':'J', 'F#':'K', 'G#':'L'}
    
    for i in change.keys():
        m = m.replace(i,change[i])
    return m

def solution(m, musicinfos):
    answer = []
    infos = []
    
    m = change_ly(m)
        
    for i in range(len(musicinfos)):
        
        x = musicinfos[i]
        ss, ee, n, l = x.split(',')
        l = change_ly(l)
        
        ssh, ssm = map(int, ss.split(":"))
        eeh, eem = map(int, ee.split(":"))
        
        length = ((eeh*60)+eem) - ((ssh*60)+ssm)
        
        if len(l) > length:
            l = l[:length]
        else:
            l = l * (length // len(l) + 1)
        
        infos.append((length, n, l))
        
    for length, n, l in infos:
        if m in l:
            answer.append((n, length))
    
    if answer:
        return sorted(answer, key=lambda x: (x[1]), reverse=True)[0][0]
    else:
        return "(None)"
    
