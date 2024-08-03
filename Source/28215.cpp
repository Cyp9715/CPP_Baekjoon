#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class baekjoon_28215
{
    int N, K; // N = 집의개수, K = 대피소의 개수
    vector<pair<int, int>> location;

    int get_distance(pair<int, int>& a, pair<int, int>& b)
    {
        return abs(a.first - b.first) + abs(a.second - b.second);
    }

    int calculate()
    {
        // KOI 마을의 집들의 위치와 설치할 대피소의 개수가 주어질 때, 
        // 대피소를 설치하는 모든 방법 중 가장 가까운 대피소와 집 사이의 거리 중 
        // 가장 큰 값이 가장 작을 때의 거리를 구해라.

        // 즉 모든 경우에 수에서 가장 가까운 대피소와 집 사이의 거리중, 가장 먼 값이 작을 때의 거리.
        // 최적의 대피소 분포를 구하라.

        // => 조합 돌려서 최소거리 대피소 구하고.
        // 그 중 가장 큰값들 찾아서, 또 그중에서 작은거 걸러야됨.
        vector<int> mask(location.size(), 0);
        fill(mask.end() - K, mask.end(), 1);

        int max_distance = 0;
        int min_distance = INT_MAX;

        do
        {
            vector<pair<int, int>> exit; // 대피소 조합

            // 조합 돌려서 가장 먼 집 찾아야됨.
            for (auto i = 0; i < location.size(); ++i)
            {
                if (mask[i] == 1)
                {
                    exit.push_back(location[i]); // 여기에 대피소가 저장되어있음.
                }
            }

            max_distance = 0;

            for (auto loc : location)
            {
                for (auto ex : exit)
                    min_distance = min(min_distance, get_distance(loc, ex)); 
                max_distance = max(max_distance, min_distance);
            }

            min_distance = min(min_distance, max_distance);

        } while (next_permutation(mask.begin(), mask.end()));

        return min_distance;
    }

public:
    void run()
    {
        std::cin >> N >> K;

        // 입력받기
        for (int i = 0; i < N; ++i)
        {
            int temp1, temp2;
            std::cin >> temp1 >> temp2;
            location.push_back({ temp1, temp2 });
        }
        std::cout << calculate() << std::endl;
    }
};