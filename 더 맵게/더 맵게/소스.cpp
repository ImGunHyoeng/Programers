#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> heap;

    for (int i = 0; i < scoville.size(); i++)
    {
        heap.push(scoville[i]);
    }

    while (heap.top() < K)
    {
        int temp = 0;
        temp = heap.top();
        heap.pop();
        temp += heap.top() * 2;
        heap.pop();
        heap.push(temp);

        answer++;
        if (heap.size() == 1)//heap이 작은 경우
            break;
    }
    if (heap.top() < K)
        answer = -1;
    return answer;
}