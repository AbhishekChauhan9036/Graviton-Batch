// You need to return the count of Primes less than equal to N
// N: input number

function isPrime(m){
          let answer = true;
    
    if (m <= 1) {
        answer = false;
    }
    else {
        for (let i = 2; i*i <= m; i++) {
            if (m % i === 0) {
                answer = false;
                break;
            }
        }
         return answer;
  }
  return answer;
}

function numberOfPrimes(N)
{
      // Your code here
    var count = 0;
    
    for (let i = 0; i <= N; i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    return count;
}
// console.log(numberOfPrimes(N));