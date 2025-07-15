/* Strategy Pattern – What It Does
Strategy pattern reduce duplicate code, customize behaviours at run time . 
example : selecting functionaliy as per need, which can be used by object as it own capabliy.

1 Promotes composition over inheritance
2 Allows changing behavior dynamically
3 Makes the code more maintainable, flexible, and testable

*/
#include <iostream>
using namespace std;

//interface , pure virtual function , its child will override drive funtionaity
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


//car is inferface , it hsas pure virtual functiion, hence its object cannot be created
class car {
    
    public:
    drivefun *f;  
    virtual void drive()=0;
    ~car()
    {
        delete(f);
        //need to delete object pointing by this address, else memory leak, since it is not ok stack, but on heap , as it was assigned at runtime.
    }
   
};

class racecar : public car
{
    //int speed;  functionality to be added latter

    public:
    racecar(drivefun* x)
    {
        f= x;
        // this is not a good approach,  i should pass to parent constructor, will do latter
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
    cabcar(drivefun* x) 
    {
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
   
     //dynamically provide functionality of sporty to a racecar. 
    car* c= new racecar(new drivefun_sporty);
    c->drive();


    return 0;
};
