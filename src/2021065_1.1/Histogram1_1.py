import matplotlib.pyplot as plt
import numpy as np

f=open("Time_Taken.txt","r")
values=[]
values=f.readlines()

list_RR=[]
list_FIFO=[]
list_OTHER=[]


for i in range(0,30):
 
        if values[i][0]=="r":
            list_RR.append(float(values[i][3:8]))
        elif values[i][0]=="f":
                list_FIFO.append(float(values[i][3:8]))
        else:
                list_OTHER.append(float(values[i][3:8]))


list_priority=[2,4,6,8,10,12,14,16,18,20]
bar_RR=[i+0.5 for i in list_priority]
bar_FIFO=[i+1 for i in list_priority ]

fig=plt.subplots(figsize=(12,8))
plt.bar(list_priority,list_OTHER,color='maroon',width=0.50,label='OTHER')
plt.bar(bar_RR,list_RR,color='blue',width=0.50, label='RR' )
plt.bar(bar_FIFO,list_FIFO,color='green',width=0.50, label='FIFO')
plt.xlabel("Priority")
plt.ylabel("Time taken in sec")
plt.title("Question-1.1")
plt.legend()
plt.show()
