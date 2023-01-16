#Program a function that returns a new distribution 
#q, shifted to the right by U units. If U=0, q should 
#be the same as p.

p=[0, 1, 0, 0, 0]
world=['green', 'red', 'red', 'green', 'green']
measurements = ['red', 'green']
pHit = 0.6
pMiss = 0.2
no_of_possibilities = len(p)

def sense(p, Z):
    q=[]
    hit = 0
    sum=0.0
    for i in range(no_of_possibilities):
        hit = (Z == world[i])
        q.append(p[i] * (hit * pHit + (1-hit) * pMiss))
        sum+=q[i]
    for k in range(no_of_possibilities):
        q[k] = q[k] / sum
    return q

def move(p, U):
    q=[]
    for i in range(no_of_possibilities):
        q.append(p[(i-U)%no_of_possibilities])
    return q

print move(p, 1)
