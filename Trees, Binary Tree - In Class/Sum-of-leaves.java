/**
 *    author:  Abhishek Chauhan
 *    created: 14.03.2022 22:53:11      
**
**/

/*
 class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
*/

 public static int sumOfLeaf(Node root)
   {
       // your code here
       if(root == null) return 0;
       int sum = 0;
       if(root.left == null && root.right == null)
           sum += root.data;
       sum += sumOfLeaf(root.left);
       sum += sumOfLeaf(root.right);
       
       return sum;
   }