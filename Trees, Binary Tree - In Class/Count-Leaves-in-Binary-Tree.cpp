#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main() {
    int n;
    cin>>n;

   int left=0,right=0,count=0;
    for(int i=0;i<n;i++)    {
        cin>>left;
        cin>>right;
        if(left==-1 && right==-1) count++;
    } 

    cout<<count;
	return 0;
}