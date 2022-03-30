#include<iostream>
using namespace std;

int main()
{
    string k;
    cin>>k;
    int dd=(k[k.size()-2]-48)*10 + (k[k.size()-1]-48);
    if(dd % 4 == 0)
        cout<<4<<endl;
    else
        cout<<0<<endl;
}
