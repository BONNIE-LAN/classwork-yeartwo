import math
def distance(**dot):
    point1_keys=sorted([k for k in dot.keys() if k.endswith('1')])
    point2_keys=sorted([k for k in dot.keys() if k.endswith('2')])
    sum_of_squares=0
    x_distance=0
    for k1,k2 in zip(point1_keys,point2_keys):
        diff=dot[k1]-dot[k2]
        sum_of_squares+=diff**2
        if k1=='x1' and k2=='x2':
            x_distance=abs(diff)
    total_distance=math.sqrt(sum_of_squares)
    return x_distance,total_distance