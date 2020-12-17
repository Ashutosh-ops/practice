#include <iostream>    
using namespace std;    
class Cal {    
    public:    
static int add(int a,int b){      
        return a + b;      
    }      
static int add(int a, int b, int c)      
    {      
        return a + b + c;      
    }      
};     
int main(void) {    
    Cal obj;  
    cout<<obj.add(10, 20)<<endl;      
    cout<<obj.add(12, 20, 23);     
   return 0;    
}  