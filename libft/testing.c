#include "libft.h"
#include <stdio.h>

// void checkIfPassed(int grade) {
//     if (grade >= 50)
//         printf("Student passed with grade %d.\n", grade);
//     else
//         printf("Student failed with grade %d.\n", grade);
// }

// void checkIfScholarship(int grade) {
//     if (grade >= 90)
//         printf("Student qualifies for a scholarship with grade %d.\n", grade);
//     else
//         printf("Student does not qualify for a scholarship with grade %d.\n", grade);
// }
// void checkStudents(int *grades, int size, void (*checkFunc)(int)) {
//     for (int i = 0; i < size; i++) {
//         checkFunc(grades[i]);
//     }
// }
// int main() {
//     int grades[] = {75, 60, 92};

//     printf("Checking if students passed:\n");
//     checkStudents(grades, 3, checkIfPassed);

//     printf("\nChecking if students qualify for scholarships:\n");
//     checkStudents(grades, 3, checkIfScholarship);

//     return 0;
// }
 void	printSquare(int number) {
		printf("%d\n", number * number);
	}

void	printDouble(int number) {
	printf("%d\n", number * 2);
}

void	processNumbers(int *numbers, int size, void (*operation)(int)) {
	for (int i = 0; i < size; i++) {
		operation(numbers[i]);
	}
}

int	main()
{
	int	numbers[] = {2,4,6,8};
	//printSquare(numbers[0]);
	printf("The square of numbers is:\n");
	processNumbers(numbers, 4, printSquare);
	//printf("The double of numbers is:\n");
	//processNumbers(numbers, 4, printDouble);
}