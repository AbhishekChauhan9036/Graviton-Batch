function sum_array(arr) {
// write code here
// use console.log for displaying the output
    let sum = 0;
    for(let i=0; i<arr.length; i++){
        let newarr = arr[i];

        for(let j=0; j<newarr.length; j++){
            sum+= newarr[j];
        }
    }
    console.log(sum);
}