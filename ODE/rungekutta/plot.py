import pandas as pd
import numpy as np
from datetime import datetime
import csv
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
headers = ['x','y']
df = pd.read_csv('./output.csv',names=headers)
df = df[1 : df.size]
print (df)
df['x'] = df['x'].astype("float")
df['y'] = df['y'].astype("float")


x = df['x']
y = df['y']

print(df.dtypes)

# plot
plt.plot(x,y)
plt.show()
