from itertools import permutations

n = int(input())
num = 0
for item in permutations('123456789'):
    per = ''.join(item)
    for i in range(1, len(str(n)) + 1):
        a = int(per[:i])
        if a > n:
            continue
        # n = a + b/c  =>  b = (n - a) * c
        # 因为用per的最后部分当c，所以c的个位数我们是已知的per[-1]
        # (n - a) * per[-1] 的个位数与 (n - a) * c 的个位数相同
        # 也就是b的个位数，这样就可以确定b和c之间的间隔在哪
        b_last = (n - a) * int(per[-1]) % 10
        b_last_index = per.find(str(b_last))
        if b_last_index < i or b_last_index == 8:
            continue
        b = int(per[i:b_last_index + 1])
        c = int(per[b_last_index + 1:])
        if a + b / c == n:
            # print(a, b, c)
            num += 1
print(num)