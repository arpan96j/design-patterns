#include <iostream>
using namespace std;


/* Strategy Pattern – What It Does
Strategy pattern helps you define a family of behaviors, encapsulate each one, and make them interchangeable at runtime.

✅ Benefits
1 Promotes composition over inheritance
2 Allows changing behavior dynamically
3 Makes the code more maintainable, flexible, and testable

Drive functionalities to use in car

*/

class drivefun
{

    public:
    virtual void drive()=0;
   

};

class drivefun_normal : public drivefun
{

     public : 
    void drive() override
    {
        cout<<"this is a normal drive "<<endl;
    }

};

class drivefun_sporty : public drivefun
{

     public : 
    void drive() override
    {
        cout<<"this is a sporty drive "<<endl;
    }

};

class drivefun_offroad : public drivefun
{

     public : 
    void drive() override
    {
        cout<<"this is a offroad drive "<<endl;
    }

};










class car {
    
    public:
    drivefun *f;  
    virtual void drive()=0;
    ~car()
    {
        delete(f);
    }
   
};

class racecar : public car
{
    //int speed;

    public:
    racecar(drivefun* x) {
        f= x;
    }
    void drive() override
    {
       cout<<"race car says : " ;
       f->drive();
    }

};

class cabcar : public car
{
public:
cabcar(drivefun* x) {
        f= x;
    }
    void drive() override
    {
        cout<<"cabcar says ";
       f->drive();
    }


};




int main()
{
    cout<<"Game Starts"<<endl;
   
 
    car* c= new racecar(new drivefun_sporty);
    c->drive();


    return 0;
};