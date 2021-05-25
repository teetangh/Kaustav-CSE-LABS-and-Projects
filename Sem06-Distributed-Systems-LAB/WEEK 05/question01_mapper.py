import numpy as np
import pandas as pd

df = pd.read_csv(
    "/home/kaustav/Desktop/Kaustav-CSE-LABS-and-Projects/Sem06-Distributed-Systems-LAB/WEEK 05/resources/covid_19_data.csv")
# print(df.sample(15))


hashMap = {}

for x in df["Country/Region"]:
    # print(x)
    if x in hashMap:
        hashMap[x] += 1
    else:
        hashMap[x] = 0


for (key, value) in hashMap.items():
    print(key, value)
