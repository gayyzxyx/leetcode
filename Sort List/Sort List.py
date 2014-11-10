# -*- coding: utf-8 -*-
#!/usr/bin/env python
# Sort a linked list in O(n log n) time using constant space complexity.
# Definition for singly-linked list.
import sys
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def sortList(self, head):
        if head == None:
            return None
        if head.next == None:
            return head

    def heap_build(self, x, heap, index):
        while heap[index/2] > x:
            heap[index] = heap[index/2]
            index = index/2
        heap[index] = x

    def delete_min(self, heap, size):
        if len(heap) == 0:
            return heap
        min_element = heap[1]
        last_element = heap[size]
        size = size - 1
        i = 1
        while i * 2 <= size:
            child = i * 2
            if child != size and heap[child+1] < heap[child]:
                child = child + 1
            if last_element > heap[child]:
                heap[i] = heap[child]
            else:
                i = child
                break
        heap[i] = last_element
        return min_element

s = Solution()
heap = [0 for i in range(1000)]
heap[0] = -sys.maxint
s.heap_build(21, heap, 1)
s.heap_build(13, heap, 2)
s.heap_build(16, heap, 3)
s.heap_build(19, heap, 4)
s.heap_build(14, heap, 5)
s.heap_build(31, heap, 6)
print heap[1:7]
# print s.delete_min(heap, 6)
# print s.delete_min(heap, 5)