#include <stdio.h>
#include <stdlib.h>

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

		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i]; // store data for each student in s

            int anotherDemo = 0; // for counting courses/grades
            for (int j = 0; j < s.load; ++j){ // process each course taken by the student
                if(s.grades[j] >= 6 && s.grades[j] <= 9){ // *** second filter, conditions on the course/grade
                    ++anotherDemo; // counting courses
                }
            }
            if (anotherDemo == s.load && anotherDemo != 0){ // *** third filter, various other conditions
                printf("Name and surname: %s %s\n ", s.name, s.surname);
                printf("List of %d course(s):\n ", s.load);
                for(int j = 0; j < s.load; ++j)
                    printf("%d\)%s %d \n ", j+1, s.courses[j], s.grades[j]);
                printf("\n");
                ++counterDemo; // counting studfents
            }
		}
		printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
		fclose(db);
	} else {
		printf("File db.bin not found, check current folder\n");
	}

	return 0;
}
