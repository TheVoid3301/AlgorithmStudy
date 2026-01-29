if __name__ == "__main__":
    with open("words.txt") as f:  #读取
        words_t=f.read()
        words=words_t.splitlines()
    words.sort(key=lambda x:(len(x),x))   #优先长度排序，长度相同按字典序排

    mei_s=set()  #用来判断条件2
    mei=""  #最长的优美字符串，即结果
    for word in words:
        a2=list(word[:-1])  #匹配判断条件2
        a2.sort()
        if len(word)==1 or str(a2) in mei_s:
            a=list(word)
            a.sort()  #排序再存进mei_s
            mei_s.add(str(a))

            if len(word)>len(mei):
                mei=word
            elif len(word)==len(mei):
                mei=min(word,mei)
    print(mei)