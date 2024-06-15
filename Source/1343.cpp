#include <iostream>

class baekjoon_1343
{
public:
    int run()
    {
        std::string input;
        std::cin >> input;

        std::string result;
        int count = 0;

        for (char ch : input)
        {
            if (ch == 'X')
            {
                ++count;
            }
            else if (ch == '.')
            {
                // 짝수가 아닐경우 폴리오미노 제작 불가, 종료.
                if (count % 2 != 0)
                {
                    std::cout << "-1";
                    return -1;
                }

                append_polynomials(result, count);
                result += '.';
                count = 0;
            }
        }

        // 위에서는 '.' 을 트리거로 했는데, 마지막에 'XXX' 가 나올수도 있으므로, 루프 종료시 한번 더 걸러봄.
        if (count % 2 != 0)
        {
            std::cout << "-1";
            return -1;
        }
        append_polynomials(result, count);

        std::cout << result;
        return 0;
    }


private:
    // '.' 을 맞닥뜨리거나, loop 종료시 AAAA, BB 를 출력함.
	void append_polynomials(std::string& result, int count)
	{
		int a = count / 4;
		int b = (count % 4) / 2;

        // A 우선이며
		for (int i = 0; i < a; ++i)
		{
			result.append("AAAA");
		}

        // B 는 A출력 후 짜투리만
		for (int i = 0; i < b; ++i)
		{
			result.append("BB");
		}
	}
};
