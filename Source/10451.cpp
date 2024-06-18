#include <iostream>
#include <vector>
#include <queue>

class baekjoon_10451_bfs
{
public:
    std::vector<int> permutation;
    std::vector<bool> visited;
    std::vector<int> answer;

    // BFS 방식.
    bool bfs(int start)
    {
        std::queue<int> q;
        int next = permutation[start];

        // 다음 방문지를 방문 했다면 이미 사이클을 반복한것과 같으므로 return false.
        if (visited[next])
        {
            return false;
        }
        else // 방문하지 않았다면, 다음 방문지를 queue 에 추가하여 반복할 준비.
        {
            q.push(next);
        }

        /* 
        * 현재 위치는 방문처리함.
        * 해당 코드구문을 후행 처리하는 이유는 만약 2->2->2->2 와 같이 자체 반복되는 경우
        * 선행적으로 visited[start] = true 처리되어 
        * 다음 방문지 (Queue에 permutation[start]) 추가가 불가능하기때문.
        * 이로 인해 최종적으로 true 를 return 하는것 역시 차단되기에 올바른 답이 나오지 않음.
        */ 
        visited[start] = true; 

        // queue 내부에서 사이클을 이룰때까지 반복.
        while (!q.empty())
        {
            int point = q.front();
            q.pop();

            int next = permutation[point];

            // 만약 next 순열이 start 지점과 같다면 cycle 을 이룬것임. true 반환.
            if (next == start)
            {
                return true;
            }

            // 만약 다음 순열지를 방문하지 않았다면, 계속 이어져 사이클을 이룰 가능성이 있으므로 queue 에 추가.
            if (!visited[next])
            {
                // visited[next] 를 true 로 지정함으로서 연산시간을 절약할 수 있음.
                visited[next] = true;
                q.push(next);
            }
        }

        return false;
    }


    void run()
    {
        int T, N;
        std::cin >> T;

        while (T--)
        {
            std::cin >> N;

            permutation.clear();
            visited.clear();

            permutation.reserve(N+1);
            visited.assign(N+1, false);

            permutation.push_back(0);

            while (N--)
            {
                int temp;
                std::cin >> temp;
                permutation.push_back(temp);
            }

            int count = 0;

            for (int i = 1; i < permutation.size(); ++i)
            {
                // 이미 방문했으면 카운팅되었기에 bfs 돌릴 필요도 없음.
                if (!visited[i] && bfs(i))
                {
                    ++count;
                }
            }

            answer.push_back(count);
        }

        for (int out : answer)
        {
            std::cout << out << std::endl;
        }
    }
};


class baekjoon_10451_dfs
{
public:
    std::vector<int> permutation;
    std::vector<bool> visited;
    std::vector<int> answer;

    int start = 0;

    bool dfs(int point)
    {
        // visited[point] == true 이면 이미 돌린 사이클임.
        // 카운팅 된 사이클이므로 바로 return false.
        if (visited[point])
        {
            return false;
        }

        // 그게 아니라면 visited를 true 로 만듬.
        visited[point] = true;

        // permutation[point] 즉 다음 대상과 start가 같다면
        // 사이클이 형성된것이므로 return true;
        if (permutation[point] == start)
        {
            return true;
        }

        // 해당되는 사항이 없다면 dfs를 통해 사이클 경로를 찾음.
        return (dfs(permutation[point]));
    }


    void run()
    {
        int T, N;
        std::cin >> T;

        while (T--)
        {
            std::cin >> N;

            permutation.clear();
            visited.clear();

            permutation.reserve(N+1);
            permutation.push_back(0);
            visited.assign(N+1, false);

            while (N--)
            {
                int temp;
                std::cin >> temp;
                permutation.push_back(temp);
            }

            int count = 0;

            for (int i = 1; i < permutation.size(); ++i)
            {
                start = i;

                // 이미 방문했으면 카운팅되었기에 dfs 돌릴 필요도 없음.
                if (!visited[i] && dfs(i))
                {
                    ++count;
                }
            }

            answer.push_back(count);
        }

        for (int out : answer)
        {
            std::cout << out << std::endl;
        }
    }
};
