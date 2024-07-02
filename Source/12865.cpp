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
class baekjoon_12865 
{
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
                    // 현재 아이템을 선택하였을 때의 최대 가치 dp[i-1][j-W[i]] + V[i]를 비교하여 더 큰 값을 dp[i][j] 에 삽입하여 저장한다.
                    dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);

                    // 핵심적인 부분으로
                    // dp[i][j]는 i번째 아이템까지 고려했을때, 무게 제한 j에서 얻을 수 있는 최대 가치를 저장하고 있으므로
                    // dp[i-1][j]는 이전 아이템까지 고려 && j까지의 무게제한이 주어졌을 때의 최대 Value를 저장중.
                    // dp[i-1][j-W[i]]는 이전 아이템까지 고려 && 무게 j-현재아이템(W[i]) 즉, 현재 아이템이 들어갈만한 여유 공간이 
                    // 존재하는 경우의 Value 와 현재 아이템의 Value를 더함.
                    // 
                    // 위 둘을 서로 std::max 함수로 비교하여 dp[i][j]는 현재 보유할 수 있는 최고 Value를 저장할 수 있음.
                }
                // 현재 아이템을 현재 무게 제한내에 삽입할 수 없다면.
                else
                {
                    // 저장된 이전 weight를 현재 weight 로 장착.
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        // 위 알고리즘을 보다 상세하게 설명하자면, Dynamic Programming 기법을 적극 이용하였다.
        // item과 weight별 기록을 dp[][] 에 기록하기 위해 중첩 for 문을 통해 반복하면서 현재 상황(item, weight) 에서 
        // 어떤 아이템이 최적인지 기록한다.
        // 
        // 추후에 만약 j + 3 인 상황에서 이전에 기록한 dp[i-1][j-W[i]]
        // 즉 [이전 아이템까지 고려한 경우][현재 아이템의 무게를 뺀 경우의 Value] 가
        // [이전 아이템까지 고려한 경우][현재 무게제한의 Value] 를 상회한다면
        // dp[i-1][j-W[i]] + V[i] 를 dp[i][j] 에 할당함.
        // 
        // 이러한 방식은 비록 직관적이진 않을지언정 매우 효율적임.
        // 위의 조합 알고리즘의 경우 시간복잡도가 기하급수적으로 늘어지는 반면
        // Dynamic Programming 방식을 사용한다면 매우 낮은 시간복잡도를 지님.
        
        // 최종적으로 아이템과 무게를 제한시키며 dp[][]를 완성 시키는 이유는
        // 그래야만 dp[i-1][j-W[i]] + V[i]를 계산할 수 있기 때문임.
        
        std::cout << dp[N][K] << std::endl;
    }
};