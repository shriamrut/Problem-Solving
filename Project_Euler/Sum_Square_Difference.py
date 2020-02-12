def sumofsquares(n):
	return (n*(n+1)*(2*n+1))//6

def squareofsum(n):
	return ((n*(n+1))//2)**2

def solve(n):
	a1=sumofsquares(n)
	a2=squareofsum(n)
	return a2-a1

if __name__=="__main__":
	print(solve(100))
