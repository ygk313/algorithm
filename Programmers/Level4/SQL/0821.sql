-- Programmers Lv 4. 취소되지 않은 진료예약 조회하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/132204
-- 서브 쿼리 활용하거나 JOIN 쓰기.

SELECT APNT_NO, (SELECT PT_NAME
                 FROM PATIENT P
                 WHERE A.PT_NO = P.PT_NO) AS PT_NAME, PT_NO, MCDP_CD, 
                 (SELECT DR_NAME
                  FROM DOCTOR D
                  WHERE A.MDDR_ID = D.DR_ID) AS DR_NAME, APNT_YMD
FROM APPOINTMENT A
WHERE APNT_CNCL_YN = "N" AND DATE_FORMAT(APNT_YMD, '%Y-%m-%d') = "2022-04-13" AND MCDP_CD="CS" 
ORDER BY APNT_YMD;
