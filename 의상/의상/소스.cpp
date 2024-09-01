#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, vector<string>> sections;
vector<vector<int>> ClothSet;
void divide(vector<vector<string>> clothes)
{
    for (int i = 0; i < clothes.size(); i++)
    {
        string temp;
        temp = clothes[i][1];
        if (i != 0)
        {
            if (sections.count(temp))//�ʿ� �ִ� ��� ��������
                continue;
        }

        vector<string> tempvector;
        for (int j = i; j < clothes.size(); j++)//�ʿ� ó�� ������ �� ���� �ֱ�.
        {
            if (temp != clothes[j][1])
                continue;
            tempvector.push_back(temp);
        }
        sections.insert(make_pair(temp, tempvector));
    }
}

void GenerateClothSets(vector<int>v, vector<bool> visited, int size)
{
    if (v.size() == size)
    {
        ClothSet.push_back(v);
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        vector<bool> newB = visited;
        vector<int> newV = v;
        newV.push_back(i);
        GenerateClothSets(newV, newB, size);
    }
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    divide(clothes);//�� ���� �˾Ƴ���

    //�Ѱ��� �ʸ� ���� ���
    for (auto it = sections.begin(); it != sections.end(); ++it)//�� ��ȸ�� it
    {
        vector<string> temp = it->second;
        answer *= temp.size() + 1;//���� ������ �˾Ƴ���

    }



    return answer - 1;
}