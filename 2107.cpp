#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>


using namespace std;

int main()
{
    deque<int> s;
    while(true)
    {
        string command;
        cin>>command;
        if(command == "exit")
        {
            cout<<"bye"<<endl;
            return 0;
        }
        if(command == "push")
        {
            int N;
            cin>>N;
            s.push_back(N);
            cout<<"ok"<<endl;
        }
        if(command == "pop")
        {
            if(s.size() == 0)
            {
                cout<<"error"<<endl;
                continue;
            }
            cout<<s.back()<<endl;
            s.pop_back();
        }
        if(command == "back")
        {
            if(s.size() == 0)
            {
                cout<<"error"<<endl;
                continue;
            }
            cout<<s.back()<<endl;
        }
        if(command == "size")
        {
            cout<<s.size()<<endl;
        }
        if(command == "clear")
        {
            s.clear();
            cout<<"ok"<<endl;
        }
    }
}
