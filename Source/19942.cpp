#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class baekjoon_19942
{
public:

    typedef long long ll;
    const int INF = 987654321;
    int n, mp, mf, ms, mv;
    int b, c, d, e, ret = INF, sum;

    struct A
    {
        int mp, mf, ms, mv, cost;
    }a[16];

    map<int, vector<vector<int>>> ret_v;

    void run()
    {
        ios_base::sync_with_stdio(false);

        // n을 입력 받는다.
        cin >> n;

        // mp, mf, ms, mv 는 각 영양성분의 기준점이 되는 녀석들이다.
        cin >> mp >> mf >> ms >> mv;

        // n 개수만큼 mp 에 삽입한다.
        // 이제 배열에는 n 개 만큼의 요소가 존재한다.
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
        }

        // for 문 선언
        // [ << ] 좌측시프트, [ >> ] 우측시프트 이므로
        // 1 << n 만큼 좌측 시프트 하라는 의미 (n 이 10 이라면 1024)
        for (int i = 1; i < (1 << n); i++)
        {
            // 모든값 0 로 초기화
            b = c = d = e = sum = 0;

            vector<int> v;

            // < n 까지 반복
            for (int j = 0; j < n; j++)
            {
                // 1 << j 만큼 좌측 시프트 한것을 i 와 and 연산해서 0가 아니라면,
                if (i & (1 << j))
                {
                    // 위에서 선언한 임시백터 v 에 (j+1) 값을 push_back.
                    v.push_back(j + 1);
                    // 각 값들을 모두 더해 계산함.
                    b += a[j].mp;
                    c += a[j].mf;
                    d += a[j].ms;
                    e += a[j].mv;
                    sum += a[j].cost;
                }
            }

            // 만약 모든 값들이 기준값을 초과한다면,
            if (b >= mp && c >= mf && d >= ms && e >= mv)
            {
                // 만약 sum 값이 ret 값 미만이면. (ret = INF)
                if (ret >= sum)
                {
                    ret = sum;

                    // map 내 인자 vector 에 vector를 push_back;
                    ret_v[ret].push_back(v);
                }
            }
        }

        // 만약 ret 값이 INF 와 같다면 -1 출력하고 종료.
        if (ret == INF) cout << -1 << '\n';

        // 아니라면,
        else
        {
            // 오름차순 정렬 
            sort(ret_v[ret].begin(), ret_v[ret].end());
            cout << ret << "\n";

            // ret_v[ret][0] a 출력후 종료.
            for (int a : ret_v[ret][0])
            {
                cout << a << " ";
            }
        }
    }
};
