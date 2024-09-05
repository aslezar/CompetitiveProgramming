from collections import defaultdict

class City:
    def __init__(self, name, goods, tax):
        self.name = name
        self.goods = goods
        self.tax = tax

def compare_cities(c1, c2):
    city1 = Cities[c1]
    city2 = Cities[c2]
    if city1.goods != city2.goods:
        return city1.goods > city2.goods
    elif city1.tax != city2.tax:
        return city1.tax < city2.tax
    else:
        return city1.name < city2.name

def solve(start_city, m, visited, path, total_cost, no_of_cities):
    path.append(start_city)
    visited.add(start_city)
    total_cost[0] += Cities[start_city].tax

    for i in m[start_city]:
        if i not in visited:
            solve(i, m, visited, path, total_cost, no_of_cities)
            path.append(start_city)
            total_cost[0] += Cities[start_city].tax

n = int(input())
Cities = {}

graph = defaultdict(list)

start_city = ''
for i in range(n - 1):
    city1, city2, goods, tax = input().split()

    if i == 0:
        start_city = city1

    if city1 not in Cities:
        Cities[city1] = City(city1, 0, 0)
    if city2 not in Cities:
        Cities[city2] = City(city2, int(goods), int(tax))

    graph[city1].append(city2)

if n == 1:
    print(start_city)
    print(0)
    exit()

visited = set()
path = []
total_cost = [0]

for cities in graph.values():
    cities.sort(key=lambda x: compare_cities(x, x))

solve(start_city, graph, visited, path, total_cost, n)

print('-'.join(path))
print(total_cost[0])
