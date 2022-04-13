import java.io.*; // for handling input/output
import java.util.*; // contains Collections framework

// don't change the name of this class
// you can add inner classes if needed
class Main {
	public static void main (String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim());
		int count=0;
		while(t > 0){
			int javab=0;
			int n = Integer.parseInt(br.readLine().trim());
			int arr[]=new int[n];
			String[] str = br.readLine().trim().split(" ");
			for(int i =0;i<n;i++){
				arr[i]=Integer.parseInt(str[i]);
			}
			int k =Integer.parseInt(br.readLine().trim());
			int ans[]=topKFrequent(arr,k);
			count=0;
			for(int i =0;i<k;i++){
				for(int j=0;j<n;j++){
					if(arr[j]==ans[i]){
						count++;
					}
				}
				javab+=count;
				
				count=0;
			}
			System.out.println(javab);
			t--;
        }
    }

	 public static int[] topKFrequent(int[] nums, int k) {
       
         Map<Integer,Integer> map=new HashMap<>();
         List<Integer> list=new ArrayList<>();
         for(int x:nums){
             if(!map.containsKey(x))
                 list.add(x);
             map.put(x,map.getOrDefault(x,0)+1);
         }
        
         Collections.sort(list,new Comparator<Integer>(){
             public int compare(Integer a,Integer b) {
                 return map.get(b)-map.get(a);
             }
      });
        
         int ret[]=new int[k];
         for(int i=0;i<k;i++)
            ret[i]=list.get(i);
        
        return ret;
    }
}