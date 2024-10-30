#include "libft.h"

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

//  void	printSquare(int number) {
// 		printf("%d\n", number * number);
// 	}

// void	printDouble(int number) {
// 	printf("%d\n", number * 2);
// }

// void	processNumbers(int *numbers, int size, void (*operation)(int)) {
// 	for (int i = 0; i < size; i++) {
// 		operation(numbers[i]);
// 	}
// }

// int	main()
// {
// 	int	numbers[] = {2,4,6,8};
// 	//printSquare(numbers[0]);
// 	printf("The square of numbers is:\n");
// 	processNumbers(numbers, 4, printSquare);
// 	//printf("The double of numbers is:\n");
// 	//processNumbers(numbers, 4, printDouble);
// }

/*-----------------------------------------------------------------------------------*/

#include <fcntl.h>    // For open
#include <unistd.h>   // For close, read, write
#include <stdio.h>

// int main() {
//     // Open a file with read-only permissions
//     int fd = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
//     if (fd == -1) {
//         perror("Error opening file");
//         return 1;
//     }
// 	printf("%d\n", fd);

//     char buffer[100] = "wash a shabab";
//     ssize_t bytesRead = write(fd, buffer, sizeof(buffer) - 1); // Read into buffer
//     if (bytesRead == -1) {
//         perror("Error reading file");
//         close(fd);
//         return 1;
//     }

//     buffer[bytesRead] = '\0'; // Null-terminate the buffer
//     printf("File contents:\n%s\n", buffer);

//     // close(fd); // Always close file descriptors when done
//     return 0;
// }

// typedef struct s_list
// {
//     void *content;
//     struct s_list *next;
// } t_list;

// int main() {
//     // Create a new node
//     t_list *node = malloc(sizeof(t_list));
//     if (!node) {
//         return 1; // Handle memory allocation failure
//     }

//     node->content = "Hello, World!"; // Assign content
//     node->next = NULL; // No next node yet

//     // Output the content
//     printf("%s\n", (char *)node->content);

//     // Free the allocated memory
//     free(node);

//     return 0;
// }

void *ft_memset(void *str, int c, size_t n)
{
    unsigned char *q = (unsigned char *)str;

    while (n > 0)
    {
        *q = (unsigned char)c;
        q++;
        n--;
    }
    return (void *)str;
}

int main()
{
    int arr[] = {4, 2, 5, 67, 3};

    ft_memset(arr, 0, sizeof(arr));
    size_t i = 0;
    while (i < 5)
    {
        printf("%d, ", arr[i]);
        i++;
    }
    printf("\n");
}