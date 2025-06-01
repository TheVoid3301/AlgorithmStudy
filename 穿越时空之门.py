import os
import sys

# 请在此输入您的代码
count = 0
for i in range(1, 2025):
  n2 = 0
  n4 = 0
  j = i
  while j > 0:
    n2 += (j % 2)
    j = j // 2
  j = i
  while j > 0:
    n4 += (j % 4)
    j = j // 4
  if (n2 == n4):
    count = count + 1
print(count)