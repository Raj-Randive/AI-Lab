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

# Getting DFS path
visited = []
stack = []
seq = []

start = input("Enter the starting node: ")
end = input("Enter the ending node: ")

visited.append(start)
stack.append(start)

while stack:
    curr = stack.pop()
    print(curr, end=", ")
    seq.append(curr)
    visited.append(curr)
    if curr == end:
        break

    temp = []
    for neighbor in graph[curr]:
        if neighbor not in visited:
            temp.append(neighbor)
    temp = temp[::-1]
    stack.extend(temp)


# Calculating min cost for the path
count = 0
state = seq[count]
cost = 0

visited = []
visited.append(start)
neighbors = {}

for key in graph.keys():
    neighbors[key] = list(graph[key].keys())

while state != end:
    for i in seq:
        state = seq[count]
        next = seq[count + 1]
        cost = cost + graph[state][next]
        if next in neighbors[state]:
            if next == end:
                break
            count = count + 1
        else:
            count = count - 1
    if next == end:
        break

print(f"\nTotal cost is {cost}")

endTime = time.time()
print(f"Execution Time is {round(endTime - startTime, 2)}")
