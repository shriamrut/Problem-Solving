from math import sqrt
def sieveOfEratosenses(n,x):
	if n==1:
		return 2
	else:
		primes=[True for _ in range(n+1)]
		primes[2]=True
		for i in range(2,int(sqrt(n))+1):
			if primes[i]:
				for j in range(i*i,n+1,i): #why i^2
					primes[j]=False
		c=1
		i=2 
		while True:
			if primes[i] and c==x:
				return i
			elif primes[i]:
				c=c+1
			i=i+1
if __name__=="__main__":
	print(sieveOfEratosenses(pow(10,8),10001))
