# Name: Raj Randive
# Roll Number: 21BCP378

import time

startTime = time.time()

# graph = {
#     '1': {'2': 22, '3': 48, '4': 28},
#     '2': {'1': 22, '3': 20, '4': 18},
#     '3': {'1': 48, '2': 20, '4': 32},
#     '4': {'1': 28, '2': 18, '3': 32}
# }

graph = {
    "1": {"2": 2, "7": 6},
    "2": {"1": 2, "3": 7, "5": 2},
    "3": {"2": 7, "4": 3, "6": 3},
    "4": {"3": 3, "8": 2},
    "5": {"2": 2, "6": 2, "7": 1},
    "6": {"3": 3, "5": 2, "8": 2},
    "7": {"1": 6, "5": 1, "8": 4},
    "8": {"4": 2, "6": 2, "7": 4},
}

# Getting BFS Path
visited = []
queue = []
seq = []

start = input("Enter the starting node: ")
end = input("Enter the ending node: ")

visited.append(start)
queue.append(start)

while queue:
    curr = queue.pop(0)
    print(curr, end=", ")
    seq.append(curr)
    if curr == end:
        break

    for neighbor in graph[curr]:
        if neighbor not in visited:
            visited.append(neighbor)
            queue.append(neighbor)


# Calculating cost to reach the end state
count = 0
state = seq[count]
cost = 0

visited = []
visited.append(start)
neighbors = {}

for key in graph.keys():
    neighbors[key] = list(graph[key].keys())

while state != end:
    for key in neighbors[state]:
        if key not in visited:
            cost = cost + graph[state][key]
            visited.append(key)
        if key == end:
            break
    if key == end:
        break
    count = count + 1
    state = seq[count]

print(f"\nTotal cost is {cost}")

endTime = time.time()
print(f"Execution Time is {round(endTime - startTime, 2)}")
