#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> queue;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++)
    {
        queue.push({ priorities[i],i });
        pq.push(priorities[i]);
    }
    int count = 1;
    while (1)
    {
        pair<int, int> temp = queue.front();
        queue.pop();
        if (pq.top() != temp.first)
        {
            queue.push(temp);
        }
        else//같은경우
        {
            if (temp.second == location)
            {
                answer = count;
                break;
            }

            pq.pop();
            count++;
        }
    }


    return answer;
}