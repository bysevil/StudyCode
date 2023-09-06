#include<stdio.h>

int leapyear(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return 1;
    else
        return 0;
}



int GetDaysOfYear(int year,int month,int day) {
    switch (month){
        case 12:
            day += 30;
        case 11:
            day += 31;
        case 10:
            day += 30;
        case 9:
            day += 31;
        case 8:
            day += 31;
        case 7:
            day += 30;
        case 6:
            day += 31;
        case 5:
            day += 30;
        case 4:
            day += 31;
        case 3:
            if (leapyear(year)) day += 29;
            else day += 28;
        case 2:
            day += 31;
    }
    return day;
}


int main() {
    int year,month,day;
    scanf("%d %d %d",&year,&month,&day);
    printf("%d", GetDaysOfYear(year,month,day));
    return 0;
}