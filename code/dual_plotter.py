import matplotlib.pyplot as plt
plt.style.use('seaborn-whitegrid')
import numpy as np

fig = plt.figure()

ax = fig.add_subplot(111)

ax.set_xlim([-100, 100])
ax.set_ylim([-100, 100])

x = np.linspace(-100, 100, 200)

n = int(input())

for i in range (n):
	m, b = map(float, input().split(" "))
	plt.plot(x, m*x - b, color='r')


n = int(input())

for i in range (n):
	m, b = map(float, input().split(" "))
	plt.plot(x, m*x - b, color='b')

xi, yi = map(float,input().split(" "))

plt.scatter([xi], [-yi], color='g')

plt.show()

