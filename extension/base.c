/*
    Generate basic moving model
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
unsigned char background[3] = {255, 204, 204};
unsigned char target[3] = {0, 11, 255};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int rbound = 490;
int lbound = 150;
int ubound = 380;
int dbound = 100;
int target_x = 320;
int target_y = 240;
int target_size = 10;
void move(){
    int mv = rand() % 4;
    while(1){
        int newx = target_x + 3*dir[mv][0];
        int newy = target_y + 3*dir[mv][1];
        if(newx < rbound && newx > lbound
        && newy < ubound && newy > dbound){
            target_x = newx, target_y = newy;
            break;
        }else{
            mv = rand() % 4;
        }
    }
}
int main(){

    int i, j;
    unsigned long long c = 0;
    srand(time(0));
    int msec = 0, trigger = 100; /* 0.1s */
    clock_t before = clock();

    while (1)
    {
        for (j = 0; j < 480; j++) {
            for (i = 0; i < 640; i++) {

                if((i >= target_x) && (target_x + target_size >= i)
                && (j >= target_y) && (target_y + target_size >= j)){
                    fwrite(target, sizeof(target), 1, stdout);
                }else{
                    fwrite(background, sizeof(background), 1, stdout);
                }
                clock_t difference = clock() - before;
                msec = difference * 1000 / CLOCKS_PER_SEC;
                if(msec > trigger){
                    move();
                    msec = 0;
                    before = clock();
                }
            }
        }
        //break;
    }
    return 0;
}