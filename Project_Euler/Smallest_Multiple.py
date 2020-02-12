from math import sqrt

def primeFactorise(x):
	c=0
	ans=[]
	while x%2==0:
		x=x/2
		c=c+1
	if c>=1:
		ans.append((2,c))
	for i in range(3,int(sqrt(x))+1,2):
		c=0
		while x%i==0:
			x=x/i
			c=c+1
		if c>=1:
			ans.append((i,c))
	if x>1:
		ans.append((x,1))
	return ans
	
def gcd(a,b):
	while b:
		a,b=b,a%b
	return a
	
def lcm(a,b):
	return a*b//gcd(a,b)

def solve(x):
	ans=1
	for i in range(1,x+1):
		ans=lcm(ans,i)
	return ans

if __name__=="__main__":
	print(solve(20))
	
