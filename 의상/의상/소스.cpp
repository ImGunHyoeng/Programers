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
            if (sections.count(temp))//맵에 있는 경우 내보내기
                continue;
        }

        vector<string> tempvector;
        for (int j = i; j < clothes.size(); j++)//맵에 처음 들어오는 값 전부 넣기.
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
    divide(clothes);//옷 종류 알아내기

    //한가지 옷만 입을 경우
    for (auto it = sections.begin(); it != sections.end(); ++it)//맵 순회용 it
    {
        vector<string> temp = it->second;
        answer *= temp.size() + 1;//벡터 사이즈 알아내기

    }



    return answer - 1;
}