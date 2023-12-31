-- Programmers Lv 4.서울에 위치한 식당 목록 출력하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131118
-- 반올림은 ROUND(숫자, 위치)이고 버림은 TRUNCATE(숫자, 위치)이다.

SELECT A.REST_ID, A.REST_NAME, A.FOOD_TYPE, A.FAVORITES, A.ADDRESS, ROUND(AVG(B.REVIEW_SCORE),2) AS SCORE
FROM REST_INFO A
JOIN REST_REVIEW B ON A.REST_ID = B.REST_ID
WHERE A.ADDRESS LIKE '서울%'
GROUP BY B.REST_ID
ORDER BY SCORE DESC, A.FAVORITES DESC