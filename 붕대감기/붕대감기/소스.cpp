#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// bandage_len은 배열 bandage의 길이입니다.
// attacks_rows는 2차원 배열 attacks의 행 길이, attacks_cols는 2차원 배열 attacks의 열 길이입니다.
int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    int answer = 0;
    int time = attacks[attacks_rows - 1][0];//행과 0의 값이 공격이 마지막으로 일어날때의 기준이 된다.

    int curhealth = health;
    int maxhealth = health;

    int attackcount = attacks_rows;
    int attackCurCount = 0;

    int chainsuccess = bandage[0];
    int successCount = 0;

    for (int i = 0; i <= time; i++)
    {
        if (attacks[attackCurCount][0] == i)//공격
        {
            curhealth -= attacks[attackCurCount][1];
            if (curhealth <= 0)//죽었을 경우
                return -1;
            attackCurCount++;
            successCount = 0;
            continue;
        }

        if ((curhealth + bandage[1]) > maxhealth)//최대값을 넘는 경우 확인
        {
            curhealth = maxhealth;
            //successCount=0;최대 체력을 넘어도 성공횟수가 초기화되지 않는 것을 인지했어야한다.
            //continue;
        }
        else
            curhealth += bandage[1];//회복
        successCount++;

        if (successCount == chainsuccess)
        {
            if ((curhealth + bandage[2]) > maxhealth)
            {
                curhealth = maxhealth;
                successCount = 0;
                continue;
            }
            curhealth += bandage[2];//추가회복
            successCount = 0;
        }

    }
    return curhealth;
}