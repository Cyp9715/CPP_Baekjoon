#include <iostream>
#include <vector>
#include <algorithm>

class baekjoon_1912
{
public:
    int n;

    void run()
    {
        // 10
        // 2 1 -4 3 4 -4 6 5 -5 1

        std::cin >> n;
        std::vector<int> m(n);
        std::vector<int> d(n, 0);
        for (int& num : m) 
            std::cin >> num;

        d[0] = m[0]; // 첫번쨰 m 을 d[0] 에 할당.
        int max_sum = d[0]; // max_sum 역시 d[0] 로 초기화.

        // dynamic programming 의 핵심적인 역할을 수행하는 for 문
        for(int i = 1; i < n; ++i)
        {
            // 만약 m[i]가 더 크다면, 새로운 연속 구간을 시작.
            // 만약 d[i-1] + m[i]가 더 크다면, 이전 연속 구간을 계속 유지.
            d[i] = std::max(m[i], d[i-1] + m[i]); // d[i]는 단기적인 최고값을 보유
            max_sum = std::max(max_sum, d[i]); // max_sum 은 최종적인 최고값을 보유
        }
        
        // 위 구문에서 느낄 수 있는 의문점은, 이전누적값(d[i-1]) + 현재값(m[i]) 보다 현재값(m[i]) 가 크가면
        // 새로운 연속구간을 시작하는 로직으로 넘어가는게 타당하냐? 이다.
        // 잘 생각해 보면 이는 모든 경우에서 타당하다는 것을 알 수 있음.

        std::cout << max_sum << std::endl;
    }
};