#include <iostream>
#include <vector>
#include <cstdlib>

class baekjoon_14890
{
public:
    int N, L;
    
    bool constraint(const std::vector<int>& line)
    {
        int value_before = line[0];
        int limitPoint = 0;

        for (int i = 1; i < line.size(); ++i)
        {
            // diff 는 이전값과 현재값의 차이를 지님.
            int diff = value_before - line[i];

            // 만약 차이가 없다면 검증할것이 없음. continue.
            if (diff == 0)
                continue;

            // 이전값과 현재값과의 차이가 2 이상일 경우 false
            if (abs(diff) >= 2)
                return false;

            // 현재값이 이전 값보다 1 작을 경우.
            if(diff == 1)
            { 
                // 경사로가 지정된 범위 내에 존재하는지 확인.
                if(i + L > line.size())
                    return false;

                // 경사로 limitPoint를 지정함.
                if(i + L * 2 > line.size())
                    limitPoint = line.size();
                else
                    limitPoint = i + L * 2;

                // 경사로 point가 line과 같거나 크면 false, 겹치는것임.
                for (int j = i; j < limitPoint; ++j)
                {
                    if(line[j] > line[i])
                        return false;
                }

                // 경사로가 여유 공간을 확보하고 있는지 확인.
                for (int j = i; j < i + L; ++j)
                {
                    if(line[j] < line[i])
                        return false;
                }
            }
            // 현재값이 이전 값보다 1 클 경우.
            else if(diff == -1)
            {
                // 경사로가 지정된 범위 내에 존재하는지 확인.
                if(i - L < 0)
                    return false;

                // 경사로가 여유 공간을 확보하고 있는지 확인.
                for (int j = i-1; j >= i - L; --j)
                {
                    if (line[j] != line[i] - 1)
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
                count++;

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