#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
	char name[30];
	char surname[30];
	int course;					// year of study
	double average; 			// average grade

	int load; 					// number of courses
	char courses[10][30]; 		// course names
	int grades[10]; 			// course grades

	char languages[100];		// spoken languages

} Student;


int main(int argc, char *argv[]) {
	FILE *db = NULL;
	// open database file for reading, provide a parameter or use default "db.bin"
	if (argc > 1)
		db = fopen(argv[1], "rb");
	else
		db = fopen("db.bin", "rb");

	if (db){
		Student students[1000];			// all the data goes here
		int size = 0;					// how many students in database

		// reading data from file
		fread(&size, sizeof(int), 1, db);

		for (int i = 0; i < size; i++){
			fread(&students[i], sizeof(Student), 1, db);
		}
		printf("%d records loaded succesfully\n", size);


		// MODIFY CODE BELOW

		int counterDemo = 0; // for counting students
		int n = 0;
        char **arr = NULL;

		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i]; // store data for each student in s

            int foundName = 0, foundSurname = 0; // checking the uniqueness of a name
            for (int j = 0; j < n; ++j) {
                if (strcmp(arr[j], s.name) == 0) {
                    foundName = 1;
                }
                if (strcmp(arr[j], s.surname) == 0) {
                    foundSurname = 1;
                }
            }

                if(foundName == 0){ // Student with unique name
                    n++;
                    arr = realloc(arr, n * sizeof(char*));
                    arr[n-1] = malloc(strlen(s.name) + 1);
                    strcpy(arr[n-1], s.name);

                    ++counterDemo;
                    printf("Unique by name: %s %s\n\n", s.name, s.surname);
                }
                else if(foundSurname == 0){ // Student with unique surname
                    n++;
                    arr = realloc(arr, n * sizeof(char*));
                    arr[n-1] = malloc(strlen(s.surname) + 1);
                    strcpy(arr[n-1], s.surname);

                    ++counterDemo;
                    printf("Unique by surname: %s %s\n\n", s.name, s.surname);
                }
		}
        // clearing memory
		for (int i = 0; i < n; i++) {
            free(arr[i]);
        }
        free(arr);

		printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
		fclose(db);
	} else {
		printf("File db.bin not found, check current folder\n");
	}

	return 0;
}
