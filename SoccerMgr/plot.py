import numpy as np
import matplotlib.pyplot as plt

values = np.loadtxt('plot_data')

x = values[:,0]
vendeur = values[:,1]
acheteur = values[:,2]

V, = plt.plot(x, vendeur, label='Vendeur', color='red')
A, = plt.plot(x, acheteur, label='Acheteur', color='blue')

plt.legend(handles=[V, A])

plt.ylabel('Montant')
plt.xlabel('temps')

plt.show()