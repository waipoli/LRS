#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int P=a/b;
    int R=a % b;
    if(R < 0)
    {
        R+=abs(b);
        if(b*a < 0)
            P--;
        else
            P++;
    }
    cout<<P<<" "<<R<<endl;
}
