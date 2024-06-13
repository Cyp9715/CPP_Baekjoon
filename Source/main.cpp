#include <iostream>
#include <vector>

int main()
{
	int T{}, M{}, N{}, K{};
	std::cin >> T;

	std::vector<std::vector<std::pair<int, int>>> K_content;
	std::vector<std::pair<int, int>> MN;

	for (int i = 0; i < T; ++i)
	{
		std::cin >> M >> N >> K;
		MN.push_back(std::pair<int, int>{M, N});

		std::vector<std::pair<int, int>> k_temp;
		for (int j = 0; j < K; ++j)
		{
			int a{}, b{};
			std::cin >> a >> b;
			k_temp.push_back({ a, b });
		}

		K_content.push_back(k_temp);
	}

	std::cout << "test" << std::endl;
}