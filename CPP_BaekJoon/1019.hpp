#include <iostream>
#include <vector>
#include <math.h>
#include <string>

// 검증용
void counting(int N);

// 보정되지 않은 각 숫자별 빈도수를 추출하는 클래스.
class NumberFrequency
{
public:
	std::vector<std::vector<int>> GetFrequency(const std::vector<int>& numbers);

private:
	// F 그 자체는 GetAboveF() + 1 
	long long GetAbove(int F, int B);

	// except for zero
	long long GetUnder(int F, int B);

	long long GetZero(int F, int B);
};


// 각 숫자별 빈도수를 보정하기 위한 클래스.
class NumberCorrect
{
public:
	std::vector<int> GetCorrectFrequency(const std::vector<int>& numbers, const std::vector<std::vector<int>>& frequencies);

public:
	std::vector<int> GetCorrect(const std::vector<int>& numbers, const std::vector<std::vector<int>>& frequencies);

	// 9
	// 108
	// 1107
	// 11106
	// 111105
	long long GetCorrectZero(int F, int B);
};

void Execute();