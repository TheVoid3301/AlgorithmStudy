import os
import sys

# 请在此输入您的代码

def res():
    w, h, v = int(input().split())
    for i in range(h):
        for j in range(w):
            print("Q", end="")
        print()
    for i in range(m):
        for j in range(v + w):
            print("Q", end="")
        print()

if __name__ == "__main__":
    res()