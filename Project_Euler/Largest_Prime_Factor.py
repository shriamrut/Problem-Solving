from math import sqrt
def solve(x):
	ans=2
	while x%2==0:
		x=x/2
	for i in range(3,int(sqrt(x))+1,2):
		if x%i==0:
			while x%i==0:
				x=x/i
			ans=i
	if x>1:
		ans=x
	return ans
if __name__ == "__main__":
	print(solve(600851475143))
