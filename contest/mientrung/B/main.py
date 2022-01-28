12:36 PM
Trọng
Trọng Chiến
n = int(input())

arr = []


def maxx(a, b):
    if a > b:
        return a
    else:
        return b

tmp = input().split()
for i in tmp:
    j = int(i)
    arr.append(j)

ans = 1

for i in range(len(arr)):
    ans*=arr[i]


for i in range(len(arr)):
    tmpans = 1
    for j in range(len(arr)):
        if i == j:
            continue
        tmpans *= arr[j]
    ans = maxx(ans, tmpans)

mo = 1000000000+7
print(ans%mo)