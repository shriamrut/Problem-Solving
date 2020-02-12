first=1
second=2
ans=2
while True:
	third=first+second
	if third>4000000:
		break
	if third%2==0:
		ans=ans+third
	first=second
	second=third
print(ans)
