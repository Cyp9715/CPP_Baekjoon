#include <iostream>
#include <string>
#include <stack>

using namespace std;

class baekjoon_10799
{
    string input;
public:
    void run() 
    {
        cin >> input;

        int answer = 0;
        stack<char> s;

        for (int i = 0; i < input.length(); i++) 
        {
            if (input[i] == '(')
            {
                s.push('(');
            }
            else 
            {
                s.pop();
                if (input[i - 1] == '(')
                    answer += s.size();
                else 
                    answer += 1;
            }
        }

        cout << answer;
    }
};
