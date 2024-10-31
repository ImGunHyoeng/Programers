//조건에 맞는 도서와 저자 리스트 출력하기 LV2
SELECT b.BOOK_ID, a.AUTHOR_NAME, DATE_FORMAT(b.PUBLISHED_DATE, '%Y-%m-%d') as PUBLISHED_DATE from BOOK as b, AUTHOR as a where b.AUTHOR_ID = a.AUTHOR_ID and b.CATEGORY = '경제' ORDER BY b.PUBLISHED_DATE ASC;

//있었는데요 없었습니다. LV3
SELECT AIN.ANIMAL_ID, AIN.NAME FROM ANIMAL_INS AS AIN, ANIMAL_OUTS AS AOUT WHERE AIN.ANIMAL_ID = AOUT.ANIMAL_ID AND TIMESTAMPDIFF(SECOND, AIN.DATETIME, AOUT.DATETIME) < 0 ORDER BY AIN.DATETIME ASC;
