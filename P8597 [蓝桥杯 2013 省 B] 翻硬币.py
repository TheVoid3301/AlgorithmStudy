initial = input().strip()
target = input().strip()
flips = 0
coins = list(initial)

for i in range(len(coins) - 1):
    if coins[i] != target[i]:
        coins[i] = 'o' if coins[i] == '*' else '*'
        coins[i+1] = 'o' if coins[i+1] == '*' else '*'
        flips += 1

print(flips)