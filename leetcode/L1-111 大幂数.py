def main():
    n = int(input())
    k = 1
    res = 1
    f = False
    maxn = n
    now = 1
    t = 1
    p = 0
    last = 1
    while now <= 31:
        p += t ** now
        if p == n:
            res = now
            now += 1
            maxn = t
            last = t
            t = 1
            p = 0
            f = True
            continue
        if p > n:
            now += 1
            maxn = t - 1
            t = 1
            p = 0
            continue
        t += 1
    if not f:
        print(f"Impossible for {n}.")
        return
    m = range(1, last + 1)
    print(*m, sep = "^" + str(res) + "+", end = "")
    print("^" + str(res))


if __name__ == "__main__":
    main()