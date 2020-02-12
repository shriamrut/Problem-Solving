def rev(x):
	ans=0
	while x>0:
		ans=ans*10+(x%10)
		x=x/10
	return ans
	
def solve():
	pal=-1
	for i in range(100,1000):
		for j in range(100,1000):
			if i*j==rev(i*j):
				pal=max(i*j,pal)
	return pal

if __name__ == "__main__":
	print(solve())
 
