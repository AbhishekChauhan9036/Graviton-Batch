import java.io.*; // for handling input/output
import java.util.*; // contains Collections framework

// don't change the name of this class
// you can add inner classes if needed
class Main {
	public static void main (String[] args) {
                      // Your code here
        Scanner inputTaker = new Scanner(System.in);
        int n = inputTaker.nextInt();
        int q = inputTaker.nextInt();
        Node[] arr = new Node[n];
        for(int i =0; i <n;i++){
            arr[i] = new Node(0);
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

         for(int i =0; i <q;i++){
            int queryType = inputTaker.nextInt();
            perform(queryType, arr, inputTaker);
        }
	}

    private static void perform(int queryType, Node[] arr, Scanner inputTaker){
        switch(queryType){
            case 1:{
                int nodeValue = inputTaker.nextInt();
                int valueToBeAdded = inputTaker.nextInt();
                addValue(arr[nodeValue - 1], valueToBeAdded);
                break;
            }
            case 2:{
                int nodeValue = inputTaker.nextInt();
                System.out.println(arr[nodeValue - 1].data);
                break;
            }
            default:{}
        }
    }

    private static void addValue(Node root, int value){
        if(root == null){
            return;
        }
        root.data = root.data + value;
        addValue(root.left, value);
        addValue(root.right, value);
    }


}

class Node {

    public int data;
    public Node left;
    public Node right;

    public Node(int data){
        this.data = data;
    }
}