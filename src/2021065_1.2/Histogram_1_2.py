import matplotlib.pyplot as plt
import numpy as np

f=open("Question_1_2_values","r")
values=[]
values=f.readlines()
val=[]
for i in range(0,3):
    val.append(float(values[i][11:18]))
fig=plt.subplots(figsize=(12,8))
plt.bar(25,val[-1],color='maroon',width=4,label='OTHER')
plt.bar(50,val[1],color='blue',width=4, label='RR' )
plt.bar(75,val[0],color='green',width=4, label='FIFO')
plt.xlabel("Priority=50")
plt.ylabel("Time taken in sec")
plt.title("Question-1.2")
plt.legend()
plt.show() 
