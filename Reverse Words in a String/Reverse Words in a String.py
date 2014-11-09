# -*- coding: utf-8 -*-
#!/usr/bin/env python
class Solution:
    # @param s, a string
    # @return a string
    #需要考虑空字符串如" "应该输出"",还有当中间隔有多个空格，应该输出为一个空格
    def reverseWords(self, s):
        s_array = s.split(" ")
        s_reverse = ""
        for i in range(len(s_array)):
            if s_array[len(s_array)-i-1] != '':
                s_reverse += s_array[len(s_array)-i-1] + " "
        return s_reverse[0 : len(s_reverse)-1].lstrip().rstrip()

s = Solution()
print s.reverseWords("   a   b ")