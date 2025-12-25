def main():
    a = int(input())
    b = 1
    if b == a:
        print(b)
        return
    while b < a:
        b = b * 2
        if b == a:
            print(b)
            return
        elif b > a:
            print(b // 2)
            return

if __name__ == '__main__':
    main()