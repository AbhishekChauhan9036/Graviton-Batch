#include<bits/stdc++.h>
using namespace std;
int kthSmallest(int arr[], int l, int r, int k) {
        int n=r-l+1;
        sort(arr,arr+n);
        return arr[k-1];
}
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
                int k;
        cin>>k;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}