import math

s = "static const float freqTable[88] = { "
for i in range(1, 89):
    f = math.pow(2.0, (i - 49)/12) * 440.0
    s += str(f) + ',\n'

s = s[:-2]
s += "}"

with open("frequencies.txt", 'w') as f:
    f.write(s)




