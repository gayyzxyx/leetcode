# -*- coding: utf-8 -*-
#!/usr/bin/env python
#end[i]表示以a[i]结尾的最大子数组之和，包括两种情况：包含a[i]和不包含a[i，则end[i]=max(end[i-1]+a[i], a[i])
#all[i]表示a[i]的最大子数组之和，包括两个方面：以i结尾和不以li结尾，则all[i]=max(end[i],all[i-1])
def max(a, b):
    return a if a > b else b

def dp_msp(a):
    end, all = [], []
    end.append(a[0])
    all.append(a[0])
    for i in range(1, len(a)):
        end.insert(i, max(end[i-1] + a[i], a[i]))
        all.insert(i, max(end[i], all[i-1]))
    return all[len(a)-1]

#一直累加，只要大于0，如果小于0，从当前位置开始重新开始

def view_msp(a):
    max_sum = -9999
    sum = 0
    for i in range(len(a)):
        if sum < 0:
            sum = a[i]
        else:
            sum = sum + a[i]
        if sum > max_sum:
            max_sum = sum
    return max_sum

a = [-1, 3, -5, 4, 6, -1, 2, -7, 13, -3]
print dp_msp(a)
print view_msp(a)