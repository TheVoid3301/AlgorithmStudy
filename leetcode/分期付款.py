import os
import sys
n,k=map(int,input().split())
ans=0
def get_factor(n):

    factors=set()
    i=1
    while i*i<=n:
        if n%i==0:
            factors.add(i)
            factors.add(n//i)
        i+=1
    return factors
t=n-k
factors=list(get_factor(t))
for i in factors:
  if(i > k):
    ans+=1
print(ans)