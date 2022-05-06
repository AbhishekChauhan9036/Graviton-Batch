// You need to return Compound Interest
// P: principal value
// T: rate of interest
// T: time in years 
function calculateCI(P, R, T)
{
    return (P * (Math.pow((1 + R / 100), T))-P).toFixed(2);
}