class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN){
            if(divisor==-1) return INT_MAX;
            else if(divisor<0) return 1+divide(dividend-divisor,divisor);
            else return -1+divide(dividend+divisor,divisor);
        }
        if(divisor==INT_MIN) return 0;
        int a=abs(dividend), b=abs(divisor), ans=0;
        for(int i=31;i>=0;i--){
            if((a>>i)>=b){
                a-=b<<i;
                ans+=1<<i;
            }
        }
        return (dividend>0)==(divisor>0)?ans:-ans;
    }
};