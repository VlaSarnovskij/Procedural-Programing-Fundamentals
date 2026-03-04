#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 256

// Cheking if the year is leap
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Cheking if data is correct
int is_valid_date(int year, int month, int day) {
    if (year < 1 || month < 1 || month > 12 || day < 1) return 0;

    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && is_leap_year(year)) days_in_month[1] = 29;

    return day <= days_in_month[month-1];
}

// Zeller's formula (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
int day_of_week(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int K = year % 100;
    int J = year / 100;
    int h = (day + 13*(month+1)/5 + K + K/4 + J/4 + 5*J) % 7;
    int d = (h + 6) % 7;
    return d;
}

int main() {
    char buffer[CAPACITY];
    int year, month, day;

    printf("Programme will print what day of a week by the date.\n");
    printf("Enter date (YYYY-MM-DD format):\n");

    // Reading data and validation
    while(1){
        scanf("%s", buffer);

        // Clearing buffer
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);

        // Validation
        if (sscanf(buffer, "%d-%d-%d", &year, &month, &day) == 3) {
            if (is_valid_date(year, month, day)) break;
            else printf("Error: invalid date. Try again.\n");
        } else {
            printf("Error: wrong format. Try again.\n");
        }
    }

    // Reading the week names from the file 'week.txt'
    char week_days[7][20];
    FILE *fp = fopen("week.txt", "r");
    for (int i = 0; i < 7; i++) {
        if (!fgets(week_days[i], 20, fp)) {
            printf("Error reading week.txt\n");
            fclose(fp);
            return 1;
        }
        // Replacing the 'newline' symbol
        for (int j = 0; week_days[i][j]; j++) {
            if (week_days[i][j] == '\n') {
                week_days[i][j] = '\0';
                break;
            }
        }
    }
    fclose(fp);

    // Day of week searching
    int dow = day_of_week(year, month, day);
    printf("Day of week: %s\n", week_days[dow]);

    return 0;
}
