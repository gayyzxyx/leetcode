# -*- coding: utf-8 -*-
#!/usr/bin/env python
class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        stack = []
        for i in tokens:
            if i == "+":
                stack.append(int(stack.pop()) + int(stack.pop()))
            elif i == "-":
                f = int(stack.pop())
                n = int(stack.pop())
                stack.append(n - f)
            elif i == "*":
                stack.append(int(stack.pop()) * int(stack.pop()))
            elif i =="/":
                f = float(stack.pop())
                n = int(stack.pop())
                stack.append(n / f)
            else:
                stack.append(i)
        return int(stack[0])

s = Solution()
print s.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"])