# -*- coding: UTF-8
import sys
import tokenize

class Token:
    def __init__(self,tok_num,tok_value):
        self.toknum=tok_num
        self.tokvalue=tok_value

global current_token

def current():
    global current_token
    return current_token

def next(tk):
    # 生成当前token 对象
    toknum,tokvalue,_,_,_=tk.next()
    global current_token
    current_token=Token(toknum,tokvalue)

def expr(tk):
    # expr由n个term相加得到，与term差不多
    s1=term(tk)
    toknum,tokvalue=current().toknum,current().tokvalue

    value=s1

    while tokvalue=="+" or  tokvalue=="-":
        next(tk)
        s2=term(tk)

        if tokvalue=="+":
            value+=s2
        elif tokvalue=="-":
            value-=s2
        toknum,tokvalue=current().toknum,current().tokvalue

    return value

def term(tk):
    # term 由n个factor相乘得到
    f1=factor(tk)
    toknum,tokvalue=current().toknum,current().tokvalue

    value=f1

    while tokvalue=="*" or  tokvalue=="/":

        # 跳过当前token，即符号位
        next(tk)
        # factor结束的时候调用了next，所以调用factor后当前token为符号
        f2=factor(tk)
        if tokvalue=="*":
            value*=f2
        elif tokvalue=="/":
            value/=f2

        toknum,tokvalue=current().toknum,current().tokvalue

    return value

def factor(tk):
    # factor只有数字或者(表达式)
    if current().toknum==tokenize.NUMBER:
        value=current().tokvalue
        next(tk)
    elif current().toknum=="(":
        next(tk)
        f=expr(tk)

        if current().tokvalue!=")":
            print 'error kuohao pipei'
        value=f
        next(tk)
    return int(value)

if __name__ == '__main__':
    files=open('token.txt')
    tk=tokenize.generate_tokens(files.readline)
    # tk 是token生成器
    next(tk)
    print(expr(tk))