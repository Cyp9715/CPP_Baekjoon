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

        d[0] = m[0]; // 첫번째 m을 d[0] 에 할당.
        int max_sum = d[0]; // max_sum 역시 d[0] 로 초기화.

        // dynamic programming 의 핵심적인 역할을 수행하는 for 문
        for(int i = 1; i < n; ++i)
        {
            // 만약 m[i]가 더 크다면, 새로운 연속 구간을 시작.
            // 만약 d[i-1] + m[i]가 더 크다면, 이전 연속 구간을 계속 유지.
            d[i] = std::max(m[i], d[i-1] + m[i]); // d[i]는 단기적인 최고값을 보유
            max_sum = std::max(max_sum, d[i]); // max_sum 은 최종적인 최고값을 보유
        }
        
        // 위 구문에서 느낄 수 있는 의문점은, 이전누적값(d[i-1]) + 현재값(m[i]) 보다 현재값(m[i])이 크다면
        // 새로운 연속구간을 시작하는 로직으로 넘어가는게 타당하냐? 이다.
        // 잘 생각해 보면 이는 모든 경우에서 타당하다는 것을 알 수 있음.

        // 만약 [1, -3, 4, 2, -1, 6] 이 입력값이라고 할 때 최대값은 11 이다.
        // d[1] 에는 -2 값이 들어가게 되고,
        // d[2] 를 할당할 시 m[i] = 4, d[i-1] + m[i] = 2 이므로, 4부터 새로운 구간이 시작된다.
        // 따라서 d[i]는 최적값으로 유지됨.

        // 즉 중요한 점은 이전 최적값보다 현재값이 더 크지 않다면, 계속 이어나가도 된다는 사실임.
        // 이 점을 이해하지 못하면 Dynamic Programming 의 원리를 이해하고 있다고 해도 해당 문제는 꽤 어려울 수 있음.

        std::cout << max_sum << std::endl;
    }
};