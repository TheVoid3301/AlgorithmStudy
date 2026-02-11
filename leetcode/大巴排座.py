def main():
    n = int(input())
    a = list(map(int, input().split()))
    
    # 对学号列表进行排序
    a.sort()
    
    # 遍历检查每个座位
    for i in range(n):
        # 当前座位编号是 i+1
        # 如果排序后的第 i 个学号小于座位编号 i+1，则无法满足
        if a[i] < i + 1:
            print("NO")
            return
            
    # 所有座位都满足条件
    print("YES")

if __name__ == "__main__":
    main()