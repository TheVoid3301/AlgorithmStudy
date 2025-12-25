def main():
    s = input()
    d = dict()
    c = list(input().split())
    res = 0
    for i in s:
        if i in d:
            d[i] += 1
        else:
            d[i] = 1
    for i in range(26):
        ch = chr(ord('a') + i)
        if ch not in d:
            d[ch] = 0
    sorted_dict = dict(sorted(d.items()))
    for j in d:
        res += int(d[j]) * int(c[ord(j) - ord('a')])
    print(*sorted_dict.values(), sep=' ')
    print(res)

if __name__ == '__main__':
    main()