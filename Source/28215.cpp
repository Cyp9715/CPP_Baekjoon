#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class baekjoon_28215
{
    int N, K; // N = ���ǰ���, K = ���Ǽ��� ����
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
            vector<pair<int, int>> exits; // �ӽ� ���Ǽ� ���ս��� ��Ƶ� vector

            for (int i = 0; i < location.size(); ++i)
            {
                // ���ս��� �ش� if ������ �ߵ���.
                if (mask[i] == 1)
                {
                    exits.push_back(location[i]);
                }
            }

            // �� ���ǼҺ��� ���� �� ���� �Ÿ��� ������ ��.
            int max_distance_for_min_distance = 0;

            // �� loop
            for (auto& loc : location)
            {
                int min_distance_for_exit = INT_MAX;
                for (auto& exit : exits) // ���Ǽҵ�� ������ ��� �Ÿ��� ��
                    min_distance_for_exit = min(min_distance_for_exit, get_distance(loc, exit)); // ������ ���� ����� ���Ǽҿ��� �Ÿ��� ������.
                max_distance_for_min_distance = max(min_distance_for_exit, max_distance_for_min_distance); // ���� ���� �� �Ÿ��� ������.
            }

            // ���������� �� ���ǼҺ��� ���� �� ����, ���� ����� ����� result�� ������ ��
            result = min(result, max_distance_for_min_distance);
        } while (next_permutation(mask.begin(), mask.end()));

        return result;
    }

public:
    void run()
    {
        cin >> N >> K;

        // �Է¹ޱ�
        for (int i = 0; i < N; ++i)
        {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            location.push_back({ temp1, temp2 });
        }
        cout << calculate() << endl;
    }
};
