def power(x,y):
    ans=1
    while y!=0:
        if y%2==0:
            x=(x%mod*x%mod)%mod
            y=y/2
        else:
            ans=(ans%mod * x%mod)%mod
            x=x*x
            y=(y-1)/2
    return ans
