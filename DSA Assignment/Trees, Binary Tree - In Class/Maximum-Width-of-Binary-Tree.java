/**
 *    author:  Abhishek Chauhan
 *    created: 15.03.2022 20:43:33     
**
**/



/*
// Information about the class Node
class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}
*/


static int getMaxWidth(Node root) {
       // Your code here
       LinkedList<Node> que = new LinkedList<>();
       int width = 0;
       
       que.addLast(root);
       
       while(que.size() != 0 ){
           int size = que.size();
           width = Math.max(width,size);
           
           while(size-- > 0){
               Node rmv = que.removeFirst();
               
               if(rmv.left != null) 
                   que.addLast(rmv.left);
               
               if(rmv.right != null)
                   que.addLast(rmv.right);
           }
       }
       

       return width;
   }