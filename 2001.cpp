#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool isPrime(int n)
{
  if(n == 1)
    return false;
  for(int i=2;i*i<=n;i++)
  {
    if(n % i == 0)
      return false;
  }
  
  return true;
}


int main()
{
int count=0;
  while(true)
  {
    int t;
    cin>>t;
    if(t == 0)
      break;
     count+=isPrime(t);
  }
	cout<<count<<endl;
}
