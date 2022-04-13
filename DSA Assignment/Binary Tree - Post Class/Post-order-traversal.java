import java.io.*; // for handling input/output
import java.util.*; // contains Collections framework

// don't change the name of this class
// you can add inner classes if needed
class Node {
    public int data;
    public Node left;
    public Node right;

    public Node(int data){
        this.data = data;
    }
}
class Main {
	public static void main (String[] args) {
                      // Your code here
        Scanner inputTaker = new Scanner(System.in);
        int n = inputTaker.nextInt();
        Node[] arr = new Node[n];
        for(int i =0; i <n;i++){
            arr[i] = new Node(i + 1);
        }
        for(int i = 0;i<n;i++){
            int left = inputTaker.nextInt();
            int right = inputTaker.nextInt();
            if(left != -1){
                arr[i].left = arr[left -1];
            }
            if(right != -1){
                arr[i].right = arr[right - 1];
            }
        }
		Postorder(arr[0]);
	}

	static void Postorder(Node root)
    {
        if (root == null)
            return;
 
        Postorder(root.left);
        Postorder(root.right);
        System.out.print(root.data + " ");
    }
    private static void preOrder(Node root){
        if(root == null){
            return;
        }
        System.out.print(root.data + " ");
        preOrder(root.left);
        preOrder(root.right);
    }

     private static void inOrder(Node root){
        if(root == null){
            return;
        }
        inOrder(root.left);
        System.out.print(root.data + " ");
        inOrder(root.right);
    }
}