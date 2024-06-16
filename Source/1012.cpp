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
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 서, 동, 남, 북
    int M, N, K;

    // 핵심은 bfs를 통해서 visited를 기록하는것.
    // 이를 통해 wormcount를 통제할 수 있음.
    void bfs(int x, int y) 
    {
        std::queue<std::pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;

        while (!q.empty()) 
        {
            x = q.front().first; 
            y = q.front().second;
            q.pop();

            // 서, 동, 남, 북 반복.
            for (int i = 0; i < 4; ++i) 
            {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];

                if (nx >= 0 && nx < M && ny >= 0 && ny < N &&  // nx, ny 가 지정한 범위 내에 존재하며
                    !visited[nx][ny] && field[nx][ny] == 1) // 해당 위치가 visited 가 아니며, 동시에 배추가 존재한다면
                {
                    visited[nx][ny] = true;	// visited로 변경후
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
        while (T--) 
        {
            // 배열 M x N 과 배추개수 K
            std::cin >> M >> N >> K;

            // 반복시 field, visited를 초기화.
            memset(field, 0, sizeof(field));
            memset(visited, 0, sizeof(visited));

            // field 값을 K 만큼 입력받음. field에는 배추 존재 유무가 저장.
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
                    if (field[i][j] && !visited[i][j]) 
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

class baekjoon_1012_dfs
{
public:
    static const int MAX = 50;
    int field[MAX][MAX];
    bool visited[MAX][MAX];
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 북, 남, 서, 동
    int M, N, K;

    // 핵심은 dfs 를 통해서 visited를 기록하는것.
    // 이미 dfs를 진입할 때, visited, field를 체크하기에 별도 체크 X.
    void dfs(int x, int y)
    {
        visited[x][y] = true;

        // 서, 동, 남, 북 반복
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];

            if(nx >= 0 && nx < M && ny >= 0 && ny < N &&  // nx, ny 가 지정한 범위 내에 존재하며
                !visited[nx][ny] && field[nx][ny]) // 해당 위치가 visited 가 아니며, 동시에 배추가 존재한다면
            {
                dfs(nx, ny); // dfs 를 진입 -> 진입한 즉시 해당 영역의 visited 를 true 로 수정.
            }
        }
    }

    void run()
    {
        int T;
        std::cin >> T;

        // T 만큼 반복
        while(T--)
        {
            // 배열 M x N 과 배추개수 K
            std::cin >> M >> N >> K;

            // 반복시 field, visited를 초기화.
            memset(field, 0, sizeof(field));
            memset(visited, 0, sizeof(visited));

            // field 값을 K 만큼 입력받음. field에는 배추 존재 유무가 저장.
            for(int i = 0; i < K; ++i)
            {
                int x, y;
                std::cin >> x >> y;
                field[x][y] = 1;
            }

            int wormCount = 0;

            for(int i = 0; i < M; ++i)
            {
                for(int j = 0; j < N; ++j)
                {
                    // 만약 배추가 존재하며, 방문하지 않았다면 DFS 진입후 wormCount 증가.
                    if(field[i][j] && !visited[i][j])
                    {
                        dfs(i, j);
                        ++wormCount;
                    }
                }
            }
            
            std::cout << wormCount << std::endl;
        }
    }
};