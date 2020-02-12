#not mine
def prime_sieve(n):
    """ Returns  a list of primes < n for n > 2 """
    from itertools import compress
    sieve = bytearray([True]*(n//2))
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i//2]:
            sieve[i*i//2::i] = bytearray((n-i*i-1)//(2*i)+1)
    return [2,*compress(range(3,n,2),sieve[1:])]

def euler_7():
    import time
    start = time.time()

    ans = prime_sieve(1000000)[10000]
    
    elapsed = (time.time() - start)
    print("%s found in %s seconds." % (ans, elapsed))
