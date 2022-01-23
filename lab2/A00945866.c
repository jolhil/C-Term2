#include <stdio.h>
#include <stdbool.h>

void checkInteger(int x) {
    if (x == 0) {
        printf("%d is Zero\n\n", x);
    } else if (x % 2 == 0 && x > 0) {
        printf("%d is a positive even.\n\n", x);
    } else if (x % 2 == 0 && x < 0) {
        printf("%d is a negative even.\n\n", x);
    } else if (x % 2 != 0 && x > 0) {
        printf("%d is a positive odd\n\n", x);
    } else if (x % 2 != 0 && x < 0) {
        printf("%d is a negative odd\n\n", x);
    }
}

bool isPalindrome(int elements[], int size) {
    bool result = true;
    for (int i = 0; i < size; i++) {
        printf("%d ", elements[i]);
    }
    printf("\n");
    for (int i = 0; i < size / 2; i++) {
        if (elements[i] != elements[size - 1 - i]) {
            result = false;
        }
    }
    if (result) {
        printf("The array is a palindrome.\n\n");
    } else {
        printf("The array is not a palindrome\n\n");
    }
    return result;
}

int main() {
    int x = 4;
    int y = 1;
    int z = -6;
    int a = -3;
    int b = 0;

    checkInteger(x);
    checkInteger(y);
    checkInteger(z);
    checkInteger(a);
    checkInteger(b);

    int case1[5] = {1, 0, 0, 0, 1};
    isPalindrome(case1, 5);

    int case2[4] = {1, 0, 0, 1};
    isPalindrome(case2, 4);

    int case3[5] = {1, 1, 0, 0, 1};
    isPalindrome(case3, 5);

    return 0;
}
