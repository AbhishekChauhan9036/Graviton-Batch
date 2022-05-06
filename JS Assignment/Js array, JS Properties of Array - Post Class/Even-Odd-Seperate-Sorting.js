// You need to return sorted array, not string
// arr: input array
// arrSize: size of array
function sortEvenOdd(arr, arrSize)
  {
    let n = arrSize;
      // Your code here     
       let l = 0, r = n - 1;
   
        // Count of odd numbers
        let k = 0;
   
        while (l < r)
        {
           
            // Find first even number
            // from left side.
            while (arr[l] % 2 != 0)
            {
                l++;
                k++;
            }
   
            // Find first odd number
            // from right side.
            while (arr[r] % 2 == 0 && l < r)
                r--;
   
            // Swap even number present
            // on left and odd
            // number right.
            if (l < r)
            {
               
                // swap arr[l] arr[r]
                let temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
            }
        }
           
        let odd=new Array(k);
        for(let i=0;i<k;i++)
        {
            odd[i]=arr[i];
        }
        let even=new Array(n-k);
        for(let i=0;i<n-k;i++)
        {
            even[i]=arr[k+i];
        }
        // Sort odd number in descending order
        odd.sort(function(a,b){return b-a;});
        // Sort even number in ascending order
        even.sort(function(a,b){return a-b;});
         
        return odd.concat(even);     
  }