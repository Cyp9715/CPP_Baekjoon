#include <iostream>
#include <vector>
#include <cstdlib>

class baekjoon_14890
{
public:
    int N, L;
    
    bool constraint(const std::vector<int>& line)
    {
        int index_last = line.size();
        int value_before = line[0];
        int point = 0;

        for (int i = 1; i < index_last; ++i)
        {
            int diff = abs(value_before - line[i]);

            if (diff != 0)
            {
                // 다음값과의 차이가 2이상일 경우 false.
                if (diff > 1)
                    return false;

                int temp = 0;

                for (int j = i; j < L+i; ++j)
                {
                    temp += line[j];
                }

                if (temp != (value_before * L))
                {
                    return false;
                }
            }

            value_before = line[i];
        }

        return true;
    }

    void run()
    {
        std::cin >> N >> L;
        std::vector<std::vector<int>> content(N, std::vector<int>(N));

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                std::cin >> content[i][j];
            }
        }

        int count = 0;

        for (int i = 0; i < N; ++i)
        {
            // 행을 확인
            if (constraint(content[i]))
            {
                count++;
            }

            // 임시 열벡터 생성
            std::vector<int> col(N);
            for (int j = 0; j < N; ++j)
            {
                col[j] = content[j][i];
            }

            // 열을 확인
            if (constraint(col))
            {
                count++;
            }
        }

        std::cout << count << std::endl;
    }
};