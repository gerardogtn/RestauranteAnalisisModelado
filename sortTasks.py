# A simple python program that reads Tasks.csv and prints the tasks sorted
# first by descending priority and then by ascending length.
import csv

class Task(object):
    def __init__(self, id, priority, length):
        self.id = id
        self.priority = priority
        self.length = length

    def __eq__(self, other):
        return self.id == other.id

    def __lt__(self, other):
        return self.priority > other.priority or self.length < other.length

    def __str__(self):
        return self.id + ", " + str(self.priority) + ", " + str(self.length)

with open('Tasks.csv', 'r') as csvfile:
    reader = csv.DictReader(csvfile)
    tasks = []
    for row in reader:
        if (int(row['Completed']) == 0):
            task = Task(row['ID'], int(row['Priority']), int(row['Length']))
            tasks.append(task)
    for task in sorted(tasks):
        print task
