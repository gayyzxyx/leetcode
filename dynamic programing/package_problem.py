# -*- coding: utf-8 -*-
#!/usr/bin/env python
#背包问题，第一行表示总人数和金矿数量，第二行开始每个金矿需要的人数和其拥有的金子数量
#100 5
#77 91
#22 22
#29 87
#50 46
#99 90

people_total = 100
mine_num = 5
people_need = [77, 22, 29, 50, 99]
gold = [91, 22, 87, 46, 90]
max_gold = [[-1 for col in range(mine_num+1)] for row in range(people_total+1)]

def max(a, b):
    return a if a > b else b

def get_max_gold(people, minenum):
    ret_max_gold = 0
    #如果计算过则保存起来
    if max_gold[people][minenum] != -1:
        ret_max_gold = max_gold[people][minenum]
    #如果仅有一个金矿
    elif minenum == 0:
        if people >= people_need[minenum]:
            ret_max_gold = gold[minenum]
        else:
            ret_max_gold = 0
    elif people >= people_need[minenum]:
        ret_max_gold = max(get_max_gold(people - people_need[minenum], minenum - 1) + gold[minenum], get_max_gold(people, minenum - 1))
    else:
        ret_max_gold = get_max_gold(people, minenum - 1)
    max_gold[people][minenum] = ret_max_gold
    return ret_max_gold

print get_max_gold(people_total, mine_num-1)
