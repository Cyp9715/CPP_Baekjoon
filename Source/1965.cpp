#include <iostream>
#include <vector>
#include <algorithm>

class baekjoon_1965
{
public:
    int n;

    void run()
    {
        std::cin >> n;
        std::vector<int> boxes(n);
        std::vector<int> dp(n, 1);
        int max_length = 1;

        for(int& box : boxes)
            std::cin >> box;

        // 8
        // 1 6 2 5 7 3 5 6
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                // 각 상자(i)에 대해, 그 이전 모든 상자(j)를 검사한다.
                if(boxes[i] > boxes[j]) // 만약 현재 상자(i)가 이전상자(j) 보다 크다면, 이전 상자 수열에 현재 상자를 추가할 수 있다.
                {
                    // dp[i]를 (dp[j] + 1)과 비교하여 더 큰 값으로 업데이트
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            max_length = std::max(max_length, dp[i]);
        }

        // 결국 dp에는 연속적으로 할당할 수 있는 상자의 최대값이 들어간다.
        // dp[i]를 할당하는 과정에서도 지속적으로 현재값 기준 최선의값을 구해넣는다.

        std::cout << max_length << std::endl;
    }
};