import sys
import heapq

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    
    n = int(data[0])
    m = int(data[1])
    k = int(data[2])
    
    idx = 3
    res = []
    max_heap = []
    
    for i in range(n):
        row = list(map(int, data[idx:idx + m]))
        res.append(row)
        for j in range(m):
            heapq.heappush(max_heap, (-row[j], i, j))
        idx += m

    row_deleted = [False] * n
    col_deleted = [False] * m

    deleted_count = 0
    while deleted_count < k and max_heap:
        neg_val, i, j = heapq.heappop(max_heap)
        if row_deleted[i] or col_deleted[j]:
            continue
        row_deleted[i] = True
        col_deleted[j] = True
        deleted_count += 1

    output_lines = []
    for i in range(n):
        if row_deleted[i]:
            continue
        line = []
        for j in range(m):
            if not col_deleted[j]:
                line.append(str(res[i][j]))
        output_lines.append(' '.join(line))
    
    print('\n'.join(output_lines))

if __name__ == "__main__":
    main()