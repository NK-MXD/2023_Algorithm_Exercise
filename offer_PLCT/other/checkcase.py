import random
import math

# 生成 400 个随机的双精度浮点数
numbers = []
for i in range(400):
    num = random.uniform(-1.7E+10, 1.7E+10)
    while math.isnan(num) or math.isinf(num):
        num = random.uniform(-1.7E+10, 1.7E+10)
    numbers.append(num)

# 将数据写入到 output.txt 文件中
with open('output.txt', 'w') as f:
    for num in numbers:
        f.write(str(num) + '\n')
