#Modify the move function to accommodate the added 
#probabilities of overshooting or undershooting 
#the intended destination.

p=[0, 1, 0, 0, 0]
world=['green', 'red', 'red', 'green', 'green']
measurements = ['red', 'green']
no_of_possibilities = len(p)
pHit = 0.6
pMiss = 0.2
pExact = 0.8
pOvershoot = 0.1
pUndershoot = 0.1


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
    

print move(p, 1)
