# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
	if not intervals:
            return intervals
        intervals.sort(key=operator.attrgetter('start'))
        prev = None
        i = 0
        while i < len(intervals):
            if prev and intervals[i].start <= prev.end:
                prev.end = max(prev.end, intervals[i].end)
                del intervals[i]
            else: #error1: i missed this else
                prev = intervals[i]
                i += 1
        return intervals

    def merge2(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
	if not intervals:
            return intervals
        intervals.sort(key=operator.attrgetter('start'))
        prev = None
        i = 0
        res = []
        for item in intervals:
            if prev and intervals[i].start <= prev.end:
                prev.end = max(prev.end, intervals[i].end)
                del intervals[i]
            else: #error1: i missed this else
                prev = intervals[i]
                i += 1
        return intervals
