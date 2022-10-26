fn divide(dividend: i32, divisor: i32) -> i32 {
    let mut dividend:i64 = dividend as i64;
    let mut divisor:i64 = divisor as i64;
    let mut sign:i64 = 0;
    if dividend < 0 && divisor < 0
    {
        sign = 0;
        dividend = -dividend;
        divisor = -divisor;
    }
    else if dividend < 0
    {
        dividend = -dividend;
        sign = 1;
    }
    else if divisor < 0
    {
        divisor = -divisor;
        sign = 1;
    }
    let mut dc:i64 = dividend;
    let mut q:i64 = 0;
    while dc >= divisor
    {
        dc -= divisor;
        q+=1;
    }
    if sign == 1 
    {
        q = -q;
    }
    
    return q;
}

fn main() {
    divide(-2147483648,-1);
}
