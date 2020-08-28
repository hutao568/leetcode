import dis
def foo():
    a=2
    b=3
    c=a+b
    return c

if __name__ == '__main__':

    dis.dis(foo)