#include <stdio.h>

int main() {
    int day, month, year, i;
    char exitOption;
    
    while (1) {
        printf("Enter the date:\n");
        printf("Day: "); scanf("%d", &day);
        printf("Month: "); scanf("%d", &month);
        printf("Year: "); scanf("%d", &year);
        
        // Calculate contributions of each month to the total days
        int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            monthDays[2] = 29;
        }
        
        int totalDays = 0;
        
        // Add contributions of previous months
        for (i = 1; i < month; i++) {
            totalDays += monthDays[i];
        }
        
        // Add the entered day
        totalDays += day;
        
        // Add contributions of previous years
        for (i = 1; i < year; i++) {
            totalDays += 365;
            
            // Check for leap year
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
                totalDays += 1;
            }
        }
        
        // Find the day of the week
        int dayOfWeek = totalDays % 7;
        
        switch (dayOfWeek) {
            case 0:
                printf("Sunday\n");
                break;
            case 1:
                printf("Monday\n");
                break;
            case 2:
                printf("Tuesday\n");
                break;
            case 3:
                printf("Wednesday\n");
                break;
            case 4:
                printf("Thursday\n");
                break;
            case 5:
                printf("Friday\n");
                break;
            case 6:
                printf("Saturday\n");
                break;
        }
        
        printf("Do you want to exit? (y/n): ");
        scanf(" %c", &exitOption);
        
        if (exitOption == 'y' || exitOption == 'Y') {
            break; // Döngüden çýkýþ yap
        }
    }
    
    return 0;
}

