#include <string>
#include <vector>

using namespace std;
int partition(vector<int>& arr, int p, int r);
void quicksort(vector<int>& temp, int p, int r)
{
    if (p < r)
    {
        int q = partition(temp, p, r);
        quicksort(temp, p, q - 1);
        quicksort(temp, q + 1, r);
    }
}
int partition(vector<int>& arr, int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] < x)
        {
            int temp;
            i += 1;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];//마지막에 피벗을 바꾸어주는 작업을 하지 않았다.
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++)//
    {
        vector<int> temp;
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++)//맞네
        {
            temp.push_back(array[j]);//array
        }
        quicksort(temp, 0, temp.size() - 1);
        int result = commands[i][2];
        answer.push_back(temp[result - 1]);
    }
    return answer;
}