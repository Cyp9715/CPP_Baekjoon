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

    // 1 부터 n 까지 숫자중 아직 선택되지 않은 숫자를 선택한다.
    for (int i = 1; i <= n; i++)
    {
        // 숫자 i 가 아직 선택되지 않았다면
        if (visited[i] == false)
        {
            visited[i] = true;  // 숫자 i 를 선택했다고 표시
            arr[cnt] = i;       // arr[] 의 cnt 위치헤 숫자 i 를 저장
            dfs(cnt + 1);       // 다음 숫자를 선택하기 위해 재귀적으로 호출
            visited[i] = false; // 현재 선택한 숫자 i 를 선택하지 않았다고 표시, (이러면 다음 순열 생성 시 이 숫자를 다시 사용 가능)
        }
    }
}

void Execute_15649()
{
    cin >> n >> m;
    dfs(0);
}
