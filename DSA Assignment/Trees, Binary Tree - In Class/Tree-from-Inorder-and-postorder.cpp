/**
 *    author:  Abhishek Chauhan
 *    created: 14.03.2022 21:13:02      
**/


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


void preOrder(Node* node) {
    if (node == NULL) return;

    printf("%d ", node->data);


    preOrder(node->left);


    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int n;
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    return 0;
}

Node *build(int in[], int post[], int s, int e){
   
   if(s>e){
       return NULL;
   }
   
   int index = -1;
   for(int i=e;i>=0;i--){
       for(int j=e;j>=s;j--){
           if(in[j] == post[i]){
               index = j;
               break;
           }
       }
       if(index!=-1){
           break;
       }
   }
   Node* root = new Node(in[index]);
   root->left = build(in, post, s, index-1);
   root->right = build(in, post, index+1, e);
   return root;
}


Node *buildTree(int in[], int post[], int n) {
   return build(in, post, 0, n-1);
}