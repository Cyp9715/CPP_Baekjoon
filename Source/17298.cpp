#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
* 경험을 쌓지 않는다면 틀리기 좋은 문제이다.
* 10여분동안 고민해봐도 이중 루프문을 제외하곤 풀이방법이 생각나지 않아서
* 정답지를 보고 comment만 작성한다.
*/

class baekjoon_17298
{
public:
    void run()
    {
        int N;
        cin >> N;

        vector<int> arr(N);
        vector<int> place(N, -1); // 뒤에 큰수가 존재하지 않을경우 -1 로 출력하기 위해 -1 로 초기화.
        stack<int> temp;

        for(int i = 0; i < N; ++i)
            cin >> arr[i]; // arr에 배열 입력
        
        for (int i = 0; i < N; i++)
        {
            // stack에는 arr 숫자들을 삽입함.
            // 해당 stack의 top이 arr[i] 보다 작다면 무한루프 돌리며 check함.
            // 만약 arr[i]가 더 크다면 출력할 place[temp.top()] 변수에 arr[i]를 추가하여 출력할 준비를함.
            while (!temp.empty() && arr[temp.top()] < arr[i])
            {
                place[temp.top()] = arr[i];
                temp.pop();
            }
            // 위와 같은 원리를 사용하면 계속 작아질 때 단 한번만 search 할 수 있다.
            // 계속해서 작아진다면 사실상 -1로 채우면 되고, 그 후에 arr[temp.top()] 보다 큰 수가 나온다면
            // 해당 수로 stack에 담긴것을 하나씩 검토해보면 된다.
            
            // 때문에 스택 temp에는 차례대로 작은값이 들어가게 된다.
            // 그 후에 만약 큰 값이 나타난다면 while()문을 돌려 stack.pop() 하면서arr[i]와 크기를 비교해간다. 

            // 계속 작은값이 temp 스택에 저장되어 있고, 간만에 큰 값이 등장하였으니,
            // 이전에 등장한 값들역시 arr[i] 보다 작을수 있으니 해당값과 비교후, arr[i]가 더 크다면
            // palce[temp.top()] 에 arr[i] 값을 삽입하는 형태로 진행된다.

            temp.push(i); // temp에서 사용하기 위해 index 값을 temp에 삽입한다.
        }

        // 저장된 place[i]를 출력한다.
        for (int i = 0; i < N; i++)
            cout << place[i] << " ";
    }

    // 위의 원리를 보고 자체적으로 구현해본 코드
    void run_test()
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        vector<int> output(N, -1);

        for(int i = 0; i < N; ++i)
            cin >> arr[i];

        stack<int> s;

        for(int i = 0; i < N-1; ++i)
        {
            // 앞에꺼가 더 크면 stack에 push.
            if(arr[i] >= arr[i+1])
            {
                s.push(i);
            }
            // 뒤에꺼가 더 크면 발동.
            else
            {
                // 먼저 i 보다 i+1 이 더 크니 출력값 할당.
                output[i] = arr[i+1];

                // 이제 i+1이 s.top() 보다 더 큰지 check
                // stack에 남아있는것이 더 클경우 while 문이 바로 종료되므로, 무한루프에 빠질 가능성은 없음.
                while(!s.empty() && arr[s.top()] < arr[i+1])
                {
                    output[s.top()] = arr[i+1];
                    s.pop();
                }
            }
        }

        for(auto i : output)
            cout << i << " ";
    }
};