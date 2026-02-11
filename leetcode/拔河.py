from bisect import  *
n=int(input())
arr=list(map(int,input().split()))
a=[]
for i in range(n):
    for j in range(i+1,n+1):
        a.append(sum(arr[i:j]))
a.sort()
res=sum(a)
for i in range(1,len(a)):
    res=min(abs(a[i]-a[i-1]),res)
print((res))
