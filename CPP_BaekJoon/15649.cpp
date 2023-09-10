#include <iostream>
#include "15649.hpp"

#define MAX 9
using namespace std;

int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };

void dfs(int cnt)
{
    /* 
    * cnt == m 일때 출력하는 구문 
    * cnt 가 m 과 같다는것은 한 열에 대한 구문이 이미 arr 에 모두 기재되어있다는 의미. 
    * 예로 [4,4] matrix 라면 4열까지 arr 값이 채워진다면 출력된다.
    */
    if (cnt == m)
    {
        for (int i = 0; i < m; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    /*
    * 재귀함수겸 실질적인 DFS 로직, 
    * 
    * visited 변수는 visited 되었는지 확인함.
    * arr[cnt] 는 i 값을 할당함.
    * dfs 는 재귀함수로직.
    */

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            arr[cnt] = i;
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

void Execute_15649()
{
    cin >> n >> m;
    dfs(0);
}
