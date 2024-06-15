#include <iostream>

using namespace std;

class baekjoon_2292
{
public:
    void run()
    {
        unsigned int input;
        unsigned int point = 1;
        unsigned int temp = 6;
        unsigned int result = 1;

        cin >> input;

        while (true)
        {
            if (point >= input)
            {
                break;
            }

            point += temp;
            temp += 6;
            ++result;
        }
        cout << result;
    }

};
