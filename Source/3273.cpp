#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class backjoon_3273
{
public:

    void run()
    {
        int nums, standard;
        vector<int> v_arr;
        int cnt = 0;

        cin >> nums;
        int temp;

        for (int i = 0; i < nums; i++)
        {
            v_arr.push_back(temp);
        }

        cin >> standard;
        sort(v_arr.begin(), v_arr.end());

        int start = 0;
        int end = static_cast<int>(v_arr.size()) - 1;

        while (true)
        {
            if (start >= end)
                break;

            int sum = v_arr.at(start) + v_arr.at(end);

            if (sum == standard)
            {
                ++cnt;
                --end;
                ++start;
            }
            else if (sum > standard)
            {
                --end;
            }
            else
            {
                ++start;
            }
        }

        std::cout << cnt;
    }

};
