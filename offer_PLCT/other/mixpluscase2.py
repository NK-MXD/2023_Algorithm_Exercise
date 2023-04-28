import random
import string

# 生成 1000 个随机字符串
strs = []
for i in range(1000):
    while True:
        # 随机生成字符串
        length = random.randint(1, 15)
        chars = string.ascii_letters + string.digits + string.punctuation
        s = ''.join(random.choice(chars) for _ in range(length))
        
        # 检查字符串是否为十进制或十六进制数
        if not (s.isdigit() or (s.startswith('0') and s[1:].isdigit()) or (s.startswith('-0') and s[2:].isdigit())
                or (s.startswith('0x') and all(c in string.hexdigits for c in s[2:])) 
                or (s.startswith('-0x') and all(c in string.hexdigits for c in s[3:]))):
            break
    
    strs.append(s)

# 将随机生成的字符串写入文件
with open('output.txt', 'w') as f:
    for s in strs:
        f.write(s + '\n')
