import numpy
from timeit import timeit
stat = '''
import numpy
a1 = range(4000)
a2 = numpy.array(a1)
i = 0
'''
if __name__ == "__main__":
    test_times = 1000
    print '1. {0:.8f}'.format(timeit('a1[i]', setup = stat, number = test_times))
    print '2. {0:.8f}'.format(timeit('a2[i]', setup = stat, number = test_times))
    print '3. {0:.8f}'.format(timeit('i += a1[i]; ++i', setup = stat, number = test_times))
    print '4. {0:.8f}'.format(timeit('i += a2[i]; ++i', setup = stat, number = test_times))
    print '5. {0:.8f}'.format(timeit('a = a1[i:len(a1)]; ++i', setup = stat, number = test_times))
    print '6. {0:.8f}'.format(timeit('a = a2[i:len(a2)]; ++i', setup = stat, number = test_times))
    '''
    a1 = range(4000)
    a2 = numpy.array(a1)
    sum1, sum2, elapse1, elapse2, elapse3, elapse4  = 0,0,0.,0.,0.,0.
    for i in range(4000):
        start = time.clock()
        sum1 += a1[i]
        elapse1 += time.clock() - start
        start = time.clock()
        sum2 += a2[i]
        elapse2 += time.clock() - start
        start = time.clock()
        a = a1[i:len(a1)]
        elapse3 += time.clock() - start
        start = time.clock()
        a = a2[i:len(a2)]
        elapse4 += time.clock() - start
    print elapse1, elapse2, elapse3, elapse4
    '''
