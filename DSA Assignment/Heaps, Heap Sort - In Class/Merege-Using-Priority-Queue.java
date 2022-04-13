import java.util.*;
class Main{
static void merge(int A[], int B[], int N, int M)
{
	int []res = new int[N + M];
	Queue<Integer> pq = new PriorityQueue<>();
	for(int i = 0; i < N; i++)
		pq.add(A[i]);
	
	for(int i = 0; i < M; i++)
		pq.add(B[i]);
	
	int j = 0;
	

	while (!pq.isEmpty())
	{
		res[j++] = pq.peek();
	
		pq.remove();
	}
	
	for(int i = 0; i < N + M; i++)
		System.out.print(res[i] + " ");
}


public static void main(String[] args)
{
	
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	int m=sc.nextInt();
	int A[]=new int[n];
	int B[]=new int[m];

	for(int i=0;i<n;i++){
		A[i]=sc.nextInt();
	}

	for(int i=0;i<m;i++){
		B[i]=sc.nextInt();
	}
	merge(A, B, n, m);
}
}