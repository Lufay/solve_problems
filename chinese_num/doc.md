# 问题描述
将一个12 位整数转换成中文读法的形式

# 思路
分段取读

# 坑
1. 零的读法
比如
20014，要读作“二十万零一十四”
201400，要读作“二十万零一千四百”，“零”要读出来
chinese.py 不行，chinese2.py 可以
