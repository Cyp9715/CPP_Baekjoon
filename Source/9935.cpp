#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 문자열이 폭발 문자열을 포함하고 있는 경우 => 모든 폭발 문자열이 폭발하게 된다(남은 문자열을 순서대로 이어 붙여 새 문자열 제작)
// 새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
// 폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다. (연쇄폭발)

// 남아있는 문자열 존재하지 않을경우 "FRULA" 출력
// 폭발 문자열은 같은 문자를 두 개 이상 포함하지 않는다.

class baekjoon_9935 {
    string input;
    string boom;

public:
    /* 흔히 생각할 수 있는 방식으로도 잘 동작하지만
    * 문자열 제한이 1,000,000개 이기 때문에, Time_exceed 문제가 생긴다.
    * 수차례 문자열을 반복하면서 폭탄을 찾기 때문.
    */
    void run_time_exceed() 
    {
        cin >> input >> boom;

        while (true)
        {
            size_t pos = input.find(boom);

            // 문자가 존재한다면, replace
            if (pos != string::npos)
                input.replace(pos, boom.size(), "");
            else
                break;
        }

        if (input == "")
            cout << "FRULA" << endl;
        else
            cout << input << endl;
    }
    
    /* 
    * 반면 Stack 기반으로 해결할 때에는 실질적으로 문자열을 한번만 search 하면 되기에
    * Time_exceed 문제가 발생하지 않는다.
    * 
    * 원리는 stack을 생성하며 폭탄을 발견하는 즉시 해당 문자열을 지워버린다.
    * 이 때 폭탄 발견 Trigger는 boom.back() 문자를 발견할 시, 앞의 문자들을 확인해서
    * 내가 발견한 것이 boom이 맞는지 확인한다.
    * 
    * 만약 boom 이 맞다면 boom 만큼 stack.pop_back()을 수행하여 
    * boom을 stack에서 제거하는 과정을 거친다.
    * 
    * 여기서 아직 모든 문자열을 받은것이 아니기에, 추가적으로 연결된 boom이 들어온다고 해도
    * 위 과정을 거친다면 search 과정을 한번만 거치고 문자열에서 모든 boom을 제거할 수 있다.
    */
    void run()
    {
        cin >> input >> boom;
        vector<char> stack;

        for (char c : input)
        {
            bool isBoom = false;
            stack.push_back(c);

            if (stack.size() >= boom.size() && c == boom.back())
            {
                isBoom = true;
                for (int i = 1; i <= boom.size(); ++i)
                {
                    if (stack[stack.size() - i] != boom[boom.size() - i])
                    {
                        isBoom = false;
                        break;
                    }
                }

                if (isBoom)
                {
                    for (int i = 0; i < boom.size(); ++i)
                    {
                        stack.pop_back();
                    }
                }
            }
        }

        if (stack.empty())
            cout << "FRULA" << endl;
        else
        {
            for (char c : stack)
                cout << c;
        }
    }
};