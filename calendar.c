#include <stdio.h>

int getDayOfWeek_FirstDay(int month,int year) /*一ヶ月の最初の曜日判定*/
{
  int firstday;
  if(month==1){
    year=year-1;
    month=13;
  }
  else if(month==2){
    year=year-1;
    month=14;
  }
  return (5*year/4-year/100+year/400+(26*month+16)/10+1)%7;
  /* 0=日曜日 ... １月２月はmonth=13,14とする */
}

int is_leap_year(int year) /*閏年の判定*/
{
  int rc=0;
  if(year%4==0 && (year%100 != 0 || year%400 ==0)){
    rc=1;
  }
  return rc;
}

int getEndDayOfMonth(int month,int year) /*一ヶ月の最後が何日か*/
{
  int number=0,last[]={31,28,31,30,31,30,31,31,30,31,30,31};
  if(month==2){
    number=last[month-1]+ is_leap_year(year);
  }
  else if(month>=1 && month<=12){
    number=last[month-1];
  }
  return number;
}


int getNumberOfWeek(int month,int year) /*その週が一年で何週目か*/
{
  int number,i,j=0,m[]={1,3,4,5,6,7,8,9,10,11,12};
  
  for(i=0;m[i]<month;i++)
    {
      if((getDayOfWeek_FirstDay(m[i],year)==5 || getDayOfWeek_FirstDay(m[i],year)==6) && getEndDayOfMonth(m[i],year)==31)
	{
	  j=j+1;
	  
	}
      else if(getDayOfWeek_FirstDay(m[i],year)==6 && getEndDayOfMonth(m[i],year)==30)
	{
	  j=j+1;
	}
    }

  if(is_leap_year(year)==1 && month==3)
    {
	  return 11+j;
    }
  else if(is_leap_year(year)==1 && month>3)
    {
      return 16+(month-4)*5+j;
    }
  else if((is_leap_year(year)==0)&&(getDayOfWeek_FirstDay(2,year)==0))
    {
      if(month>3){return 15+(month-4)*5+j;}
      else if(month==3){return 10+j;} 
    }
  else if((is_leap_year(year)==0)&&(getDayOfWeek_FirstDay(2,year)!=0))
    {
      if(month>3){return (16+j)+(month-4)*5;}
      else if(month==3){return 11+j;}
    }
  if(month==1){return 1;}
  if(month==2){return 6+j;}
  
return 0;

}


void printMonthName(int month,int year){
  
  if(month==1)printf("January %d\n",year);
  if(month==2)printf("February %d\n",year);
  if(month==3)printf("March %d\n",year);
  if(month==4)printf("April %d\n",year);
  if(month==5)printf("May %d\n",year);
  if(month==6)printf("June %d\n",year);
  if(month==7)printf("July %d\n",year);
  if(month==8)printf("August %d\n",year);
  if(month==9)printf("September %d\n",year);
  if(month==10)printf("October %d\n",year);
  if(month==11)printf("November %d\n",year);
  if(month==12)printf("December %d\n",year);

}
void printMonthCalendar(int month,int year)
{
  int i,j=1,e,w;

  w=getDayOfWeek_FirstDay(month,year);
  e=getEndDayOfMonth(month,year);
  printf("%d:",getNumberOfWeek(month,year));
  for(i=1;i<=w;i++)
    {
      printf("   ");
    }
  for(i=1;i<=e;i++)
    {
      printf(" %2d",i);
      if((i+w)%7==0)
	{
	  putchar('\n');
	  if(i==e){ break; }
	  printf("%d:",getNumberOfWeek(month,year)+j);
	    j++;
	}
    }
  printf("\n");
}
