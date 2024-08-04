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
        vector<int> mask(location.size(), 0);
        fill(mask.end() - K, mask.end(), 1);
        int result = INT_MAX;

        do
        {
            vector<pair<int, int>> exits; // 임시 대피소 조합식을 담아둘 vector

            for (int i = 0; i < location.size(); ++i)
            {
                // 조합식은 해당 if 문에서 발동함.
                if (mask[i] == 1)
                {
                    exits.push_back(location[i]);
                }
            }

            // 각 대피소별로 가장 먼 집의 거리를 저장할 곳.
            int max_distance_for_min_distance = 0;

            // 집 loop
            for (auto& loc : location)
            {
                int min_distance_for_exit = INT_MAX;
                for (auto& exit : exits) // 대피소들과 집간의 모든 거리를 비교
                    min_distance_for_exit = min(min_distance_for_exit, get_distance(loc, exit)); // 집별로 가장 가까운 대피소와의 거리를 저장함.
                max_distance_for_min_distance = max(min_distance_for_exit, max_distance_for_min_distance); // 그중 가장 먼 거리를 저장함.
            }

            // 최종적으로 각 대피소별로 가장 먼 집중, 가장 가까운 경우의 result를 저장할 곳
            result = min(result, max_distance_for_min_distance);
        } while (next_permutation(mask.begin(), mask.end()));

        return result;
    }

public:
    void run()
    {
        cin >> N >> K;

        // 입력받기
        for (int i = 0; i < N; ++i)
        {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            location.push_back({ temp1, temp2 });
        }
        cout << calculate() << endl;
    }
};
