import numpy as np
import pandas as pd

df = pd.read_csv(
    "/home/kaustav/Desktop/Kaustav-CSE-LABS-and-Projects/Sem06-Distributed-Systems-LAB/WEEK 05/resources/example.txt", sep="\t", names=["date", "time", "city", "items", "sales", "card_type"])

# for x in list(df["city"]):
#     print(x, sum(df[df['city'] == x]['sales']))


for a, b in zip(df.city, df.sales):

    print("{0}\t{1}".format(a, b))
