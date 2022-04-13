/**
 *    author:  Abhishek Chauhan
 *    created: 16.03.2022 23:02:18      
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
static boolean isFoldable(Node node)
    {
        boolean res;

        if (node == null)
            return true;
 

        mirror(node.left);
 

        res = isStructSame(node.left, node.right);

        mirror(node.left);
 
        return res;
    }
 
    static boolean isStructSame(Node a, Node b)
    {
        if (a == null && b == null)
            return true;
        if (a != null && b != null
            && isStructSame(a.left, b.left)
            && isStructSame(a.right, b.right))
            return true;
 
        return false;
    }
 

    static void mirror(Node node)
    {
        if (node == null)
            return;
        else {
            Node temp;
 
            mirror(node.left);
            mirror(node.right);
 
           
            temp = node.left;
            node.left = node.right;
            node.right = temp;
        }
    }