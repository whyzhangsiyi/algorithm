#include <iostream>
#include <stack>
using namespace std;

int getAndRemoveLast(stack<int> &stack)
{

    if (stack.size() == 1)
    {
        int ret = stack.top();
        stack.pop();
        return ret;
    }

    int val = stack.top();
    stack.pop();
    int ret = getAndRemoveLast(stack);
    stack.push(val);
    return ret;
}

void reverse(stack<int> &stack)
{
    int last = getAndRemoveLast(stack);
    if (!stack.empty())
    {
        reverse(stack);
    }
    // 已经getAndRemoveLast到最高层,此时开始压入栈底即是逆序
    stack.push(last);
}

int main()
{
    srand(int(time(0)));
    stack<int> s1;
    stack<int> s2;
    for (size_t i = 0; i < 30; i++)
    {
        int val =rand()%200;
        s1.push(val);
        s2.push(val);
    }

    reverse(s2);
    cout << "S1:"
         << "    "
         << "S2" << endl;

    for (size_t i = 0; i < 30; i++)
    {
        cout << s1.top() << "    "<<s2.top()<<endl;
        s1.pop();
        s2.pop();
    }

    return 0;
}