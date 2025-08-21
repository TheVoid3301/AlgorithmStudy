import os
import sys

MOD = 10**9 + 7

total = pow(9, 10000, MOD)
no_3 = pow(8, 10000, MOD)
no_7 = pow(8, 10000, MOD)
no_3_and_7 = pow(7, 10000, MOD)

result = (total - no_3 - no_7 + no_3_and_7) % MOD
print(result)