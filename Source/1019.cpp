#include <iostream>
#include <vector>
#include <cmath>
#include <string>

// 보정되지 않은 각 숫자별 빈도수를 추출하는 클래스.

class baekjoon_1019
{
public:

    class NumberFrequency
    {
    public:
        std::vector<std::vector<int>> GetFrequency(const std::vector<int>& numbers)
        {
            std::vector<std::vector<int>> frequencies;

            for (int i = static_cast<int>(numbers.size()); i > 0; --i)
            {
                std::vector<int> frequency(10);

                int t_zero = GetZero(numbers[i - 1], i);
                int t_above = GetAbove(numbers[i - 1], i);
                int t_under = GetUnder(numbers[i - 1], i);

                // number[i-1]보다 큰 인덱스에 t_above를 더하기
                for (int j = numbers[i - 1] + 1; j <= 9; j++) {
                    frequency[j] = t_above;
                }

                // 같은 인덱스에 t_above + 1 만큼 더하기
                frequency[numbers[i - 1]] = t_above + 1;

                // number[i-1]보다 작은 인덱스에 t_under를 더하기
                for (int j = 1; j < numbers[i - 1]; j++) {
                    frequency[j] = t_under;
                }

                // frequency[0] 에 t_zero 만큼 더하기
                frequency[0] = t_zero;

                frequencies.push_back(frequency);
            }

            return frequencies;
        }

    private:
        // F 그 자체는 GetAboveF() + 1 
        int GetAbove(int F, int B)
        {
            if (B <= 1)
            {
                return 0;
            }

            return (F * static_cast<int>(round(pow(10, B - 1)))) / 10 * (B - 1);
        }

        // except for zero
        int GetUnder(int F, int B)
        {
            if (B <= 1)
            {
                return 1;
            }

            return (F + 10) * static_cast<int>(round(pow(10, B - 2))) + F * static_cast<int>(round(pow(10, B - 2))) * (B - 2);
        }

        int GetZero(int F, int B)
        {
            if (F == 0)
            {
                return 0;
            }

            return (B - 2) * static_cast<int>(round(pow(10, B - 2))) + (B - 2) -
                (static_cast<int>(round(pow(10, B - 2))) - 1) / 9 + 1 +
                (F - 1) * (B - 1) * static_cast<int>(round(pow(10, B - 2)));
        }
    };

    // 각 숫자별 빈도수를 보정하기 위한 클래스.
    class NumberCorrect
    {
    public:
        std::vector<int> GetCorrectFrequency(const std::vector<int>& numbers, const std::vector<std::vector<int>>& frequencies)
        {
            std::vector<int> correctFrequency(10);

            int correctFrequency_zero = 0;
            auto correctFrequency_other = GetCorrect(numbers, frequencies);

            for (int i = 0; i < frequencies.size(); ++i)
            {
                for (int j = 0; j < 10; ++j)
                {
                    correctFrequency[j] += frequencies[i][j];
                }
            }

            for (int i = 0; i < 10; ++i)
            {
                correctFrequency[i] += correctFrequency_other[i];
            }

            for (int i = static_cast<int>(numbers.size()) - 2; i > 0; --i)
            {
                correctFrequency_zero += GetCorrectZero(numbers[i], i + 1);
            }

            correctFrequency[0] += correctFrequency_zero;

            return correctFrequency;
        }

    public:
        std::vector<int> GetCorrect(const std::vector<int>& numbers, const std::vector<std::vector<int>>& frequencies)
        {
            std::vector<int> correctFrequency(10);

            for (int i = static_cast<int>(numbers.size()) - 1; i >= 0; --i)
            {
                for (int j = i - 1; j >= 0; --j)
                {
                    correctFrequency[numbers[i]] += numbers[j] * static_cast<int>(round(pow(10, j)));
                }
            }

            return correctFrequency;
        }

        int GetCorrectZero(int F, int B)
        {
            int result = 0;

            if (F == 0)
            {
                return 0;
            }

            for (int i = 1; i <= B - 1; ++i)
            {
                result += static_cast<int>(pow(10, i));
            }

            result -= B - 1;
            return result;
        }
    };

    void run()
    {
        int N;
        std::vector<int> number;
        std::vector<std::vector<int>> frequencies;

        NumberFrequency nf;
        NumberCorrect nc;

        std::cin >> N;

        while (N != 0)
        {
            number.push_back(N % 10);
            N /= 10;
        }

        frequencies = nf.GetFrequency(number);
        auto totalFrequency = nc.GetCorrectFrequency(number, frequencies);

        printf("%d %d %d %d %d %d %d %d %d %d", totalFrequency[0], totalFrequency[1], totalFrequency[2], totalFrequency[3], totalFrequency[4],
            totalFrequency[5], totalFrequency[6], totalFrequency[7], totalFrequency[8], totalFrequency[9]);
    }
};
