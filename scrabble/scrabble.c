#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);
int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int len = strlen(word);
    int scores = 0;
    int A[26];
    int a[26];
    int i = 65, j = 0, g = 97;
    while (i < 91 && j < 26 && g < 123)
    {
        A[j] = i;
        a[j] = g;
        i++;
        j++;
        g++;
    }
    for (int k = 0; k < len; k++)
    {
        if (islower(word[k]))
        {
            for (int l = 0; l < 26; l++)
            {
                if (word[k] == a[l])
                {
                    scores += POINTS[l];
                }
            }
        }
        else if (isupper(word[k]))
        {
            for (int h = 0; h < 26; h++)
            {
                if (word[k] == A[h])
                {
                    scores += POINTS[h];
                }
            }
        }
    }
    return (scores);
}
