import random
import string

# 生成 1000 个随机字符串
strs = []
for i in range(1000):
    length = random.randint(1, 15)
    chars = string.ascii_letters + string.digits + string.punctuation
    s = ''.join(random.choice(chars) for _ in range(length))
    
    strs.append(s)

# 将随机生成的字符串写入文件
with open('output.txt', 'w') as f:
    for s in strs:
        f.write(s + '\n')
