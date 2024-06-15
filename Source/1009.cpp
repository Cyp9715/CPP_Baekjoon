#include <iostream>

using namespace std;

using uint = unsigned int;

class baekjoon_1009
{
public:
    void run()
    {
        uint nums, a, b, output;

        cin >> nums;

        for (uint i = 0; i < nums; ++i)
        {
            output = 1;

            cin >> a >> b;

            for (uint j = 0; j < b; ++j)
            {
                output = (output * a) % 10;
            }

            if (output == 0)
            {
                output = 10;
            }

            printf("%d\n", output);
        }
    }
};