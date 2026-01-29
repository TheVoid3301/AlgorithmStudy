import os
import sys

# 请在此输入您的代码
def res():
    key = ["lqb", "lbq", "blq", "bql", "qlb", "qbl"]

    s = input()
    a = [0] * len(s)

    m = 0
    for i, k in enumerate(s):
        if i < 3:
            continue
        if i == 3:
            if s[: 3] in key:
                a[i] = 1
                m = max(m, a[i])
            continue;
        if s[i - 3 : i] in key:
            a[i] = a[i - 3] + 1
            m = max(m, a[i])

    print(m)

if __name__ == "__main__":
    res()