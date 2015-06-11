stat = '''
import numpy
def func(a):
    while len(a) >= 1:
        a[len(a)-1] += 1
        if len(a) == 1:
            return a[0]
        else:
            a = a[1:len(a)]
a1=range(4000)
a2=numpy.array(range(4000))
'''
import timeit
import time
import numpy
def func(a):
    elapse = 0.
    while len(a) >= 1:
        a[len(a)-1] += 1
        if len(a) == 1:
            return elapse
        else:
            start = time.clock()
            a = a[1:len(a)]
            elapse += time.clock() - start
#string stat is declared same as following 9 lines, used for timeie
def func_1(a):
    while len(a) >= 1:
        a[len(a)-1] += 1
        if len(a) == 1:
            return a[0]
        else:
            a = a[1:len(a)]
a1=range(4000)
a2=numpy.array(range(4000))
if __name__ == "__main__":
    test_times = 100
    print '\n' + '-' * 20 + 'test on single line' + '-' * 20
    elapse1, elapse2 = 0.,0.
    for test_times in range(test_times):
        elapse1 += func(a1)
        elapse2 += func(a2)
    print "1.a Execute time of built-in list: {0}".format(elapse1)
    print "1.b Execute time of numpy array: {0}".format(elapse2)
    print '\n' + '-' * 20 + 'test on func' + '-' * 20
    elapse1, elapse2 = 0.,0.
    for test_times in range(test_times):
        start = time.clock()
        func_1(a1)
        elapse1 += time.clock() - start
        start = time.clock()
        func_1(a2)
        elapse2 += time.clock() - start
    print "2.a Execute time of built-in list: {0}".format(elapse1)
    print "2.b Execute time of numpy array: {0}".format(elapse2)
    print '\n' + '-' * 20 + 'test on func with timeit' + '-' * 20
    print "3.a Execution time with build-in list: {0}".format(timeit.timeit('func(a1)', setup = stat, number = test_times))
    print "3.b Execution time with Numpy array: {0}".format(timeit.timeit('func(a2)', setup = stat, number = test_times))
