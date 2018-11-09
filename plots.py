import numpy as np 
import matplotlib.pyplot as plt 


Datos = np.loadtxt('tiempo_c.txt')

tiempo = Datos
particiones = np.array([1, 10, 20, 50, 100])

plt.plot(particiones, np.log(tiempo))
plt.title('Tiempo en funcion del numero de particiones')
plt.xlabel('Numero de Particiones')
plt.ylabel('log(tiempo)')
plt.savefig('Tiempo en funcion del numero de particiones.pdf')
# plt.show()
