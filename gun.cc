#include<bits/stdc++.h>

using namespace std;

int fun(int a, int b, int c = 0)
{
	return (a+b+c);
}

int main()
{
	int a,b,p;
	cin>>a>>b;
	p = fun(a,b,5);
	cout<<p<<endl;
	return 0;
}
