#include <stdio.h>
#include <stdbool.h>
int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year){
  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
    return true;
  } else {
    return false;
  }
}

void add_days_to_date(int* mm, int* dd, int* yy, int days_left_to_add){
  printf("Inputted date %d/%d/%d\nAdding %d days\n",*mm,*dd,*yy, days_left_to_add);
  
  int days_left_in_month;

  while (days_left_to_add > 0) {
    //Checks how many days are in the month. Then subtracts the current date (since these days have already passed).
    days_left_in_month = days_in_month[*mm] - *dd;
    
    //Check for leap year
    if (*mm == 2 && is_leap_year(*yy)) {
        days_left_in_month++;
      }
    
    //Checks if we need have overflow to the next month/year
    if (days_left_to_add > days_left_in_month) {
        //Decrement by the amount left in the month.
        days_left_to_add -= days_left_in_month;
        //Resets the day to the 1st of the next month.
        days_left_to_add--;
        *dd = 1;
      //Checks if the month is December
      if (*mm == 12) {
        //Increases the year by 1, and sets the month back to January
        *mm = 1;
        *yy += 1;
      } else {
        //Otherwise just increment the month by 1
        *mm += 1;
      }
    //Else we stay in the present month
    } else {
        //Sets the day to what we have left
        *dd += days_left_to_add;
        //Then removes days_left_to_add to end the While loop
        days_left_to_add = 0;
    }
  }

  printf("The new date is: %d/%d/%d\n", *mm,*dd,*yy);
}

int main() {
  int mm;
  int dd;
  int yy;
  int days_left_to_add;

  printf("Please enter a date between the years 1800 and 10000 in the format mm dd yy days_to_add and provide the number of days to add to this date:\n");

  scanf("%d %d %d %d", &mm, &dd, &yy, &days_left_to_add);
  
  add_days_to_date(&mm, &dd, &yy, days_left_to_add);

}
