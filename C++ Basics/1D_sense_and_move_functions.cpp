
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;



vector<double> sense(vector<double>p, string Z, vector<string> world, double pHit, double pMiss)
{
    vector<double> q;
    bool hit = false;
    double s = 0.0;
    for(int i = 0; i<p.size(); i++)
    {
        hit = (Z == world[i]);
        q.push_back(p[i] * (hit * pHit + (1-hit) * pMiss));
        s+=q[i];
    }
    for(int i = 0; i<q.size(); i++)
    {
        q[i] = q[i] / s;
    }
    return q;
}

vector<double> move(vector<double>p, int U, double pExact, double pOvershoot, double pUndershoot)
{
    vector<double> q;
    double s = 0;
    for(int i = 0; i<p.size(); i++)
    {
        if (i-U < 0) {
            s = pExact * p[(i-U) + p.size()];
        }
        else {
            s = pExact * p[(i-U) % p.size()];
        }
        if (i-U-1 < 0) {
            s = s + pOvershoot * p[(i-U-1) + p.size()];
        }
        else {
            s = s + pOvershoot * p[(i-U-1) % p.size()];
        }
        if (i-U+1 < 0) {
            s = s + pUndershoot * p[(i-U+1) + p.size()];
        }
        else {
            s = s + pUndershoot * p[(i-U+1) % p.size()];
        }

        q.push_back(s);
    }


    return q;
}


int main()
{
    vector<double> p(5, 0.2);
    vector <string> world = {"green", "red", "red", "green", "green"};
    vector <string> measurements = {"red", "green"};
    vector<double> motions (2,1);
    vector<double>p_final;
    for (int k = 0; k<measurements.size(); k++)
    {
        p = sense(p, measurements[k],world, 0.6, 0.2);
        p = move(p, motions[k], 0.8, 0.1, 0.1);
    }

    for (int i = 0; i<p.size(); i++)
    {
        cout<<p[i]<<" ";
    }

    return 0;
}


