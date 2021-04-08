import matplotlib.pyplot as plt

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Line:
    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2

points = open('points.txt')
lines = open('lines.txt')

point_lines = points.readlines()
lines_lines = lines.readlines()

x = []
y = []
segment_list = []

for point in point_lines:
    list = point.split(' ')
    x.append(int(list[0]))
    y.append(int(list[1]))

for segment in lines_lines:
    list = segment.split(' ')
    p1 = Point(int(list[0]), int(list[1]))
    p2 = Point(int(list[2]), int(list[3]))
    l = Line(p1, p2)
    segment_list.append(l)

for segment in segment_list:
    p1 = getattr(segment, 'p1')
    p2 = getattr(segment, 'p2')

    x1 = getattr(p1, 'x')
    y1 = getattr(p1, 'y')
    x2 = getattr(p2, 'x')
    y2 = getattr(p2, 'y')

    plt.plot([x1, x2], [y1, y2])

plt.scatter(x, y)
plt.show()