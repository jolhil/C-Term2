#include <stdio.h>
#include <string.h>

#define SPACE_CHARACTER ' '

void printTokenizedString(char* inputString) {
    int count = 0;
    for (int i = 0; i < strlen(inputString); i++) {
        if (inputString[i] == SPACE_CHARACTER) {
           if (inputString[i + 1] != SPACE_CHARACTER && count != 0) {
                printf("\n");
            }
            if (i == strlen(inputString) - 1 && count == 0){
                printf("\n");
            }
        } else {
            printf("%c", inputString[i]);
            count++;
        }
    }

}

int main() {
    char* test1 =  "   Are you enjoying   coding ?  ";
    char* test2 = "This is a normal string with no trailing and leading whitespaces!";
    char* test3 = "   ";
    char* test4 = "   Hello!";

    printTokenizedString(test1);
    printTokenizedString(test2);
    printTokenizedString(test3);
    printTokenizedString(test4);
    return 0;
}
