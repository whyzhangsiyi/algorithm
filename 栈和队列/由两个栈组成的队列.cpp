#include <iostream>
#include <stack>
using namespace std;


class queueByStack
{
private:
    stack<int> inStack;
    stack<int> outStack;

    void move_In_to_Out(){

    while(!inStack.empty()){
        int val =inStack.top();
        inStack.pop();
        outStack.push(val);
    }

    }
public:
void add(int val){

    inStack.push(val);

}

int poll(){
    if (!outStack.empty())
    {
        int val=outStack.top();
        outStack.pop();
        return val ;
    }
    try
    {
        if (inStack.empty())
        {
            throw("empty queue");
        }

        move_In_to_Out();
        int val =outStack.top();
        outStack.pop();
        return val;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
 
}

int peek(){

    if (!outStack.empty())
    {
        return outStack.top();
        
    }
    try
    {
        if (inStack.empty())
        {
            throw("empty queue");
        }

        move_In_to_Out();
        return outStack.top();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

}

};



int main(){

    queueByStack queue;

for (size_t i = 0; i < 200; i++)
{
    queue.add(i);


}

for (size_t i = 0; i < 200; i++)
{
   cout<< queue.poll()<<" ";
}
 
}