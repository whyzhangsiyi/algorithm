#include <iostream>
#include <stack>
using namespace std;

class getMinStack
{
private:
    stack<int> dataStack;
    stack<int> minStack;

public:
    void push(int val)
    {
        if (minStack.empty())
        {
            minStack.push(val);
        }
        else
        {
            if (val <= minStack.top())
            {
                minStack.push(val);
            }else{
                minStack.push(minStack.top());
            }
        }
        dataStack.push(val);

    }

    void pop(){
        if (!dataStack.empty())
        {
            dataStack.pop();
            minStack.pop();
        }
        

       
    }

    int top(){
        if (!dataStack.empty())
        {
            return dataStack.top();
        }
        
    }
    int getMin(){

        if (!dataStack.empty())
        {
            return minStack.top();
        }

    }

};

int main()
{

    srand(int(time(0)));
    getMinStack stack;

    for (size_t i = 0; i < 80; i++)
    {
        stack.push(rand()%100);
    }
    


    cout<<"ds.e:"<<"     "<<"ms.e: "<<endl;
    for (size_t i = 0; i < 80; i++)
    {
        cout << stack.top() << "     "<<stack.getMin()<<endl;
        stack.pop();
    }
    

    return 0;
}