n = int(input())
for i in range(n):
	s = input()
	if(s==s[::-1]):
		sum=0
		for j in s:
			sum += int(j)
		sum = str(sum)
		if sum==sum[::-1]:
			print("Y")
		else:
			print("N")

	else:
		print("N")
print(1+1+1)