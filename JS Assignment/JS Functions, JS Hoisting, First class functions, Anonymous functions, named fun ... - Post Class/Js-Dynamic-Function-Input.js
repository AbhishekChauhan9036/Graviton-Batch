function takeMultipleNumbersAndAdd (){
    // write your code here

    // return the output using return keyword
    // do not console.log it
   var sum =0; 
   for(var i=0;i<arguments.length;i++){
     sum += arguments[i];
   }
   return sum;
}