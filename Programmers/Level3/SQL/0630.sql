# Programmers Level 3 : 대여기록이 존재하는 자동차 리스트 구하기
# https://school.programmers.co.kr/learn/courses/30/lessons/157341

SELECT DISTINCT A.CAR_ID
FROM CAR_RENTAL_COMPANY_CAR A JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY B ON A.CAR_ID = B.CAR_ID
WHERE A.CAR_TYPE = "세단" AND DATE_FORMAT(B.START_DATE, '%m') = '10'
ORDER BY A.CAR_ID DESC;
