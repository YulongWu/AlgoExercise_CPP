# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        i = 0
        while i < len(intervals):
            if intervals[i].start > newInterval.start:
                #handle start
                prev = i - 1
                if i == 0 or intervals[i-1].end < newIntervals.start:
                    intervals.insert(i, newIntervals)
                    i += 1
                #handle end
                if intervals[prev].end < newInterval.end:
                    j = i
                    while intervals[j].start <= newInterval.end:
                        j += 1
                    intervals[i-1].end = max(newInteval.end, intervals[j-1].end)
                    del intervals[i:j]
                break
            i += 1
        else:
            intervals.append(newInterval)
