from math import sqrt as sqrt
maxs=pow(10,6)
primes=[True for x in range(maxs)]
def sieve():
	for i in range(2,int(sqrt(maxs)+1)):
		if primes[i]==True :
			for j in range(i*i,maxs,i):
				primes[j]=False
sieve()
	
		

	

