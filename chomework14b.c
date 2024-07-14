#include <stdbool.h>
#include <stdio.h>
#include <Windows.h>

struct Time{
    int Time;
}typedef Time;

Time settime(Time time ,int second, int minute, int hour){ 

    time.Time = (hour*60*60) + (minute*60) + (second);
    return time;
}

Time tick(Time time){
    time.Time--;
    Sleep(1000);
    return time;
}
bool iszero(Time time){
    return (time.Time == 0 ? true : false);
}
// if time.Time and timeS are set to zero, must have second, minute and hour. otherwise you can set only time.Time or timeS, and set the rest to zero

void displaytime(Time time){
    int hour, minute, second;
    hour = time.Time/3600;
    minute = (time.Time/60) - (hour*60);
    second = time.Time - (minute*60) - (hour*60*60);
    printf("%02d:%02d:%02d %08x\n", hour, minute, second, time.Time);
}
void countdown(Time time, int amount ,int second, int minute, int hour){
    if (hour == 0 && second == 0 && minute == 0 && amount == 0){
        scanf("%d %d %d %d", &amount, &hour, &minute, &second);
    }
    time = settime(time, second, minute, hour);
    displaytime(time);
    for (int i = 0; i < amount; i++){
        
        time = tick(time);
        displaytime(time);
        if (iszero(time)){
            time = settime(time, 0, 0, 12);
        }
    }
}



int main(){
    printf("Countdown\n\n");
    Time clockTime = {0};
    printf("countdown(\"3 seconds down to zero\")\n");
    countdown(clockTime,3,3,0,0);
    printf("countdown(\"7 minutes 2 seconds for 6 seconds\")\n");
    countdown(clockTime,6,2,7,0);
    printf("countdown(\"l hour 2 seconds for 5 seconds\")\n");
    countdown(clockTime,5,2,0,1);
    printf("countdown(\"2 seconds for 5 seconds\", 5, O, 0, 2)\n");
    countdown(clockTime,5,2,0,0);
    
}