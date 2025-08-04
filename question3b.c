#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50
#define MAX_PARAGRAPH_LEN 10000


typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFreq;

int main() {
    char paragraph[MAX_PARAGRAPH_LEN];
    WordFreq words[MAX_WORDS];
    int word_count = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

   
    char *token = strtok(paragraph, " ,.-!?\n\t");

    while (token != NULL) {
       
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }

       
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

       
        if (!found && word_count < MAX_WORDS) {
            strcpy(words[word_count].word, token);
            words[word_count].count = 1;
            word_count++;
        }

        token = strtok(NULL, " ,.-!?\n\t");
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
