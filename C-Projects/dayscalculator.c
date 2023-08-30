#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}

// Function to calculate the total days passed until the given date
int calculateTotalDays(int day, int month, int year) {
    int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays = 0, i;
    
    // Add contributions of previous years
    for (i = 1; i < year; i++) {
        totalDays += 365 + isLeapYear(i);
    }
    
    // Add contributions of previous months
    for (i = 1; i < month; i++) {
        totalDays += monthDays[i];
    }
    
    // Add the entered day
    totalDays += day;
    
    // Adjust for leap year
    if (month > 2 && isLeapYear(year)) {
        totalDays += 1;
    }
    
    return totalDays;
}

// Function to find the day of the week
void findDayOfWeek(int totalDays) {
    char* daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int dayOfWeek = totalDays % 7;
    printf("Day of the week: %s\n", daysOfWeek[dayOfWeek]);
}

int main() {
    int day, month, year;
    char exitOption;
    
    while (1) {
        printf("Enter the date:\n");
        printf("Day: "); scanf("%d", &day);
        printf("Month: "); scanf("%d", &month);
        printf("Year: "); scanf("%d", &year);
        
        int totalDays = calculateTotalDays(day, month, year);
        findDayOfWeek(totalDays);
        
        printf("Do you want to exit? (y/n): ");
        scanf(" %c", &exitOption);
        
        if (exitOption == 'y' || exitOption == 'Y') {
            break;
        }
    }
    
    return 0;
}

