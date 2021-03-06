#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct location {

    double radius;
    int population;
};

bool sortFunction (location a, location b) {

    if (a.radius < b.radius) {
        return true;
    } else {
        return false;
    }
}

int main () {

    int numLocations, originalPop;
    int x, y;
    double radius = 0;
    location locations[1005];
    
    scanf ("%d %d", &numLocations, &originalPop);
    
    for (int i = 0; i < numLocations; i++) {
        scanf ("%d %d %d", &x, &y, &locations[i].population);
        locations[i].radius = sqrt ((x*x) + (y*y));
    }
    
    sort (locations, locations + numLocations, sortFunction);
    
    int i = 0;
    for (i = 0; i < numLocations; i++) {
        originalPop += locations[i].population;
        radius = locations[i].radius;
        if (originalPop >= 1000000) {
            break;
        }
    }
    
    if (i == numLocations) {
        printf ("-1\n");
    } else {
        printf ("%f\n", radius);
    }
    
    return 0;
}
