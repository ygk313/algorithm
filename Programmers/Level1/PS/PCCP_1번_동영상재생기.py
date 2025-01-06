def calc(time):
    minute, second = map(int, time.split(':'));
    total_time = minute * 60 + second;
    
    return total_time

def solution(video_len, pos, op_start, op_end, commands):
    answer = ''
    
    duration = calc(video_len)
    currentTime = calc(pos)
    opStart = calc(op_start)
    opEnd = calc(op_end)
    
    if (opStart <= currentTime <= opEnd):
        currentTime = opEnd

    for command in commands:
        if (command == "prev") :
            if (0 <= currentTime <= 10) :
                currentTime = 0;
            else:
                currentTime -= 10;
        elif (command == "next"):
            if (duration - 10 <= currentTime <= duration) :
                currentTime = duration
            else:
                currentTime += 10

        if (opStart <= currentTime <= opEnd):
            currentTime = opEnd

    # divmod 활용가능
    minute, second = currentTime // 60, currentTime % 60;
    
    #  f"{minutes:02d}:{seconds:02d}"
    if (0<=minute<10): answer += '0';
    answer += str(minute) + ":"
    if (0<=second<10): answer += '0';
    answer += str(second)
    
    return answer
