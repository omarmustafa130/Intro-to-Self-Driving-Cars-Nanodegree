#Given the list motions=[1,1] which means the robot 
#moves right and then right again, compute the posterior 
#distribution if the robot first senses red, then moves 
#right one, then senses green, then moves right again, 
#starting with a uniform prior distribution.

p=[0.2, 0.2, 0.2, 0.2, 0.2]
world=['green', 'red', 'red', 'green', 'green']
measurements = ['red', 'green']
motions = [1,1]
pHit = 0.6
pMiss = 0.2
pExact = 0.8
pOvershoot = 0.1
pUndershoot = 0.1
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
        s = pExact * p[(i-U)%no_of_possibilities]
        s = s + p[(i-U+1)%no_of_possibilities] * pUndershoot
        s = s + p[(i-U-1)%no_of_possibilities] * pOvershoot
        q.append(s)
    return q

for i in range(len(measurements)):
    p = sense(p, measurements[i])
    p = move(p, motions[i])
print p         
