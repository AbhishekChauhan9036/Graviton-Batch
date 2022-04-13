#include <bits/stdc++.h>
using namespace std;
vector<int> kthLargest(int k, int arr[], int n) {
        priority_queue<int , vector<int>,greater<int>> pq;
        vector<int> v;
        for(int i=0;i<k;i++)
        {
            pq.push(arr[i]);
            if(i<k-1)
                v.push_back(-1);
        }
        for(int i=k ; i<n ; i++)
        {
            v.push_back(pq.top());
            if(arr[i]> pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
                
            }
        }
        v.push_back(pq.top());
        return v;
    }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>n>>k;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

    
        vector<int> v = kthLargest(k,arr,n);
		int nop = v.size();
    	cout << v[nop - 1] << endl;
        
    }
    return 0;
}