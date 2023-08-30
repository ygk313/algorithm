-- Programmers Lv 3. 조회수가 가장 많은 파일 조회하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/164671
-- 문자열 연결에 사용되는 함수: CONCAT

SELECT CONCAT('/home/grep/src/', BOARD_ID,'/', FILE_ID, FILE_NAME,  FILE_EXT) AS FILE_PATH
FROM USED_GOODS_FILE
WHERE BOARD_ID = (SELECT BOARD_ID
                  FROM USED_GOODS_BOARD
                  WHERE VIEWS = (SELECT MAX(VIEWS)
                                 FROM USED_GOODS_BOARD))
ORDER BY FILE_ID DESC;