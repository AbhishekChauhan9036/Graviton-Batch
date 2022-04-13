import java.io.*; // for handling input/output
import java.util.*; // contains Collections framework

// don't change the name of this class
// you can add inner classes if needed
class Main {
	public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[]=new int [n+1];
        for(int i=1;i<=n;i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            if(x!=-1){
                arr[i]++;
                arr[x]++;
            }
            if(y!=-1){
                arr[i]++;
                arr[y]++;
            }
        }
        for(int i=2;i<=n;i++){
            if(arr[i]<3){
                System.out.print(i+" ");
            }
        }
	}
}