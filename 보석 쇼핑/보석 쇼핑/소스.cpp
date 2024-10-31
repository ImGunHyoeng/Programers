#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    priority_queue<string> pq;//종류 구분을 위함
    map<string, int> gemsCount;//젬 카운트
    for (int i = 0; i < gems.size(); i++)
    {
        pq.push(gems[i]);
    }
    string temp = pq.top();
    gemsCount.insert({ temp,0 });
    while (!pq.empty())
    {
        if (temp == pq.top())
            pq.pop();
        else
        {
            temp = pq.top();
            gemsCount.insert({ temp,0 });
        }
    }


    //cout<<gemsCount.size();
    int x = gemsCount.size();
    int left = 0, right = 0;
    int count = 0;
    int min = gems.size();
    int resultleft = 0, resultright = gems.size() - 1;
    while (left <= right && left <= gems.size() && right <= gems.size())
    {




        if (count == x)
        {
            //cout<<"right -left"<<right-left<<endl;
            //cout<<"min"<<min<<endl;
            if (right - left < min)
            {
                min = right - left;
                resultright = right - 1;
                resultleft = left;
            }
            //cout<<left+1<<right+1<<'\n';
            //answers.push({left+1,right+1});
            if (left < gems.size())
            {
                gemsCount[gems[left]]--;
                if (gemsCount[gems[left]] == 0)//카운트 개수에 포함안되는 경우
                    count--;
            }
            left++;
        }
        else//구간 증가
        {
            if (right < gems.size())
            {
                gemsCount[gems[right]]++;//1증가 시키기
                if (gemsCount[gems[right]] == 1)//1일 경우에 카운트 증가 시키기
                    count++;
            }
            right++;
        }

    }

    answer.push_back(resultleft + 1);
    answer.push_back(resultright + 1);



    return answer;
}