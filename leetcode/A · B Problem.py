
L=int(input())
dp=[0]*(L+1)   #dp[]用于储存从1到L每个数的约数个数
for i in range(1,L+1):
  count=0
  for j in range(i,L+1,i):
    dp[j]+=1

s=[0]*(L+1)     #s[]用于储存前缀和
for i in range(1,L+1):
  s[i]=s[i-1]+dp[i]

result=0
for i in range(1,L):
  result+=dp[i]*s[L-i]

print(result)