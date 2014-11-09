# -*- coding: utf-8 -*-
#!/usr/bin/env python
class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        s_array = s.split(" ")
        s_reverse = ""
        for i in range(len(s_array)):
            if s_array[len(s_array)-i-1] != '':
                s_reverse += s_array[len(s_array)-i-1] + " "
        return s_reverse[0 : len(s_reverse)-1].lstrip().rstrip()

s = Solution()
print s.reverseWords("   a   b ")