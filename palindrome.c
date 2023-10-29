// write a c program to find longest palindromic sub-string using dynamic programming approach
#include <stdio.h>
#include <string.h>

void findLongestPalindrome(char *str) {
    int n = strlen(str);
    int start = 0; 
    int max_length = 1; 
    int table[n][n];
    memset(table, 0, sizeof(table));

    for (int i = 0; i < n; i++) {
        table[i][i] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = 1;
            start = i;
            max_length = 2;
        }
    }

    for (int k = 3; k <= n; k++) {
        for (int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1; 
            if (table[i + 1][j - 1] && str[i] == str[j]) {
                table[i][j] = 1;

                if (k > max_length) {
                    start = i;
                    max_length = k;
                }
            }
        }
    }

    printf("Longest palindromic substring: ");
    for (int i = start; i < start + max_length; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    findLongestPalindrome(str);
    return 0;
}
