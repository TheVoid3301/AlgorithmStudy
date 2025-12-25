import os
import sys

# 请在此输入您的代码
def main():
    d1 = 5
    res = 0
    n = 2025
    while n > 0:
        res += 1
        if res % 2 == 1:
            d1 += 15
        else:
            d1 += 2
        if res % 3 == 1:
            d1 += 2
        elif res % 3 == 2:
            d1 += 10
        else:
            d1 += 7
        n -= d1
        d1 = 5
    print(res)

if __name__ == "__main__":
    main()