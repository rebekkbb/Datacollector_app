import numpy as np
import matplotlib.pyplot as plt

polarID= "75157825"

datafile=np.loadtxt(polarID+"-rrs.txt",delimiter=',')
x=datafile[:,0]
y=datafile[:,1]

plt.plot(x,y)
plt.show()