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
        // KOI ������ ������ ��ġ�� ��ġ�� ���Ǽ��� ������ �־��� ��, 
        // ���ǼҸ� ��ġ�ϴ� ��� ��� �� ���� ����� ���Ǽҿ� �� ������ �Ÿ� �� 
        // ���� ū ���� ���� ���� ���� �Ÿ��� ���ض�.

        // �� ��� ��쿡 ������ ���� ����� ���Ǽҿ� �� ������ �Ÿ���, ���� �� ���� ���� ���� �Ÿ�.
        // ������ ���Ǽ� ������ ���϶�.

        // => ���� ������ �ּҰŸ� ���Ǽ� ���ϰ�.
        // �� �� ���� ū���� ã�Ƽ�, �� ���߿��� ������ �ɷ��ߵ�.
        vector<int> mask(location.size(), 0);
        fill(mask.end() - K, mask.end(), 1);

        int max_distance = 0;
        int min_distance = INT_MAX;

        do
        {
            vector<pair<int, int>> exit; // ���Ǽ� ����

            // ���� ������ ���� �� �� ã�ƾߵ�.
            for (auto i = 0; i < location.size(); ++i)
            {
                if (mask[i] == 1)
                {
                    exit.push_back(location[i]); // ���⿡ ���ǼҰ� ����Ǿ�����.
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

        // �Է¹ޱ�
        for (int i = 0; i < N; ++i)
        {
            int temp1, temp2;
            std::cin >> temp1 >> temp2;
            location.push_back({ temp1, temp2 });
        }
        std::cout << calculate() << std::endl;
    }
};