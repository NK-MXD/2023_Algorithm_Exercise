import random

# 生成 1000 个随机数
nums = []
for i in range(1000):
    # 随机生成数字的类型，0 表示十进制，1 表示十六进制
    num_type = random.randint(0, 1)
    
    # 生成随机数字
    if num_type == 0:
        # 生成十进制数字
        is_negative = random.choice([True, False])
        num_str = str(random.randint(0, 10**14))
        if is_negative:
            num_str = '-' + num_str
        num = int(num_str)
    else:
        # 生成十六进制数字
        num = hex(random.randint(0, 16**15))[2:].upper()
        # 添加十六进制前缀 '0x'
        num = '0x' + num
    
    nums.append(str(num))

# 将随机生成的数字写入文件
with open('output.txt', 'w') as f:
    for num in nums:
        f.write(num + '\n')
