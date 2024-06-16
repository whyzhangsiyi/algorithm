#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <utility>
using namespace std;

class Pet
{
private:
    string _type;

public:
    Pet(string type)
    {
        this->_type = type;
    }
    string getPetType()
    {
        return _type;
    }
};

class Dog : public Pet
{
private:
    /* data */
public:
    Dog() : Pet("dog") {}
};

class Cat : public Pet
{
private:
    /* data */
public:
    Cat() : Pet("cat") {}
};

class dog_cat_queue
{

private:
    queue<pair<Dog, int>> dogQue;
    queue<pair<Cat, int>> catQue;
    int count;

public:
    dog_cat_queue()
    {
        count = 0;
    }

    void add(Pet &pet)
    {

        if ("cat" == pet.getPetType())
        {
            catQue.push(pair<Cat, int>((Cat)pet, count));
        }

        if ("dog" == pet.getPetType())
        {
            dogQue.push(pair<Pet, int>(pet, count));
        }
        count++;
    }

    Pet pollAll()
    {

        try
        {

            if ((!dogQue.empty()) && (!catQue.empty())) // 两个队列都不为空
            {
                // count越小进入越早,越在头部
                if (catQue.front().second < dogQue.front().second)
                {
                    Pet pet = catQue.front().first;
                    catQue.pop();
                    return pet;
                }
                else
                {

                    Pet pet = dogQue.front().first;
                    dogQue.pop();
                    return pet;
                }
            }
            else if (!dogQue.empty()) // 猫队列空,狗队列不空,直接从狗队列poll
            {
                Pet pet = dogQue.front().first;
                dogQue.pop();
                return pet;
            }
            else if (!catQue.empty()) // 狗队列空,猫队列不空,直接从猫队列poll
            {
                Pet pet = catQue.front().first;
                catQue.pop();
                return pet;
            }
            else
            {
                throw("queue is empty!!!");
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
       

    }






};

