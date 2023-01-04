'''
参考：https://blog.csdn.net/ly0724ok/article/details/119876759
'''
from typing import Sequence


def LCStr(str1:str, str2:str):
    '''最长公共子串
    '''
    if len(str1) < len(str2):
        str1, str2 = str2, str1
    max_len = 0
    end_idx = -1    # 用于记录最长子串的位置
    mat: list[int] = [0] * (len(str2)+1)
    for c in str1:
        for i in range(len(str2)-1, -1, -1):
            mat[i+1] = mat[i] + 1 if c == str2[i] else 0
            if mat[i+1] > max_len:
                max_len = mat[i+1]
                end_idx = i+1
        print(mat[1:])
    return str2[end_idx-max_len:end_idx]

def LCStr2(str1: Sequence, str2: Sequence):
    '''最长公共子串
    其实, 只用按照DP 矩阵, 从右上角开始按对角线计算即可, 可以节省空间, 但无法节省时间
    '''
    max_len = 0
    end_idx = -1
    i, j = len(str1)-1, 0
    while j < len(str2):
        t = 0
        i1, i2 = i, j
        while i1 < len(str1) and i2 < len(str2):
            if str1[i1] == str2[i2]:
                t += 1
                if t >= max_len:
                    max_len = t
                    end_idx = i1 + 1
            else:
                t = 0
            i1, i2 = i1+1, i2+1
        if i > 0:
            i -= 1
        else:
            j += 1
    return str1[end_idx-max_len:end_idx]


def LCSeq(seq1: Sequence, seq2: Sequence):
    '''最长公共子序列
    '''
    init = (0, '')
    if not seq1 or not seq2:
        return init
    if len(seq1) < len(seq2):
        seq1, seq2 = seq2,seq1 
    ready = [init] * (len(seq2) + 1)
    for c1 in seq1:
        doing = [init]
        for i, c2 in enumerate(seq2):
            if c1 == c2:
                t = ready[i][0]+1, ready[i][1]+c1
            elif ready[i+1][0] >= doing[i][0]:
                t = ready[i+1]
            else:
                t = doing[i]
            doing.append(t)
        ready = doing
        print(ready[1:])
    return ready[-1]


if __name__ == '__main__':
    str1, str2 = "abcabcdekfghijkyz", "eababcdefghijkwx"
    print(LCStr(str1, str2))
    print(LCStr2(str1, str2))

    from string import ascii_letters as letters
    from random import shuffle
    seq1 = list(letters)
    seq2 = list(letters)
    shuffle(seq1)
    print(seq1)
    shuffle(seq2)
    print(seq2)
    print(LCSeq(seq1, seq2))