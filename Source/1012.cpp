#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

class baekjoon_1012_bfs
{
public:
    static const int MAX = 50;
    int field[MAX][MAX];
    bool visited[MAX][MAX];
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 북, 남, 서, 동
    int M, N, K;

    void bfs(int x, int y) 
    {
        std::queue<std::pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;

        while (!q.empty()) 
        {
            int cx = q.front().first; // x 좌표를 cx 할당.
            int cy = q.front().second; // y 좌표를 cy 할당.
            q.pop();

            for (int i = 0; i < 4; ++i) // 북, 남, 서, 동 반복.
            {
                int nx = cx + directions[i][0];
                int ny = cy + directions[i][1];

                if (nx >= 0 && nx < M && ny >= 0 && ny < N &&  // nx, ny 가 지정한 범위 내에 존재하며
                    !visited[nx][ny] && field[nx][ny] == 1) // 해당 위치가 visited 가 아니며, 동시에 배추가 존재한다면
                {
                    visited[nx][ny] = true;	// visited 로 변경후
                    q.push({nx, ny});	// 계속 반복을 위해 queue 에 삽입.
                }
            }
        }
    }

    void run()
    {
        int T;
        std::cin >> T;

        // T 만큼 반복
        while (T--) {
            std::cin >> M >> N >> K;

            // 반복시 field, visited 를 초기화.
            memset(field, 0, sizeof(field));
            memset(visited, 0, sizeof(visited));

            // Field 값을 K 만큼 입력받음. Field 에는 배추 존재 유무값이 저장.
            for (int i = 0; i < K; ++i) 
            {
                int x, y;
                std::cin >> x >> y;
                field[x][y] = 1;
            }

            int wormCount = 0;

            for (int i = 0; i < M; ++i) 
            {
                for (int j = 0; j < N; ++j) 
                {
                    // 만약 배추가 존재하며, 방문하지 않았다면 BFS 진입후 wormCount 증가.
                    if (field[i][j] == 1 && !visited[i][j]) 
                    {
                        bfs(i, j);
                        ++wormCount;
                    }
                }
            }
            
            std::cout << wormCount << std::endl;
        }
    }
};