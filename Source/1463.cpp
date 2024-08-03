#include <iostream>
#include <vector>
#include <algorithm>

class baekjoon_1463
{
public:
    int x;

    void run()
    {
        std::cin >> x;
        std::vector<int> dp(x + 1, 0);

        // 큰 수로부터 나누거나 빼서 1로 만들어야된다는 고정관념을 버려야 한다.
        // 반대로 1부터 x까지 bottom-up 방식으로 최적의 경우의 수를 dp vector에 저장하는 방식이다.
        for (int i = 2; i <= x; ++i)
        {
            // 우선 최악의 효율을 보여주는 '+1' 이 진행되는것으로 가정한다.
            // 뒤에 +1 은 -1 연산이 아닌, 연산 횟수이다. '+1' 연산은 해당 for문에서 증가되는 i를 통해 진행된다.
            dp[i] = dp[i - 1] + 1;

            // 2로 나눠지는지 체크한다.
            if (i % 2 == 0)
            {
                // dp[i / 2]는 이미 i / 2라는 숫자를 1로 만드는 데 필요한 최소 연산 횟수를 저장중.
                // i는 2로 확정적으로 나눠지기에, dp[i-1] + 1(이전거에서 +1 연산횟수) vs dp[i / 2] + 1 중 어떤것이 더 연산횟수가 적은지 
                dp[i] = std::min(dp[i], dp[i / 2] + 1);
                // 가장 작은 것을 dp[i]에 삽입
            }

            if (i % 3 == 0)
            {
                dp[i] = std::min(dp[i], dp[i / 3] + 1);
            }
        }

        std::cout << dp[x] << std::endl;
    }
};