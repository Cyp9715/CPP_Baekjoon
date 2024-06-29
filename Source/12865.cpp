#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

// 시간초과 발생.
class baekjoon_12865_combination
{
public:
    int N, K{};
    std::vector<std::pair<int, int>> WV;
    std::vector<std::vector<std::pair<int, int>>> combinations;
    std::set<std::vector<std::pair<int, int>>> invalid_combination;

    // 조합을 생성하는 함수
	void make_combination(int n)
	{
		std::vector<bool> selector(WV.size() - n, false);
		selector.resize(WV.size(), true);

		do {
			std::vector<std::pair<int, int>> combination;
            int sum_weight {};

			for (size_t i = 0; i < WV.size(); ++i)
			{
				if (selector[i])
                {
					combination.push_back(WV[i]);

                    if (invalid_combination.find(combination) != invalid_combination.end())
                    {
                        break;
                    }

                    sum_weight += WV[i].first;

                    if(sum_weight > K)
                    {
                        invalid_combination.emplace(combination);
                        break;
                    }
                }
			}

            if (invalid_combination.find(combination) == invalid_combination.end())
            {
                combinations.push_back(combination);
            }

		} while (std::next_permutation(selector.begin(), selector.end()));
	}

    void run()
    {
        std::cin >> N >> K; // 물품의 수 : N, 버틸 수 있는 무게 K
        WV.reserve(N);
        combinations.reserve(N);

        for(int i = 0; i < N; ++i)
        {
            int weight, value;
            std::cin >> weight >> value;
            WV.push_back({weight, value});
        }

        int max_weight{};
        int max_value{};

        for(int i = 1; i <= N; ++i)
        {
            make_combination(i);

            for(auto rows : combinations)
            {
                int sum_value{};

                for(auto values : rows)
                {
                    sum_value += values.second;
                }

                if(sum_value > max_value)
                {
                    max_value = sum_value;
                }
            }
        }

        std::cout << max_value << std::endl;
    }
};


// 이전 답을 활용하는 방식.
class baekjoon_12865 {
public:
    void run() {
        int N, K; // 물품의 수 : N, 버틸 수 있는 무게 K
        std::cin >> N >> K;
        
        std::vector<int> W(N+1), V(N+1); // 물품당 무게와, 값

        for(int i = 1; i <= N; i++) 
        {
            std::cin >> W[i] >> V[i];
        }
        
        std::vector<std::vector<int>> dp(N+1, std::vector<int>(K+1, 0)); // N + K 의 이중벡터
        
        // row : item, column : weight
        for(int i = 1; i <= N; i++) // item
        {
            for(int w = 1; w <= K; w++) // weight
            {
                // 만약 가용가능한 weight가 기록된 이전 개별물품 weight 보다 크다면
                if(W[i] <= w) 
                {  
                    dp[i][w] = std::max(dp[i-1][w], dp[i-1][w-W[i]] + V[i]);
                }
                // 만약 이전 weight가 현재 weight 보다 크다면
                else 
                {
                    // 저장된 이전 weight를 현재 weight 로 장착.
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        
        std::cout << dp[N][K] << std::endl;
    }
};