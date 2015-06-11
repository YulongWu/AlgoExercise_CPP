"""
This Method comes from https://leetcode.com/discuss/15790/share-my-o-log-min-m-n-solution-with-explanation
which is the current best time complexity
"""
def Median2_others(A, B):
    m, n = len(A), len(B)

    if m > n:
        return Median2_others(B, A)

    imin, imax = 0, m
    while imin <= imax:
        i = (imin + imax) / 2
        j = (m + n + 1) / 2 - i
        if j > 0 and i < m and B[j - 1] > A[i]:
            imin = i + 1
        elif i > 0 and j < n and A[i - 1] > B[j]:
            imax = i - 1
        else:
            if i == 0:
                num1 = B[j - 1]
            elif j == 0:
                num1 = A[i - 1]
            else:
                num1 = max(A[i - 1], B[j - 1])
                #print "num1: "+num1

            if (m + n) & 1:
                return num1

            if i == m:
                num2 = B[j]
            elif j == n:
                num2 = A[i]
            else:
                num2 = min(A[i], B[j])
                #print "num2: " + num2

            return (num1 + num2) / 2.0
"""
This is the above method of my own version, have made a little change compared with the above version:
    make the initial value of spliter from (len1 + len2 + 1) / 2 to (len1 + len2) / 2, correspondingly changed following logic to get correct answer.
"""
def Median2_my(nums1, nums2):
    len1, len2 = len(nums1), len(nums2)
    if len1 > len2:
        return Median2_my(nums2, nums1)
    spliter = (len1 + len2) / 2
    low_bound, up_bound = 0, len(nums1)
    while low_bound <= up_bound:
        i = (low_bound + up_bound)/2
        j = spliter - i
        if i > 0 and j < len2 and nums1[i-1] > nums2[j]:
            up_bound = i-1
        elif j > 0 and i < len1 and nums2[j-1] > nums1[i]:
            low_bound = i+1
        else:
            break
    if i == len1:
        c1 = nums2[j]
    elif j == len2:
        c1 = nums1[i]
    else:
        c1 = min(nums1[i], nums2[j])
    if (len1 + len2) & 1:
        return c1
    if i == 0:
        c2 = nums2[j-1]
    elif j == 0:
        c2 = nums1[i-1]
    else:
        c2 = max(nums1[i-1], nums2[j-1])
    return (c1 + c2) / 2.0
"""
This method comes from https://leetcode.com/discuss/9265/share-my-simple-o-log-m-n-solution-for-your-reference
It is not better than the above method due to the time complexity is O(log(m+n)), but its recursive thinking is valuable.
"""
def Median2_others_M2_(nums1, nums2, k):
    if len(nums1) > len(nums2):
        return Median2_others_M2_(nums2, nums1, k)
    i, j = min(len(nums1), k / 2), min(len(nums2), k / 2)
    if(len(nums1) == 0):
        return nums2[k - 1]
    if k == 1:
        return min(nums1[0], nums2[0])
    if nums1[i-1] < nums2[j-1]:
        return Median2_others_M2_(nums1[i:len(nums1)], nums2[0:min(j+2, len(nums2))], k-i)
    else:
        return Median2_others_M2_(nums1[0:min(i+1, len(nums1))], nums2[j:len(nums2)], k-j)
def Median2_others_M2(nums1, nums2):
    len1, len2 = len(nums1), len(nums2)
    k = (len1 + len2 + 1) / 2
    if((len1+len2) & 1 == 1):
        return Median2_others_M2_(nums1, nums2, k)
    else:
        return (Median2_others_M2_(nums1, nums2, k) + Median2_others_M2_(nums1, nums2, k+1)) / 2.0
'''
This method is a variation on the above method, which is a standard example of the application of binary search thinking
'''
def Median2_others_M2_Var2_(nums1, nums2, k):
    len1, len2 = len(nums1), len(nums2)
    if len1 > len2:
        return Median2_others_M2_Var2_(nums2, nums1, k)
    if len1 == 0:
        return nums2[k-1]
    if k == 1:
        return min(nums1[0], nums2[0])
    i = (len1+1)/2; j = k - i 
    if nums1[i-1] < nums2[j-1]:
        return Median2_others_M2_Var2_(nums1[i:len1] if i<len1 else [], nums2[0:j], k-i)
    else:
        return Median2_others_M2_Var2_(nums1[0:i], nums2[j:len2] if j<len2 else [], k-j)
def Median2_others_M2_Var2( nums1, nums2):
    len1, len2 = len(nums1), len(nums2)
    k = (len1 + len2 + 1) / 2
    if((len1+len2) & 1 == 1):
        return Median2_others_M2_(nums1, nums2, k)
    else:
        return (Median2_others_M2_(nums1, nums2, k) + Median2_others_M2_(nums1, nums2, k+1)) / 2.0

