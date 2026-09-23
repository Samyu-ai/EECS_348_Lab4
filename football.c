/*
 * Name: Samyu Aitha
 * Lab: Lab 4: C Programming
 * Student ID: 3222133
 * Description: Determines all possible combinations of NFL scoring plays that can produce a user-entered score.
 */

#include <stdio.h>

int main(void)
{
    int score;
    char extra;

    while (1)
    {
        printf("Enter the NFL score (Enter 1 to stop): ");

        /*
         * Read an integer and make sure the user did not enter
         * something like "abc" or "25abc"
         */
        if (scanf("%d", &score) != 1)
        {
            printf("Invalid input. Please enter an integer score.\n");

            /* Clear invalid input from the input buffer */
            while (getchar() != '\n')
            {
            }

            continue;
        }

        /*
         * check for extra characters after the number
         */
        extra = getchar();

        if (extra != '\n')
        {
            while (getchar() != '\n')
            {
            }

            printf("Invalid input. Please enter only an integer.\n");
            continue;
        }

        /* Entering 1 ends the program */
        if (score == 1)
        {
            break;
        }

        /* Negative NFL scores are invalid */
        if (score < 0)
        {
            printf("Invalid score. Score cannot be negative.\n");
            continue;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n",
               score);

        int found = 0;

        /*
         * Scoring plays:
         *
         * TD + 2-point conversion = 8
         * TD + extra point       = 7
         * TD                     = 6
         * Field goal             = 3
         * Safety                 = 2
         */

        for (int td2 = 0; td2 <= score / 8; td2++)
        {
            for (int td1 = 0; td1 <= score / 7; td1++)
            {
                for (int td = 0; td <= score / 6; td++)
                {
                    for (int fg = 0; fg <= score / 3; fg++)
                    {
                        int usedPoints =
                            (td2 * 8) +
                            (td1 * 7) +
                            (td * 6) +
                            (fg * 3);

                        int remaining = score - usedPoints;

                        /*
                         * Remaining points must be nonnegative
                         * and divisible by 2 to be made from safeties.
                         */
                        if (remaining >= 0 && remaining % 2 == 0)
                        {
                            int safety = remaining / 2;

                            printf("%d TD + 2pt, "
                                   "%d TD + FG, "
                                   "%d TD, "
                                   "%d 3pt FG, "
                                   "%d Safety\n",
                                   td2,
                                   td1,
                                   td,
                                   fg,
                                   safety);

                            found = 1;
                        }
                    }
                }
            }
        }

        if (!found)
        {
            printf("No possible combinations of scoring plays.\n");
        }
    }

    return 0;
}
