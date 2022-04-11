#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main()
{
    while(1) {
        srand(time(NULL));
        
        int grade1[100]={0, };
        int grade2[100]={0, };
        int partner[100];
        
        int i, r;
        
        for(i = 1; i <= 21; i++) grade1[i - 1] = 1100 + i;
        for(i = 1; i <= 20; i++) grade1[i + 20] = 1200 + i;
        for(i = 1; i <= 20; i++) grade1[i + 40] = 1300 + i;
        for(i = 1; i <= 21; i++) grade1[i + 60] = 1400 + i;

        for(i = 1; i <= 20; i++) grade2[i - 1] = 2100 + i;
        for(i = 1; i <= 20; i++) grade2[i + 19] = 2200 + i;
        for(i = 1; i <= 19; i++) grade2[i + 39] = 2300 + i;
        for(i = 1; i <= 19; i++) grade2[i + 58] = 2400 + i;

        i = 0;
        do {
            r = rand() % 82;
            if(grade1[r] == 0) continue;
            partner[i++] = grade1[r], grade1[r] = 0;
        } while(i < 78);
        
        for(i = 0; i < 78; i++) printf("%d -- %d\n", grade2[i], partner[i]);

        for(i = 0; i < 82; i++)
            if(grade1[i]) printf("%d ", grade1[i]);
    
        int flag = getch();
        if(flag == 27) break;
    }
    return 0;
}