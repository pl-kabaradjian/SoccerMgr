import numpy as np
import matplotlib.pyplot as mplot

data = np.loadtxt('plot_data')

t = data[:,0]
acheteur = data[:,1]
vendeur = data[:,2]
v_data, = mplot.plot(t, vendeur, label='Vendeur')
a_data, = mplot.plot(t, acheteur, label='Acheteur')
mplot.xlabel('Echanges')
mplot.ylabel('Montant')
mplot.legend(handles=[v_data, a_data])
mplot.show()