#include <iostream>
#include <queue>

// 이론상 정점의 개수는 1,000 개 이며 1 < N < 1000 이므로 1001 지정.
// 간선의 개수는 10,000 개 미만임.
// map 을 기준으로 1,000 x 1,000 = 1,000,000 의 간선 지정이 가능.

class backjoon_1260
{
public:
    static constexpr int MAX = 1001;

    int N, M, V; // 정점 개수, 간선 개수, 시작정점
    int map[MAX][MAX]; // 정점간 연결 확인
    bool visited[MAX]; // 정점 방문 여부

    void reset()
    {
        for (int i = 1; i <= N; i++)
        {
            visited[i] = 0;
        }
    }

    // 깊이 우선 탐색 시작
    void DFS(int v)
    {
        // 첫 정점 visited 를 True 로 지정.
        visited[v] = true;
        std::cout << v << " ";

        // [DFS 핵심 로직 시작]
        // map[v][0] 는 자기 자신이므로 1 부터 검색
        // map[v][i] 가 1 이라면 정점과 정점간 '연결된 것'으로 간주.
        for (int i = 1; i <= N; i++)
        {
            // 현재 정점과 연결되어있고 방문되지 않았으면 → 방문처리.
            if (map[v][i] == 1 && visited[i] == 0)
            {
                // 진입하는 순간 재귀적으로 i 가 출력됨.
                // 다시 '방문한 정점' 을 기준으로 깊이 파 내려감
                DFS(i);
                // 계속 연결여부와, visited 를 체크하면서 반복.
            }
        }
    }


    std::queue<int> q;

    // 너비 우선 탐색 시작, 너비 우선 탐색은 재귀적으로 작동하지 않음.
    void BFS(int v)
    {
        // queue 에 시작 정점 정보를 삽입하고, 바로 visited 처리, 출력
        q.push(v);
        visited[v] = true;
        std::cout << v << " ";

        // queue 가 차있다면 계속 while.
        while (!q.empty())
        {
            v = q.front();
            q.pop();

            // 1부터 정점의 개수(N) 까지 반복함. 정점의 개수만큼 출력.
            for (int w = 1; w <= N; w++)
            {
                // 현재 정점과, 연결되어 있으며, 방문하지 않은 정점을 찾을때 까지 반복
                // 만약 없다면 그대로 종료 (연결된 그래프가 아님.)
                if (map[v][w] == 1 && visited[w] == 0)
                {
                    q.push(w);
                    visited[w] = true;
                    std::cout << w << " ";

                    // 이 후에 v 기준 연결된 모든 정점을 찾아 출력함.
                    // v와 연결된 정점들은 queue 에 들어있음.
                    // queue 를 기반으로 다시 반복.
                }
            }
        }
    }

    void run() 
    {
        std::cin >> N >> M >> V;

        // 입력을 받음과 동시에 map 을 설정함.
        // 정점 연결 정보를 map[a][b] 로 바로 접근 가능.
        // 메모리가 소폭 낭비되나, search 를 하지 않아도 되기에 속도면에서 빠름.
        for (int i = 0; i < M; i++)
        {
            int a, b;
            std::cin >> a >> b;
            map[a][b] = 1;
            map[b][a] = 1;
        }

        // reset() 은 visit 정보를 초기화.
        reset();
        DFS(V);

        std::cout << '\n';

        reset();
        BFS(V);
    }
};

