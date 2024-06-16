#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> getMaxWindowValue(vector<int> vec, int wSize)
{

    vector<int> retvec;
    deque<int> maxq;
    int frontIndex = 0;

    if (wSize > vec.size() | wSize < 1)
    {
        return vector<int>();
    }

    for (size_t i = 0; i < vec.size(); i++)
    {

        if (maxq.empty())
        {
            maxq.push_front(vec[i]);
            frontIndex = i;
            continue;
        }

        if (frontIndex == (i - wSize)) // 队头过期,移除
        {
            maxq.pop_front();
        }       

        while(!maxq.empty()){     //核心逻辑

            if (vec[i] < maxq.back())
            {
                maxq.push_back(vec[i]);
                break;

            } else{
                maxq.pop_back();
                if (maxq.empty())
                {
                    maxq.push_back(vec[i]);
                    frontIndex=i;
                    break;
                }
                continue;
            } 
        }

        if (i >=(wSize-1))
        {
            retvec.push_back(maxq.front());
        }
    }

    return retvec;
}

int main()
{

    vector<int> arr;
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(7);

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);

    auto ret = getMaxWindowValue(arr, 3);
    for (auto &i : ret)
    {
        cout << i << " ";
    }

    return 0;
}