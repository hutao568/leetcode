class MyCache(object):

    def __init__(self,func):
        self.func=func
        self.cache={}
        print(f'In MyCache __init__ {func.__name__}')

    def __call__(self, *args, **kwargs):
        if not args in self.cache:
            self.cache[args]=self.func(*args)
        return self.cache[args]

@MyCache
def fib(n):
    if n<=1:return 1
    return fib(n-1)+fib(n-2)

print(fib(32))