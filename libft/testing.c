/*#include <stdio.h>
#include <ctype.h>

int main() {
    char test_char1 = 'z';
    char test_char2 = 'Z';
    char test_char3 = ',';
    char test_char4 = '#';

    printf("%c is alphanumeric: %d\n", test_char1, isalnum(test_char1));
    printf("%c is alphanumeric: %d\n", test_char2, isalnum(test_char2));
    printf("%c is alphanumeric: %d\n", test_char3, isalnum(test_char3));
    printf("%c is alphanumeric: %d\n", test_char4, isalnum(test_char4));

}
*/

#include <stdio.h>
#include <ctype.h>

int main() {
    char test_char = 'A'; // Test character
    int result = isalnum(test_char);

    if (result) {
        printf("'%c' is alphanumeric: %d\n", test_char, result); // result could be 1 or another positive value
    } else {
        printf("'%c' is not alphanumeric.\n", test_char);
    }

    return 0;
}