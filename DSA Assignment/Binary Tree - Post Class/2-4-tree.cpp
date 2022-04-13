#include<bits/stdc++.h>
using namespace std;
 
vector<long long> TreePath (long long N) {
    vector<long long> layer(40); 

    layer[1] = 1;
    long long prev = 1;

    for(int i = 2; i < 39; ++i) {
        if(i & 1) {
            layer[i] = prev * 4;  
        }
        else {
            layer[i] = prev * 2;
        }

        prev = layer[i];
        layer[i] += layer[i - 1];
    }

    int level = 1;

    while(N > layer[level]) {
        ++level;
    }

    vector<long long> ord;
    ord.push_back(N);

    --level;
    long long curr_pos = N - layer[level];

    while(level > 0) {
        long long parent;

        if(level & 1) {
            parent = (curr_pos + 1) / 2;
        }
        else {
            parent = (curr_pos + 3) / 4;
        }

        --level;

        long long node = layer[level] + parent;
        ord.push_back(node);

        curr_pos = parent;
    }

    reverse(ord.begin(), ord.end());

    return ord;
}
 
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long N;
    cin >> N;
 
    vector<long long> out_;
    out_ = TreePath(N);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
        cout << " " << out_[i_out_];
    }
}