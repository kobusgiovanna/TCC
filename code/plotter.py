import matplotlib.pyplot as plt
plt.style.use('seaborn-whitegrid')
import numpy as np

fig = plt.figure()

ax = fig.add_subplot(111)

ax.set_xlim([-500000, 500000])
ax.set_ylim([-500000, 500000])

x = np.linspace(-500000, 500000, 1000000)

n = int(input())

xr=[]
yr=[]

for i in range (n):
	xi, yi = map(float, input().split(" "))
	xr.append(xi)
	yr.append(yi)

plt.scatter(xr, yr, color='r')

xb=[]
yb=[]

n = int(input())

for i in range (n):
	xi, yi = map(float, input().split(" "))
	xb.append(xi)
	yb.append(yi)

plt.scatter(xb, yb, color='b')

m, b = map(float, input().split(" "))


plt.plot(x, m*x + b, color='g')

plt.show()

