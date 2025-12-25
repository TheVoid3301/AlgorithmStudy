def main():
    tmax, s, t = map(int, input().split())
    if tmax > 35 and s == 1 and t >= 33:
        print("Bu Tie")
        print(tmax)
        return
    if tmax > 35 and s == 0 and t >= 33:
        print("Shi Nei")
        print(tmax)
        return
    if s == 1 and tmax <= 35 or s == 1 and t < 33:
        print("Bu Re")
        print(t)
        return
    if tmax <= 35 and s == 0 or t < 33 and s == 0:
        print("Shu Shi")
        print(t)
        return

if __name__ == '__main__':
    main()
