#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class baekjoon_17142
{
public:
	int N, M;
	int blank_count{};
	std::vector<std::pair<int, int>> loc_virus; // 바이러스의 위치를 기억할 벡터
	std::vector<std::vector<int>> content;
	int directions[4][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} }; // 동서남북
	const int MAX_INT = 2147483647;

	// 모든 가능한 조합을 저장할 이중 벡터
	std::vector<std::vector<std::pair<int, int>>> combinations;

	// 조합을 생성하는 함수
	void make_combination(int n)
	{
		std::vector<bool> selector(loc_virus.size() - n, false); // loc_virus.size() - n 만큼 false 로 초기화
		selector.resize(loc_virus.size(), true);	// 이후에 selector 를 loc_virus.size() 까지 resize 한 뒤, false 설정되지 않은부분을 true 로 설정.

		do {
			std::vector<std::pair<int, int>> combination; // 임시 조합 변수
			for (size_t i = 0; i < loc_virus.size(); ++i)
			{
				if (selector[i]) // selector[i] 에서 true 로 지정된 변수만
				{
					combination.push_back(loc_virus[i]); // combination 임시변수 할당.
				}
			}
			combinations.push_back(combination); // 최종 저장 변수에 push_back()
		} while (std::next_permutation(selector.begin(), selector.end()));
	}

	// bfs 를 통해서 각 combination 들이 몇 time을 소비하는지 체크해서 반환한다.
	int bfs(std::vector<std::pair<int, int>>& combination)
	{
		std::vector<std::vector<int>> timer(N, std::vector<int>(N, -1)); // 방문 정보와 time 담고있는 vector
		std::queue<std::pair<int, int>> q;	// BFS를 수행하기 위한 queue.
		int remaining_blanks = blank_count;	// 남아있는 빈공간 정보를 체크하기 위한 변수.

		for (auto& i : combination)	// 최초 시작지점을 queue 에 삽입.
		{
			q.push(i);
			timer[i.first][i.second] = 0; // 근원지라는 의미로 0로 시작.
		}

		int time = 0;

		while (!q.empty())
		{
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			for (int i = 0; i < 4; ++i) // 동, 서, 남, 북 진행용.
			{
				int nx = cx + directions[i][0];
				int ny = cy + directions[i][1];

				// 만약 nx, ny가 적절한 범위 내에 존재하면서, 아직 방문하지 않았다면 진입.
				if (nx >= 0 && ny >= 0 && nx < N && ny < N && timer[nx][ny] == -1)
				{
					// content[nx][ny] 가 0 라면
					if (content[nx][ny] == 0)
					{
						--remaining_blanks;
						timer[nx][ny] = ++timer[cx][cy]; // visited[nx][ny]에 visited[cx][cy] 이후의 값 추가.
						q.push({nx, ny});	// bfs 를 계속 진행하기 위해 queue 에 push().
						time = timer[nx][ny];	// timer[nx][ny] 는 현재 timer 수준과 같음.
					}
					else if (content[nx][ny] == 2) // 2일때 remaining_blanks 는 그대로 두고 queue 에 추가만 하는 형식으로 설정.
					{
						timer[nx][ny] = ++timer[cx][cy];
						q.push({nx, ny});
					}
				}
			}
		}

		return remaining_blanks == 0 ? time : -1;
	}

	void run()
	{
		// N : 연구소 크기
		// M : 활성상태로 변경가능한 바이러스의 수
		std::cin >> N >> M;
		content.resize(N, std::vector<int>(N));

		// 0 : 빈칸
		// 1 : 벽
		// 2 : 비활성 바이러스
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				std::cin >> content[i][j];

				if (content[i][j] == 0)
				{
					++blank_count;
				}

				// 추가적인 검색을 막기 위해 virus 위치를 저장해 둔다.
				if (content[i][j] == 2)
				{
					loc_virus.push_back(std::pair<int, int>(i, j));
				}
			}
		}

		// 1초라는 시간에 따라 한칸씩 전진할 수 있으며
		// 연구소를 장악할 수 있는 최소시간을 출력해야 함.
		// 만약 연구소 장악이 불가능한 구조인 경우 -1을 출력해야 함.

		// 이 때 비활성 바이러스는 무시해도 되는듯 함.
		// 기본적으로 BFS 를 통해 진행하되, 무차별대입 방법을 사용해야 할듯 함.

		// make_combination 을 통해 가능한 조합을 생성 -> combinations 변수에 할당.
		make_combination(M);
		int count = MAX_INT;

		// 추후 모든 combinations 중 가장 작은 count 값을 가지는 것을 count 변수에 할당함.
		for (int i = 0; i < combinations.size(); ++i)
		{
			int temp = bfs(combinations[i]);

			if (temp < count && temp != -1)
			{
				count = temp;
			}
		}

		count = count == MAX_INT ? -1 : count;

		// 최종적으로 count 변수를 출력함.
		std::cout << count << std::endl;
	}
};