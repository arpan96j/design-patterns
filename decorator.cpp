#include<iostream>

using namespace std;


class BasePizza
{

public :
virtual int cost()=0;
virtual ~BasePizza()=default;

};

class Margherita : public BasePizza
{
public :
int cost() override
{
     cout<<"This is Margherita Pizza +200"<<endl;
    return 200;
}

};

class Farmhouse : public BasePizza
{

public :

    int cost() override
    {
       
        cout<<"This is Farmhouse Pizza +250"<<endl;
        return 250;
    }

};


class Toppings : public BasePizza
{
 public:
    BasePizza* base;
    Toppings(BasePizza* b): base(b)
    {

    }
    ~Toppings()
    {
        delete(base);
    }

};

class extracheese : public Toppings
{
   
    public:

    extracheese(BasePizza* b) : Toppings(b)
    {
        
    }

    int cost() override
    {   
        cout<<"extracheese added +40"<<endl;
        return base->cost()+ 40;
    }


};

class ExtraVeggies : public Toppings
{

    public:
    ExtraVeggies(BasePizza* b) : Toppings(b){}
    int cost() override
    {
        cout<<"ExtraVeggies added +20"<<endl;
        return base->cost() + 20;
    }
};






int main() {

    Margherita pizza;
    int cost= pizza.cost();
    cout<<"cost is"<<cost<<endl;

    
   // BasePizza* b=new Farmhouse;
    BasePizza* order= new extracheese(new Farmhouse);
    cost=order->cost();
    cout<<"cost is"<<cost<<endl;
    delete(order);



    return 0;
}