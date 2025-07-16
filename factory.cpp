
/*
factory.cpp
in factory design pattern, we create a factory class that is respnsible for creating/provideing 
the objects of required type, based upon business logics or conditions.
this way it prevened repeated use of new and other nitty gritty details of object creation
the client code just needs to call the factory method to get the object of required type.
this is a good practice to use factory design pattern, as it provides a single point of change
if we need to change the way objects are created, we just need to change the factory  

*/

#include <iostream>
using namespace std;

enum class PizzaType {
    Margherita,
    Farmhouse,
    Veggie,
};



class Pizza
{

public:
virtual int cost()=0;
virtual ~Pizza()=default;  //virtual deconstructor as default to ensure proper cleanup of derived classes
 

};

class Margherita : public Pizza
{

    public:
    int cost () override //it is optional to use override here, but it is a good practice
    {
        cout<<"cost of Margherita pizza is 200"<<endl;
        return 200;
    }

};

class Farmhouse : public Pizza
{

    public:
    int cost () override
    {
        cout<<"cost of Farmhouse pizza is 250"<<endl;
        return 250;
    }

};


class Veggie : public Pizza
{

    public:
    int cost () override
    {
        cout<<"cost of Veggie pizza is 300"<<endl;
        return 300;
    }

};  


class Factory
{
    public:
    virtual Pizza* createPizza(PizzaType type) = 0;
    virtual ~Factory() = default; 
   

};  

class PizzaFactory : public Factory
{
     public:
    Pizza * createPizza(PizzaType type) override
    {
        switch(type)
        {
            case PizzaType::Margherita:
                return new Margherita();
            case PizzaType::Farmhouse:
                return new Farmhouse();
            case PizzaType::Veggie:
                return new Veggie();
            default:
                return nullptr;
        }
    }

};


    
int main(){

    Pizza* order;   
    PizzaFactory pf;  //creating on stack, so no need to delete
    order= pf.createPizza(PizzaType::Farmhouse);
    int x = order->cost();
    delete order;
    order =pf.createPizza(PizzaType::Margherita);
     x = order->cost();
    delete order;
    order = pf.createPizza(PizzaType::Veggie);
     x = order->cost();
    delete order;
    //int x = order->cost();
   // delete order;

    return 0;
}