/*
4:02 AM
Observer design pattern
It is used to notify those observers which have registered in observable object.
Example Weather update

my observations : 
1. I should delete the observers because they are dynamically allocated.
2. name of classes call me more specific
3.  instead of all member public, i can make private following:
->list of observer pointers
->temperature
->update method
because these are used internally, hence  a better pratice
4. I should also implement unregistration ,So, vector will take more time i.e O(n) , hence i can use set/unorganised set instead.

*/


#include <iostream>
#include <vector>

using namespace std ;

class observer
{
public:
virtual void notify(double temp)=0;

};

class tvobserver : public observer
{

public:
void notify(double temp)
{
    cout<<"TV Displays updated temperrature as "<<temp<<"degree Celcius"<<endl;
}


};

class mobileobserver : public observer
{

public:
void notify(double temp)
{
    cout<<"Mobile Displays updated temperrature as "<<temp<<"degree Celcius"<<endl;
}


};



//observerbale let a a weather office
class observable
{

public:
vector<observer*> observers;
double temperature;
void set_temperature(double x)
{
    temperature=x;
    update();
}

void update()
{

    for(observer* obj : observers)
    {
        obj->notify(temperature);
    }

}

void registration(observer* obs)
{
observers.push_back(obs);
}



};


int main()
{
    observable mainstation;
    observer* tv= new tvobserver;
    observer* mobile= new mobileobserver;
    mainstation.registration(tv);
    mainstation.registration(mobile);
    mainstation.set_temperature(45);

    return 0;
}