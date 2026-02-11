def main():
    n = int(input())
    s = input()
    d = dict()
    for i in s:
        if i in d:
            d[i] += 1
        else:
            d[i] = 1
    res = 0
    for (i, j) in d.items():
        if j % 2 == 1:
            res += 1
    res = max(1, res)
    print(res)


if __name__ == '__main__':
    main()