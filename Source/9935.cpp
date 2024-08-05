#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ���ڿ��� ���� ���ڿ��� �����ϰ� �ִ� ��� => ��� ���� ���ڿ��� �����ϰ� �ȴ�(���� ���ڿ��� ������� �̾� �ٿ� �� ���ڿ� ����)
// ���� ���� ���ڿ��� ���� ���ڿ��� ���ԵǾ� ���� ���� �ִ�.
// ������ ���� ���ڿ��� ���ڿ��� ���� ������ ��ӵȴ�. (��������)

// �����ִ� ���ڿ� �������� ������� "FRULA" ���
// ���� ���ڿ��� ���� ���ڸ� �� �� �̻� �������� �ʴ´�.

class baekjoon_9935 {
    string input;
    string boom;

public:
    /* ���� ������ �� �ִ� ������ε� �� ����������
    * ���ڿ� ������ 1,000,000�� �̱� ������, Time_exceed ������ �����.
    * ������ ���ڿ��� �ݺ��ϸ鼭 ��ź�� ã�� ����.
    */
    void run_time_exceed() 
    {
        cin >> input >> boom;

        while (true)
        {
            size_t pos = input.find(boom);

            // ���ڰ� �����Ѵٸ�, replace
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
    * �ݸ� Stack ������� �ذ��� ������ ���������� ���ڿ��� �ѹ��� search �ϸ� �Ǳ⿡
    * Time_exceed ������ �߻����� �ʴ´�.
    * 
    * ������ stack�� �����ϸ� ��ź�� �߰��ϴ� ��� �ش� ���ڿ��� ����������.
    * �� �� ��ź �߰� Trigger�� boom.back() ���ڸ� �߰��� ��, ���� ���ڵ��� Ȯ���ؼ�
    * ���� �߰��� ���� boom�� �´��� Ȯ���Ѵ�.
    * 
    * ���� boom �� �´ٸ� boom ��ŭ stack.pop_back()�� �����Ͽ� 
    * boom�� stack���� �����ϴ� ������ ��ģ��.
    * 
    * ���⼭ ���� ��� ���ڿ��� �������� �ƴϱ⿡, �߰������� ����� boom�� ���´ٰ� �ص�
    * �� ������ ��ģ�ٸ� search ������ �ѹ��� ��ġ�� ���ڿ����� ��� boom�� ������ �� �ִ�.
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