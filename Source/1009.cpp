#include <iostream>

using namespace std;

using uint = unsigned int;

class baekjoon_1009
{
public:
    void run()
    {
        uint T, a, b, output;

        cin >> T;

        // 여러개의 개별 문제에 따른 출력이 필요하므로 T만큼 반복.
        for (uint i = 0; i < T; ++i)
        {
            // a, b 가 1 이상이므로 output 은 모든경우에서 1 이상이다.
            output = 1;

            // a와 b를 입력받는다.
            cin >> a >> b;

            // 핵심부분, 입력값은 a^b 형태로 주어진다.
            // 예로 2^5 이라고 할 때 값은 2, 4, 8, 16, 32 가 도출될 것이고
            // 컴퓨터가 10대이니, 최종값은 1의자리수인 2,4,8,6,2 가 도출된다.
            for (uint j = 0; j < b; ++j)
            {
                // 때문에 % 10 으로 나눠 나머지를 output에 추가하며 처리한다.
                output = (output * a) % 10;

                // 이 때 a가 100 미만이기 때문에 무조건 첫 output 에는 한자리수의 수가 들어간다.
                // 때문에 1000 % 10 등이 발생하여 output에 2자리수 이상이 할당될 위험성 자체가 없기에 안전한 코드이다.
            }

            // 하지만 만약 output 자체가 0이라면 a가 10인 것이므로, 10을 출력한다.
            if (output == 0)
            {
                output = 10;
            }

            printf("%d\n", output);
        }
    }
};