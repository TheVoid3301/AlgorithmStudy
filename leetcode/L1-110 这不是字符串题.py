N,M = map(int,input().split())
A = ''.join([chr(x+96) for x in map(int,input().split())])

for _ in range(M):
    now = int(input())
    if now == 1:
        tmpB = list(map(int,input().split()))
        tmpC = list(map(int,input().split()))
        tmpB.pop(0)
        tmpC.pop(0)
        B = ''.join([chr(x+96) for x in tmpB])
        C = ''.join([chr(x+96) for x in tmpC])
        A = A.replace(B,C,1)
    elif now == 2:
        B = ''
        len_A = len(A)
        for i in range(len_A-1):
            B += A[i]
            if (ord(A[i])-96 + ord(A[i+1])-96)%2 == 0:
                B += chr((ord(A[i])-96 + ord(A[i+1])-96)//2+96)
        B += A[len_A-1]
        A = B
    else:
        l,r = map(int,input().split())
        A = A[:l-1] + A[l-1:r][::-1] + A[r:]

len_A = len(A)
for i in range(len_A):
    if i != len_A-1:
        print(ord(A[i])-96,end=' ')
    else:
        print(ord(A[i])-96,end='')