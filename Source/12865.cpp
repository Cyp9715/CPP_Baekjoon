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
            for(int j = 1; j <= K; j++) // weight
            {
                // 현재 아이템 W[i]를 현재 무게 제한 j 내에 넣을수 있는지 확인
                if(W[i] <= j)
                {
                    // 현재 아이템을 선택하지 않았을 경우 최대 가치 dp[i-1][j] 와
                    // 현재 아이템을 선택하였을 때의 최대 가치 dp[i-1][j-W[i]] + V[i]를
                    // 비교하여 더 큰 값을 dp[i][j] 에 삽입하여 저장한다.
                    dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
                }
                // 만약 이전 weight가 현재 weight 보다 크다면
                else
                {
                    // 저장된 이전 weight를 현재 weight 로 장착.
                    dp[i][j] = dp[i-1][j];
                }
            }

            // for(auto row : dp)
            // {
            //     for(auto value : row)
            //     {
            //         std::cout << value << " ";
            //     }

            //     std::cout << std::endl;
            // }

            // std::cout << "------------" << std::endl;
        }
        
        std::cout << dp[N][K] << std::endl;
    }
};