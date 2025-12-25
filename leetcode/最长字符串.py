import os
import sys

def main():
    with open("words.txt", "r", encoding="utf-8") as f:
        words = f.readlines()
    s = set()
    for word in words:
        s.add(sorted(word.strip()))

    res = ""

    for word in s:
        if len(word) == 1:
            res = word
        else:
            

if __name__ == "__main__":
    main()