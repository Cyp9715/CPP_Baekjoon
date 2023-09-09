#include "1019.hpp"

void counting(int N)
{
	long long zero = 0;
	long long one = 0;
	long long two = 0;
	long long three = 0;
	long long four = 0;
	long long five = 0;
	long long six = 0;
	long long seven = 0;
	long long eight = 0;
	long long nine = 0;

	for (int i = 1; i <= N; ++i)
	{
		int temp = i;
		int digit;

		while (temp != 0)
		{
			digit = temp % 10;
			temp = temp / 10;

			switch (digit)
			{
			case 0:
				++zero;
				break;

			case 1:
				++one;
				break;

			case 2:
				++two;
				break;

			case 3:
				++three;
				break;

			case 4:
				++four;
				break;

			case 5:
				++five;
				break;

			case 6:
				++six;
				break;

			case 7:
				++seven;
				break;

			case 8:
				++eight;
				break;

			case 9:
				++nine;
				break;
			}
		}
	}

	printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\r\n", zero, one, two, three, four, five, six, seven, eight, nine);
}


std::vector<std::vector<int>> NumberFrequency::GetFrequency(const std::vector<int>& numbers)
{
	std::vector<std::vector<int>> frequencies;

	for (int i = numbers.size(); i > 0; --i)
	{
		std::vector<int> frequency(10);

		auto t_zero = GetZero(numbers[i - 1], i);
		auto t_above = GetAbove(numbers[i - 1], i);
		auto t_under = GetUnder(numbers[i - 1], i);


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
 
long long NumberFrequency::GetAbove(int F, int B)
{
	if (B <= 1)
	{
		return 0;
	}

	return static_cast<long long>((F * round(pow(10, B - 1))) / 10 * (B - 1));
}

long long NumberFrequency::GetUnder(int F, int B)
{
	if (B <= 1)
	{
		return 1;
	}

	return static_cast<long long>((F + 10) * round(pow(10, B - 2)) + F * round(pow(10, B - 2)) * (B - 2));
}

long long NumberFrequency::GetZero(int F, int B)
{
	if (F == 0)
	{
		return 0;
	}

	return static_cast<long long>((B - 2) * round(pow(10, B - 2)) + (B - 2) -
		(round(pow(10, B - 2)) - 1) / 9 + 1 +
		(F - 1) * (B - 1) * round(pow(10, B - 2)));
}


std::vector<int> NumberCorrect::GetCorrectFrequency(const std::vector<int>& numbers, const std::vector<std::vector<int>>& frequencies)
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


		for (int i = numbers.size() - 2; i > 0; --i)
		{
			correctFrequency_zero += GetCorrectZero(numbers[i], i + 1);
		}

		correctFrequency[0] += correctFrequency_zero;

		return correctFrequency;
	}

std::vector<int> NumberCorrect::GetCorrect(const std::vector<int>& numbers, const std::vector<std::vector<int>>& frequencies)
{
	std::vector<int> correctFrequency(10);

	for (int i = numbers.size() - 1; i >= 0; --i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			correctFrequency[numbers[i]] += numbers[j] * round(pow(10, j));
		}
	}

	return correctFrequency;
}

long long NumberCorrect::GetCorrectZero(int F, int B)
{
	long long result = 0;

	if (F == 0)
	{
		return 0;
	}

	for (int i = 1; i <= B - 1; ++i)
	{
		result += pow(10, i);
	}

	result -= B - 1;
	return result;
}


void Execute()
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