#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// bandage_len�� �迭 bandage�� �����Դϴ�.
// attacks_rows�� 2���� �迭 attacks�� �� ����, attacks_cols�� 2���� �迭 attacks�� �� �����Դϴ�.
int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    int answer = 0;
    int time = attacks[attacks_rows - 1][0];//��� 0�� ���� ������ ���������� �Ͼ���� ������ �ȴ�.

    int curhealth = health;
    int maxhealth = health;

    int attackcount = attacks_rows;
    int attackCurCount = 0;

    int chainsuccess = bandage[0];
    int successCount = 0;

    for (int i = 0; i <= time; i++)
    {
        if (attacks[attackCurCount][0] == i)//����
        {
            curhealth -= attacks[attackCurCount][1];
            if (curhealth <= 0)//�׾��� ���
                return -1;
            attackCurCount++;
            successCount = 0;
            continue;
        }

        if ((curhealth + bandage[1]) > maxhealth)//�ִ밪�� �Ѵ� ��� Ȯ��
        {
            curhealth = maxhealth;
            //successCount=0;�ִ� ü���� �Ѿ ����Ƚ���� �ʱ�ȭ���� �ʴ� ���� �����߾���Ѵ�.
            //continue;
        }
        else
            curhealth += bandage[1];//ȸ��
        successCount++;

        if (successCount == chainsuccess)
        {
            if ((curhealth + bandage[2]) > maxhealth)
            {
                curhealth = maxhealth;
                successCount = 0;
                continue;
            }
            curhealth += bandage[2];//�߰�ȸ��
            successCount = 0;
        }

    }
    return curhealth;
}