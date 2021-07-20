def logger(func):
    def wrapped(numList):
        result = func(numList)
        with open( 'log.txt', 'w') as f:
            f.write(str(result))
        return result
    return wrapped
    
    
@logger
def summator(numList):
    return sum(numList)

listik = [1,2,3,4,5,6]

summator(listik)
with open ('log.txt', 'r') as f:
    print(f.read())
    
#21

def logger(func):
    def wrapped(*args, **kwargs):
        result = func(*args, **kwargs)
        with open( 'log.txt', 'w') as f:
            f.write(str(result))
        return result
    return wrapped
    
    
@logger
def summator(numList):
    return sum(numList)

listik = [1,2,3,4,5,6]

summator(listik)
with open ('log.txt', 'r') as f:
    print(f.read())
#21



import functools

def logger(func):
    @functools.wraps(func)
    def wrapped(*args, **kwargs):
        result = func(*args, **kwargs)
        with open( 'log.txt', 'w') as f:
            f.write(str(result))
        return result
    return wrapped
    
    
@logger
def summator(numList):
    return sum(numList)

listik = [1,2,3,4,5,6]

summator(listik)

#21

def logger(filename):
    def decorator(func):
        def wrapped(*args, **kwargs):
            result = func(*args, **kwargs)
            with open (filename,'w') as f:
                f.write(str(result))
            return result
        return wrapped
    return decorator
        

@logger('newLog.txt')
def summator(numList):
    return sum(numList)

listik = [1,2,3,4,5,6]

summator(listik)


#21


def fib(num):
    a = b = 1
    for _ in range(num):
        yield a
        a, b = b, a+b
        
for num in fib(10):
    print (num)


1
1
2
3
5
8
13
21
34
55
