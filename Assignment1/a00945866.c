#include <stdio.h>
#include <string.h>

#define MAX_NUMBER_OF_WORDS 84
#define MAX_WORD_LENGTH 17

int getAllWordsFrom2DArray(char* paragraph, char words[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH]){
    int wordNumber = 0;
    int wordLength = 0;
    int wordCount = 1;
    for (int i = 0; i < strlen(paragraph); i++) {
        if (paragraph[i] == ' ') {
            wordNumber++;
            wordCount++;
            wordLength = 0;
        } else {
            words[wordNumber][wordLength] = paragraph[i];
            wordLength++;
            if (wordLength == MAX_WORD_LENGTH) {
                wordCount--;
            }
        }
    }
    return wordCount;
}

int getNumberOfWordsForNextLine(char words[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH],
                                int processedWords, int totalWords, int lineLength){
    int number = 1;
    for (int i = processedWords; i < totalWords; i++) {
        for (int j = 0; j < MAX_WORD_LENGTH; j++) {
            if (words[i][j] != '\0' && lineLength > 0) {
                lineLength--;
                if (lineLength == 0) {
                    number = i - processedWords;
                    if (words[i][j + 1] == '\0') {
                        number++;
                    }
                }
            }
            if (j == (MAX_WORD_LENGTH - 1) && lineLength > 0) {
                lineLength--;
                if (lineLength == 0 || i == totalWords - 1) {
                    number = i - processedWords + 1;
                }
            }
        }
    }
    return number;
}

void printWordsAndSpaces(char words[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int lastWordNum, int processedWords,
                         int spaces, int spacePlaces) {
    int spaceRemainder = spaces % spacePlaces;
    for (int i = processedWords; i < lastWordNum; i++) {
        for (int j = 0; j < MAX_WORD_LENGTH; j++) {
            if (words[i][j] != '\0') {
                printf("%c", words[i][j]);
            }
            if (words[i][j] == '\0' && words[i][j - 1] != '\0' && i != lastWordNum - 1) {
                for (int k = 0; k < spaces / spacePlaces; k++) {
                    printf("%c", ' ');
                }
                if (spaceRemainder > 0) {
                    printf("%c", ' ');
                    spaceRemainder--;
                }
            }
        }
    }
}

void printNextLine(char words[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int wordsForNextLine, int processedWords,
                   int lineLength) {
    int spaces = lineLength;
    int spacePlaces = wordsForNextLine - 1;
    int lastWordNum = processedWords + wordsForNextLine;
    for (int i = processedWords; i < lastWordNum; i++) {
        for (int j = 0; j < MAX_WORD_LENGTH; j++){
            if (words[i][j] != '\0') {
                spaces--;
            }
        }
    }
    printWordsAndSpaces(words, lastWordNum, processedWords, spaces, spacePlaces);

}

void writeArray(char* paragraph, char words[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH]) {
    int wordNum = 0;
    int wordLength = 0;
    for (int i = 0; i < strlen(paragraph) + 1; i++) {
        if (paragraph[i] == ' ' || i == strlen(paragraph)) {
            for (int j = wordLength; j < MAX_WORD_LENGTH; j++) {
                words[wordNum][j] = '\0';
            }
            wordNum++;
            wordLength = 0;
        } else {
            words[wordNum][wordLength] = paragraph[i];
            wordLength++;
        }
    }
}

void justifyAndPrintParagraph(char* paragraph, int lineLength){
    char words[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];
    int processedWords = 0;
    writeArray(paragraph, words);
    int totalWords = getAllWordsFrom2DArray(paragraph, words);
    while (processedWords < totalWords){
        int wordsForNextLine = getNumberOfWordsForNextLine(words, processedWords, totalWords, lineLength);
        printNextLine(words, wordsForNextLine, processedWords, lineLength);
        processedWords += wordsForNextLine;
        printf("\n");
    }
}

int main() {
    char* test1 = "I am here to learn C programming. This is my first assignment. Wish me luck!";

    justifyAndPrintParagraph(test1, 30);
    printf("\n");
    justifyAndPrintParagraph(test1, 50);

    printf("\n");
    char* test2 = "Hello my friend. My name is Jason Yoo and I am from Korea. I am glad to meet you today!";

    justifyAndPrintParagraph(test2, 30);
    printf("\n");
    justifyAndPrintParagraph(test2, 20);

    printf("\n");
    char* test3 = "This is the test paragraph for assignment 1";
    justifyAndPrintParagraph(test3, 20);


    return 0;
}
