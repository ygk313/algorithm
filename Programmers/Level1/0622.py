# 2022 KAKAO BLIND RECRUITMENT > 신고 결과 받기 : https://school.programmers.co.kr/learn/courses/30/lessons/92334

def solution(id_list, report, k):
    answer = []
    
    reported_mbr = dict()
    mail_mbr = dict()
    
#     reportee 정리
    for val in report:
        reporter, reportee = val.split()
        if reportee not in reported_mbr:
            reported_mbr[reportee] = set()
            reported_mbr[reportee].add(reporter)
        else:
            reported_mbr[reportee].add(reporter)
    
#      mail_mbr 초기화
    for id_ in id_list:
        mail_mbr[id_] = 0

    for x,v in reported_mbr.items():
        if len(v) >= k:
            for t in v:
                mail_mbr[t] +=1
    
    for id_ in id_list:
        answer.append(mail_mbr[id_])
    return answer