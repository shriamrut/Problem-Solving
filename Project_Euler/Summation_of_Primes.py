from math import sqrt
def SieveOfErarthrosenses(n):
	primes=[True for i in range(n+1)]
	for i in range(2,int(sqrt(n))+1,1):
		if primes[i]:
			for j in range(i*i,n+1,i):
				primes[j]=False
	ans=0
	for i in range(2,n):
		if primes[i]:
			ans=ans+i
	return ans

if __name__=="__main__":
	print(SieveOfErarthrosenses(2000000))
		
