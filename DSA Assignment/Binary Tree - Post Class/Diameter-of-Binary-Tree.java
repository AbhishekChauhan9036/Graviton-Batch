/*
// Information about the class Node
class Node {
    int data;
    Node left;
    Node right;
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

*/

 
    static Node root;

    public static int getDiameter(Node root) {
        // Your code here
        // you can create your own helper function
        if (root == null)
            return 0;
 
        int leftHeight = height(root.left);
        int rightHeight = height(root.right);
 
        int leftDiameter = getDiameter(root.left);
        int rightDiameter = getDiameter(root.right);
 
        return Math.max(leftHeight + rightHeight + 1, Math.max(leftDiameter, rightDiameter));
    }
 
    static int getDiameter() {
        return getDiameter(root);
    }

    static int height(Node node) {
        if (node == null)
            return 0;
 
        return (1 + Math.max(height(node.left), height(node.right)));
    }

    //Time Complexity: O(n2)