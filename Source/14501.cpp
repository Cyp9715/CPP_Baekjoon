#include <iostream>
#define MAX 16

class baekjoon_14501
{
public:

	int N; // 퇴사일
	int Ti[MAX] = {
		0,
	}; // 상담일
	int Pi[MAX] = {
		0,
	}; // 급여
	int arr[MAX] = {
		0,
	}; // 평가 배열

	int max(int a, int b)
	{
		return a > b ? a : b;
	}

	void run()
	{
		// 입력으로 퇴사일자 받음.
		std::cin >> N;

		// 입력으로 상담일, 급여를 받음.
		for (int i = 1; i <= N; i++)
		{
			std::cin >> Ti[i] >> Pi[i];
		}

		int deadline;

		for (int i = N; i > 0; i--)
		{
			// deadline 은 현재날짜(i)와 상담일(Ti[i])을 더함.
			// deadline 은 엄밀히 말해, 오늘 근무를 포함시키고 있지 않음.
			// 위 예제에서 i가 7이고, Ti[i] 가 1일경우 8이 됨.
			deadline = i + Ti[i];
			// 하지만 N + 1 을 통해 퇴사일과 보정되므로 상관없음.
			// 더하여 이런 deadline 특성을 이용해 arr 을 더 잘 이용할 수 있음.

			// 만약 deadline 날짜가 퇴사일을 초과하면 상담이 불가함.
			if (deadline > N + 1)
			{
				// 상담이 불가할 시 행하는 구간.
				// 그냥 뒤에서 계산했던 최고치를 현재위치에 재할당함.
				arr[i] = arr[i + 1];
			}
			else
			{
				// 상담이 가능할 시 행하는 구간.
				// arr[i+1] 은 이전에 계산했던 최고치가 삽입되어 있음. 하지만 만약 그 최고치보다.
				// 오늘 받을 수 있는 급여 + 데드라인 후에 받을 수 있는 최고 급여가 더 크다면 해당 값을 max 로 사용.
				// 만약 상담일(i)이 1 이라면 최고치와, 오늘 급여까지 더해 최고치를 갱신함.
				arr[i] = max(arr[i + 1], arr[deadline] + Pi[i]);

				// 결론적으로 arr[1] 값에는 현재로서 받을 수 있는 최고치가 누적되어 있음.
			}
		}

		std::cout << arr[1] << std::endl;
	}
};
