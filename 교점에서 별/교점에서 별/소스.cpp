#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    long long top = -9223372036854775808;
    long long bottom = 9223372036854775807;
    long long left = 9223372036854775807;
    long long right = -9223372036854775808;

    vector<pair<long long, long long>> position;
    for (int i = 0; i < line.size() - 1; i++)
    {
        double A = line[i][0];
        double B = line[i][1];
        double E = line[i][2];

        for (int j = i + 1; j < line.size(); j++)
        {
            double C = line[j][0];
            double D = line[j][1];
            double F = line[j][2];
            long long AD_BC = (A * D) - (B * C);
            double x = ((B * F) - (E * D)) / AD_BC;
            double y = ((E * C) - (A * F)) / AD_BC;

            if (AD_BC == 0)
                continue;
            if (x - (long long)(x) != 0)//x좌표 정수 판정
                continue;

            if (y - (long long)(y) != 0)//y좌표 정수 판정
                continue;
            position.push_back(make_pair(x, y));
            if (top < y)
                top = y;
            if (bottom > y)
                bottom = y;
            if (left > x)
                left = x;
            if (right < x)
                right = x;
        }
    }

    //for (const auto& p : position) {
        //left = min(p.first, left);
        //bottom = min(p.second, bottom);
        //right = max(p.first, right);
      //  top = max(p.second, top);
    //}

    //answer.resize(height, string(width, '.'));

    for (long long y = bottom; y <= top; y++) {
        string tmp = "";
        for (long long x = left; x <= right; x++) {
            tmp += ".";
        }
        answer.push_back(tmp);
    }

    for (long long i = 0; i < position.size(); i++)
    {
        long long x = abs(position[i].first - left);//0,0의 기준이 왼쪽 위쪽이기 때문
        long long y = abs(position[i].second - top);
        answer[y][x] = '*';
    }
    return answer;
}