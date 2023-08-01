-- Programmers Lv 3. 헤비 유저가 소유한 장소
-- https://school.programmers.co.kr/learn/courses/30/lessons/77487
-- GROUP BY와 서브 쿼리를 활용한 문제

SELECT *
FROM PLACES
WHERE HOST_ID IN (SELECT HOST_ID
                 FROM PLACES
                 GROUP BY HOST_ID
                 HAVING COUNT(HOST_ID)>=2)
ORDER BY ID;