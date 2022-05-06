function mul(x){
  return function(y){
    return function(z){
      console.log(x*y*z);
    }
  }
}