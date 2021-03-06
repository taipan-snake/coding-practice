#include <cstdio>

int main () {

    int numYears = 0;
    int years[200005];
    
    scanf ("%d", &numYears);
    
    for (int i = 0; i < numYears; i++) {
        scanf ("%d", &years[i]);
    }
    
    int numSequences = 0;
    int unknownCount = 0;
    int lastKnown = -1;
    int nextKnown = 0;
    int difference = 0;
    
    for (int i = 0; i < numYears; i++) {
        if (years[i] == -1) {
            unknownCount++;
        } else if ((years[i] - years[lastKnown]) != difference * (unknownCount + 1)) {
            numSequences++;
            if (lastKnown != -1) {
                difference = years[i] - years[lastKnown] / (unknownCount + 1);
            }
            unknownCount = 0;
        }
        
        if (unknownCount == 0) {
            lastKnown = i;
        }
    }
    
    printf ("%d\n", numSequences);
    
    return 0;
}
