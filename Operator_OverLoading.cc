#include <iostream>    
using namespace std;    
class Gun    
{    
   private:    
      int a;    
   public:    
       Gun(): a(8){}    
       void operator ++()
       {     
          a = a+2;     
       }    
       void Print() {     
           cout<<"The Count is: "<<a;     
       }    
};    
int main()    
{    
    Gun obj;    
    ++obj; 
    obj.Print();    
    return 0;    
}    