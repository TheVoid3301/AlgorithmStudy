import os
import sys

n,d = input().split()
n = int(n)
r,f = d.split('.')
x = len(f)
d = int(r + f)*pow(2,n)
if x == 1:
    d = str(d)
else:
    d = str(d)[:-x+1]
if int(d[-1]) >= 5:
    d = int(d[:-1])+1
else:
    d = int(d[:-1])
print(d)