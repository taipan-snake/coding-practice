#include <cstdio>

int main () {

    int numApples = 0;
    int num100 = 0;
    int num200 = 0;
    int num = 0;
    
    scanf ("%d", &numApples);
    
    for (int i = 0; i < numApples; i++) {
        scanf ("%d", &num);
        
        if (num == 100) {
            num100++;
        } else if (num == 200) {
            num200++;
        }
    }
    
    if ((num100 % 2 == 0 && num200 % 2 == 0) ||
        (num100 % 2 == 0 && num100 >= 2 && num200 & 2 != 0)) {
        printf ("YES\n");
    } else {
        printf ("NO\n");
    }
    
    return 0;
}
