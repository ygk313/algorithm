-- Programmers Lv 3. 조건에 맞는 사용자 정보 조회하기.
-- https://school.programmers.co.kr/learn/courses/30/lessons/164670

-- 문자열 처리 부분이 중요함.
-- CONCAT_WS(keyword, field1, field2, ..) - keyword로 field들을 연결
-- SUBSTRING(field1, start, length) - 부분 문자열 뽑아내기.

SELECT USER_ID, NICKNAME, 
        CONCAT_WS(" ", CITY, STREET_ADDRESS1, STREET_ADDRESS2) AS "전체 주소",
        CONCAT_WS("-", SUBSTRING(TLNO, 1, 3), SUBSTRING(TLNO, 4, 4), SUBSTRING(TLNO, 8, 4)) AS "전화번호"
FROM USED_GOODS_USER
WHERE USER_ID IN (SELECT WRITER_ID
                FROM USED_GOODS_BOARD
                GROUP BY WRITER_ID
                HAVING COUNT(*) >= 3)
ORDER BY USER_ID DESC;