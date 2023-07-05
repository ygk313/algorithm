-- Programmers Lv 3. 없어진 기록 찾기 :https://school.programmers.co.kr/learn/courses/30/lessons/59042
-- Left Outer Join으로 NULL 값 찾기
 
SELECT  O.ANIMAL_ID, O.NAME
FROM ANIMAL_OUTS O LEFT OUTER JOIN ANIMAL_INS I ON O.ANIMAL_ID = I.ANIMAL_ID
WHERE I.ANIMAL_ID IS NULL
ORDER BY O.ANIMAL_ID;