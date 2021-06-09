import fileinput

for line in fileinput.input():
    data = line.strip().split(",")
    if len(data) == 6:
        country, continent, year, lifeExpectancy, population, gdpPerCapita = data
        if country != "country":
            print("{0}\t{1}".format(country, int(population)))
