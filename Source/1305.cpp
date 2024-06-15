#include <iostream>
#include <string>
#include <vector>

class baekjoon_1305
{
public:
    int getPI_cyp(std::string& str)
    {
        int len = static_cast<int>(str.length());
        int pre = 0;
        int pos = 1;
        int count = 0;

        while (pos < len)
        {
            if (str[pre] == str[pos])
            {
                ++count;
                ++pre;
                ++pos;
            }
            else
            {
                if (pre > 0 && str[pre - 1] == str[pos])
                {
                    ++pos;
                    continue;
                }

                pre = 0;
                count = 0;
                ++pos;
            }
        }
        return count;
    }


    int getPI_example(std::string& str)
    {
        int len = static_cast<int>(str.length());
        int pre = 0;
        int pos = 1;

        std::vector<int> table;

        table.resize(len);

        int count = 0;

        for (; pos < len; pos++)
        {
            while (pre > 0 && str[pre] != str[pos])
            {
                pre = table[pre - 1];
            }
            if (str[pre] == str[pos])
            {
                table[pos] = ++pre;
            }
        }

        return table[len - 1];
    }

    void run()
    {
        int len;
        std::string str;

        std::cin >> len >> str;
        //cout << len - getPI_cyp(str) << std::endl;
        std::cout << len - getPI_example(str);

    }
};
