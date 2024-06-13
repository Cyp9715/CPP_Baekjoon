#include <iostream>
#include <vector>

class backjoon_2002
{
public:

	void run()
	{
		int N;
		bool visited[1000] = { false, };
		std::vector<std::string> input;
		std::vector<std::string> output;

		std::cin >> N;
		std::string temp;

		// 입력 로직
		for (int i = 0; i < N; ++i)
		{
			std::cin >> temp;
			input.push_back(temp);
		}

		for (int i = 0; i < N; ++i)
		{
			std::cin >> temp;
			output.push_back(temp);
		}

		// 최종 출력될 count
		int count = 0;

		// index_output 은 output vector 를 뒤에서부터 진입함.
		int index_output = N - 1;

		for (int index_input = N - 1; index_input >= 0; --index_input)
		{
			while (visited[index_output] == true)
			{
				index_output -= 1;
			}

			if (input[index_input] != output[index_output] && visited[index_output] == false)
			{
				++count;

				for (int z = index_output; z >= 0; --z)
				{
					if (input[index_input] == output[z])
					{
						visited[z] = true;
						break;
					}
				}
			}
			else
			{
				visited[index_output] = true;
				index_output -= 1;
			}
		}

		std::cout << count;
	}
};
