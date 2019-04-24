#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

Y_UNIT = 100000000
W_UNIT = 10000
NUMS = u'零 一 二 三 四 五 六 七 八 九'.split()
UNIT_MAP = {
        1: u'',
        10: u'十',
        100: u'百',
        1000: u'千',
        W_UNIT: u'万',
        Y_UNIT: u'亿'
        }

def colloquial(f):
    def func(n, *argv):
        res = f(n, *argv)
        if res.startswith(u'一十'):
            res = res.replace(u'一十', u'十', 1)
        return res
    return func

def read_seg(num, get=lambda x: NUMS[x], max_unit=1000, each_unit=10):
    ns = []
    unit = max_unit
    zero = False
    while unit > 0:
        n = num / unit
        if n > 0:
            ns.append(get(n) + UNIT_MAP[unit])
            zero = False
        elif not zero:
            ns.append(NUMS[0])
            zero = True
        num %= unit
        unit /= each_unit
    return ''.join(ns).strip(NUMS[0])

@colloquial
def read_num(num):
    return read_seg(num, read_seg, Y_UNIT, W_UNIT)


if __name__ == '__main__':
    n = sys.argv[1]
    print read_num(int(n))
