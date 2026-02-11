import os
import sys

# 请在此输入您的代码
t=int(input())
for _ in range(t):
  n=int(input())
  ans=0
  if n%3==0:
    ans+=2*n
  else:
    ans+=n
  print(ans)