"""
Following two methods are together, used for get median among 3 lists.
"""
def Median2__(nums1, nums2, spliter):
    len1, len2 = len(nums1), len(nums2)
    if len1 > len2:
        return Median2__(nums2, nums1, spliter)
    low_bound, up_bound = 0, len1
    while low_bound <= up_bound:
        i = (low_bound + up_bound)/2
        j = spliter - i
        if i > 0 and j < len2 and nums1[i-1] > nums2[j]:
            up_bound = i-1
        elif j > 0 and i < len1 and nums2[j-1] > nums1[i]:
            low_bound = i+1
        else:
            break
    if i == len1:
        high_min = nums2[j]
    elif j == len2:
        high_min = nums1[i]
    else:
        high_min = min(nums1[i], nums2[j])
#    if (len1 + len2) & 1:
#        return high_min
    if i == 0:
        low_max = nums2[j-1]
    elif j == 0:
        low_max = nums1[i-1]
    else:
        low_max = max(nums1[i-1], nums2[j-1])
    return low_max, high_min 


def Median3_my(A, B, C):
    len_a, len_b, len_c = len(A), len(B), len(C)
    len_min = min(len_a, len_b, len_c)
    if(len_a > len_b and len_c >= len_b):
        return Median3_my(B, A, C)
    elif(len_a > len_c and len_b >= len_c):
        return Median3_my(C, A, B)
    spliter = (len_a + len_b + len_c) / 2
    low_bound, up_bound = 0, len_a
    while low_bound <= up_bound:
        i = low_bound + (up_bound - low_bound) / 2
        #print "B: {0}, C: {1}, spliter: {2}".format(B, C, spliter-i)
        low_max, high_min = Median2__(B, C, spliter - i)
        if(i > 0 and A[i-1] > high_min):
            up_bound = i-1
        elif i < len_a and low_max > A[i]:
            low_bound = i+1
        else:
            if i > 0 and A[i-1] > low_max:
                low_max = A[i-1]
            if i < len_a and A[i] < high_min:
                high_min = A[i]
            if (len_a + len_b + len_c) & 1:
                return high_min
            else:
                return (high_min + low_max) / 2.0

def MedianN_my_(arrays, k):
    print 'k={0}, arrays={1}'.format(k, arrays)
    if len(arrays) == 0 or len(arrays) == 1 and len(arrays[0]) == 0:
        print arrays
        return None, None
    A = arrays[0]
    if len(arrays) == 1:
        return A[k-1] if k-1 < len(A) else None, A[k] if k < len(A) else None
    min_v = len(A)
    if min_v == 0:
        return MedianN_my_(arrays[1:len(arrays)], k)
    low_bound, up_bound = 0, min(k, min_v)
    i, low_max, high_min = 0, 0, 0
    while low_bound <= up_bound:
        i = low_bound + (up_bound - low_bound) / 2
        low_max, high_min = MedianN_my_(arrays[1:len(arrays)], k-i)
        if i >= 0 and high_min is not None and A[i-1] > high_min:
            up_bound = i-1
        elif i < min_v and low_max is not None and low_max > A[i]:
            low_bound = i+1
        else:
            break
    if i != min_v:
        high_min = A[i] if high_min is None else min(A[i], high_min)
    if i != 0:
        low_max = A[i-1] if low_max is None else max(A[i-1], low_max)
    return low_max, high_min
def MedianN_my(arrays):
    sum = 0
    arrays.sort(key = len)
    print arrays
    for array in arrays:
        sum += len(array)
    k = sum / 2;
    if sum & 1:
        return MedianN_my_(arrays, k)[1]
    else:
        low, high = MedianN_my_(arrays, k)
        return (low + high) / 2. if low is not None else None
if __name__ == "__main__":
    test_cases4_MedianN = []
    nums1 = [9,11,12,13,14,15,16] 
    nums_x = nums1
    test_cases4_MedianN.append(nums1)
    nums2 = [2,3,4,5,6,7,8]
    nums_y = nums2
    test_cases = [(nums1, nums2)]
    test_cases4_MedianN.append(nums2)
    nums1 = [1,2]
    test_cases4_MedianN.append(nums1)
    nums2 = [1,2,3]
    test_cases.append((nums1, nums2))
    test_cases4_MedianN.append(nums2)
    #test case 3
    nums1 = [1]
    nums2 = [1]
    test_cases.append((nums1, nums2))
    test_cases4_MedianN.append(nums1)
    test_cases4_MedianN.append(nums2)
    nums3 = [11,12,13]
    test_cases4_MedianN.append(nums3)
    print "Median3_my: {0}".format(Median3_my(nums_x, nums_y, nums3))
    for i, case in enumerate(test_cases):
        nums1, nums2 = case
        print "-" * 15 + "Test Case {0}".format(i) + "-" * 15
        print "Median2_others: {0}".format(Median2_others(nums1, nums2))
        print "Median2_my: {0}".format(Median2_my(nums1, nums2))
        print "Median2_others_M2: {0}".format(Median2_others_M2(nums1, nums2))
        print "Median2_others_M2_Var2: {0}".format(Median2_others_M2_Var2(nums1, nums2))
    print MedianN_my(test_cases4_MedianN)
