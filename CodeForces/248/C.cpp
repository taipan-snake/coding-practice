#include <iostream>
#include <cmath>

using namespace std;

int main () {

    int n, m;
    int p[10005];
    
    int maxBenefit = 10000;
    int maxIndex = 0;
    
    int t = 0;
    
    p[0] = 0;
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> p[i + 1];
        
        if (i > 1) {
            // if ((p[i] - p[i - 1]) + (p[i] - p[i + 1]) > maxBenefit) {
            if ((int) abs(p[i + 1] - p[i - 1]) < maxBenefit) {
                // maxBenefit = ((p[i] - p[i - 1]) + (p[i] - p[i + 1]));
                maxBenefit = (int) abs(p[i + 1] - p[i - 1]);
                maxIndex = i;
            }
        }
    }
    
    int benefit = 0;
    if (p[maxIndex - 1] < p[maxIndex] && p[maxIndex] < p[maxIndex + 1] ||
        p[maxIndex - 1] > p[maxIndex] && p[maxIndex] > p[maxIndex + 1]) {
        benefit = 0;
    } else if ((int) abs(p[maxIndex] - p[maxIndex - 1]) <= (int) abs(p[maxIndex] - p[maxIndex + 1])) {
        benefit = (int) abs (2 * (p[maxIndex] - p[maxIndex - 1]));
    } else {
        benefit = (int) abs (2 * (p[maxIndex] - p[maxIndex + 1]));
    }
    
    int changed = 0;
    
    // cout << benefit << endl;
    
    if ((int) abs(p[1] - p[2]) > benefit && (int) abs(p[1] - p[2]) > (int) abs(p[m] - p[m - 1])) {
        // maxBenefit = (int) abs(p[1] - p[2]);
        // maxIndex = 1;
        p[1] = p[2];
        changed = 1;
    }
    
    if ((int) abs(p[m] - p[m - 1]) > benefit) {
        p[m] = p[m - 1];
        changed = 1;
    } 
    
    if (changed == 0) {
        p[maxIndex] = p[maxIndex - 1];
    }
    
    for (int i = 2; i <= m; i++) {
        t += (int) abs(p[i] - p[i - 1]);
        // cout << p[i] << " ";
    }
    
    cout << t << endl;
    
    return 0;
}
