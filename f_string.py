name='Huahua'
score=123.456789

print('name= '+name+',score= '+str(score))
# %占位符 s/.3f代表格式
# 格式为'%格式'% (tuple)按照顺序替代 C风格
print('name = %s,score= %.3f'%(name,score))
# 传入key-word format 表达式里面的key就被替代了，后面的value可以是变量，常量
print('name={name},score={score:.3f}'.format(name=name,score=score))
print('name={name},score={score:.3f}'.format(name='Huahua',score=123.456789))

# Python 3.6以后引入f-string(formatted string literal 格式化字符串字面值)

print(f'name={name},score={score:.3f}')

# Python 3.8 和上述结果一样
# 内部实现，利用反射机制
print(f'{name=},{score=:.3f}')
