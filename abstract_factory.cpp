
/*
abstract_factory.cpp
in factory design pattern, we create a factory class that is respnsible for creating/provideing 
the objects of required type, based upon business logics or conditions.
this way it prevened repeated use of new and other nitty gritty details of object creation
the client code just needs to call the factory method to get the object of required type.
this is a good practice to use factory design pattern, as it provides a single point of change
if we need to change the way objects are created, we just need to change the factory  

I should use smart pointers instead of raw pointers to avoid memory leaks.
Also, I should use virtual destructors in base classes to ensure proper cleanup of derived classes.
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
virtual ~Pizza()=default;  //virtual destructor as default to ensure proper cleanup of derived classes
 

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


class UsMargherita : public Pizza
{

    public:
    int cost () override //it is optional to use override here, but it is a good practice
    {
        cout<<"cost of US Margherita pizza is 700"<<endl;
        return 700;
    }

};

class UsFarmhouse : public Pizza
{

    public:
    int cost () override
    {
        cout<<"cost of US Farmhouse pizza is 800"<<endl;
        return 800;
    }

};


class UsVeggie : public Pizza
{

    public:
    int cost () override
    {
        cout<<"cost of US Veggie pizza is 600"<<endl;
        return 600;
    }

};  


class Factory
{
    public:
    virtual Pizza* createPizza(PizzaType type) = 0;
    virtual ~Factory() = default; 
   

};  

class IndianPizzaFactory : public Factory
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

class UsPizzaFactory : public Factory
{
     public:
    Pizza * createPizza(PizzaType type) override
    {
        switch(type)
        {
            case PizzaType::Margherita:
                return new UsMargherita();
            case PizzaType::Farmhouse:
                return new UsFarmhouse();
            case PizzaType::Veggie:
                return new UsVeggie();
            default:
                return nullptr;
        }
    }

};


    
int main(){

    int region, pizzachoice;
    char again='y';

    while(again=='y' || again=='Y')
    {
        cout<<"Do you want to order pizza? (y/n): ";
        cin>>again;
        if(again!='y' && again!='Y')
            break;
    
    while(1){        
    cout<<"Enter 1 for Indian Pizza , 2 for USA Pizza"<<endl;
    cin>>region;

    if(region == 1 || region == 2)
        break;
    else
        cout<<"Invalid region choice, please try again."<<endl;

    }

    while (1)
    {
        cout<<"Enter type of pizza you want: 1 for Margherita, 2 for Farmhouse, 3 for Veggie"<<endl;
         cin>>pizzachoice;

        if(pizzachoice >= 1 && pizzachoice <= 3)
             break;
        else
         cout<<"Invalid pizza choice, please try again."<<endl;
    }
    
    


    Factory* factory ;
    if(region == 1)
    {
        factory = new IndianPizzaFactory();
    }
    else if(region == 2)
    {
        factory = new UsPizzaFactory();
    }
    else
    {
        cout<<"Invalid region choice"<<endl;
        return 1;
    }

    Pizza* order ;

    order= factory->createPizza(PizzaType(pizzachoice - 1));   // i should use static_cast<PizzaType>(x) in future for better type safety
    int cost=order->cost();
    delete order;  //cleaning up the dynamically allocated memory
    delete factory; //cleaning up the factory object

    cout<<"Do you want to order pizza? (y/n): ";
    cin>>again;

    }

    /*
    //this code was before i aded user input

    Pizza* order;   
    UsPizzaFactory pf;  //creating on stack, so no need to delete
    order= pf.createPizza(PizzaType::Margherita);
    int x = order->cost();
    delete order;
    order =pf.createPizza(PizzaType::Margherita);
     x = order->cost();
    delete order;
    order = pf.createPizza(PizzaType::Veggie);
     x = order->cost();
    delete order;
    */




    //int x = order->cost();
   // delete order;

    return 0;
}