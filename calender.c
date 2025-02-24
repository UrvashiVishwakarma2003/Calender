#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int get_1st_weekDay(int year){
    int d;
    d = (year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    return d;
}

int main(){
    int year,month,day,daysInMonth,weekDay=0,startingDay;
    printf("\n Enter you desired year : ");
    scanf("%d",&year);

    char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //this is a case of leap year 
    if((year%4==0&&year%100!=0)||year%400==0) 
    monthDay[1]=29;
    
    startingDay = get_1st_weekDay(year);
    for(month=0;month<12;month++){

        daysInMonth=monthDay[month];
        printf("\n\n-------------------%s----------------------\n",months[month]);
        printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat \n");

        for(weekDay=0;weekDay<startingDay;weekDay++){
            printf("     ");
        }

        for(day=1;day<=daysInMonth;day++){
            printf("%5d",day);              //5d means spacing numbers

            if(++weekDay>6){
                printf("\n");
                weekDay=0;
            }
            startingDay = weekDay;
        }
    }
    return 0;
}