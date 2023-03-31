import numpy as np
import matplotlib.pyplot as plt
import matplotlib.dates as mdatest
from matplotlib.ticker import (MultipleLocator, FormatStrFormatter, AutoMinorLocator)
import math

data = np.fromfile ("./data.txt", dtype = np.float32, sep = '\n')
print (data)

settings = np.fromfile ("./settings.txt", dtype = np.float32, sep = "\n")
print (settings)

dt = 1 / settings[0]
time = np.linspace (0, dt * (len (data) - 1), len (data))

fig, ax = plt.subplots(figsize=(8, 6))

ax.set_title("Процесс зарядки и разрядки конденсатора в RC-цепочке", fontsize=16, color="darkblue")

ax.set(xlim=(0, 60), ylim=(0, 3))

ax.set_xlabel("Время t, c", fontsize=14, color="brown")        
ax.set_ylabel("Напряжение U, В", fontsize=14, color="brown")

ax.grid(which="major", linewidth=1, color="green")
ax.grid(which="minor", linestyle="--", color="darkblue", linewidth=0.5)

#ax.scatter(x, y1, c="red", label="y1 = 4*x")
ax.plot (time, data / 256 * 3.3, label = "V(t)", color="red")

text_kwargs = dict(fontsize=12)

ax.text (40, 1.8, "Время заряда = %.2fc" % (time[data.argmax()]), **text_kwargs)
ax.text (40, 1.6, "Время разряда = %.2fc" % (time[len(time) - 1] - time[data.argmax()]), **text_kwargs)

ax.legend()

ax.xaxis.set_minor_locator(AutoMinorLocator())
ax.yaxis.set_minor_locator(AutoMinorLocator())

ax.tick_params(which='major', length=10, width=2)
ax.tick_params(which='minor', length=5, width=1)

plt.savefig("plot.svg", bbox_inches='tight')

plt.show()

plt.close()