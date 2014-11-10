# -*- coding: utf-8 -*-
#!/usr/bin/env python
# Definition for a point
class Point:
     def __init__(self, a=0, b=0):
         self.x = a
         self.y = b

class Solution:
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):
        if len(points) == 0:
            return 0
        if len(points) == 1:
            return 1
        point_map = {}
        max_num = 0
        for i in range(len(points)):
            k_map = {}
            same_point = 0
            max_point_num = 1
            for j in range(i+1, len(points)):
                if points[j].x == points[i].x and points[j].y == points[i].y:
                    same_point = same_point + 1
                    continue
                if points[j].x != points[i].x:
                    k = 1.0*(points[j].y-points[i].y)/(points[j].x-points[i].x)
                else:
                    k = 999999
                if k_map.has_key(k):
                    k_map[k] = k_map.get(k)+1
                else:
                    k_map[k] = 2
                if k_map[k] > max_point_num:
                    max_point_num = k_map[k]
            point_map[i] = max_point_num = max_point_num + same_point
        for key in point_map.keys():
            if point_map[key] > max_num:
                max_num = point_map[key]
        return max_num

s = Solution()
p1 = Point(1,1)
p2 = Point(1,1)
# p3 = Point(1,1)
print s.maxPoints([p1,p2])