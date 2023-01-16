#Modify the code so that it updates the probability twice
#and gives the posterior distribution after both 
#measurements are incorporated. Make sure that your code 
#allows for any sequence of measurement of any length.

p=[0.2, 0.2, 0.2, 0.2, 0.2]
world=['green', 'red', 'red', 'green', 'green']
measurements = ['red', 'green']
pHit = 0.6
pMiss = 0.2

def sense(p, Z):
    q=[]
    hit = 0
    no_of_possibilities = len(p)
    sum=0.0
    for i in range(no_of_possibilities):
        hit = (Z == world[i])
        q.append(p[i] * (hit * pHit + (1-hit) * pMiss))
        sum+=q[i]
    for k in range(no_of_possibilities):
        q[k] = q[k] / sum
    return q

for measurement in measurements:
    p=sense(p, measurement)
print p
