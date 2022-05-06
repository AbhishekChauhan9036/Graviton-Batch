// Your code here
Array.prototype.average = function() {
    var sum = 0;
    for(var i=0; i<this.length; i++){
        sum +=  parseInt(this[i]);
    }
    return sum/this.length;
};