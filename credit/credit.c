#include <cs50.h>
#include <stdio.h>

// function to check the validity
bool check(long number)
{
    int summ = 0;
    int other = 1;
    // summ
    while (number > 0)
    {
        // add directly the not other numbers
        if (other == 1)
        {
            summ += number % 10;
            other = 2;
        }
        else
        {
            // add the degits of the other numbers multiplied by 2
            summ += (2 * (number % 10)) % 10;
            summ += (2 * (number % 10)) / 10;
            other =  1;
        }
        number = number / 10;
    }
    // return valid or invalid
    if (summ % 10 == 0)
    {
        return true;
    }
    return false;
}

// function to count the number on digits of the card's number
int count(long number)
{
    int c = 0;
    while (number > 0)
    {
        c++;
        number /= 10;
    }
    return c;
}

int main(void)
{
    long number;
    string type;
    // get the number card
    do
    {
        number = get_long("number :");
    }
    while (number < 1);

    // check the validity
    if (check(number))
    {
        int c = count(number);
        //american express
        if ((c == 15 && number / 10000000000000 == 34) || (c == 15 && number / 10000000000000 == 37))
        {
            printf("AMEX\n");
        }
        // master card and visa with 16 digits
        else if (c == 16)
        {
            if (number / 100000000000000 > 50 && number / 100000000000000 < 56)
            {
                printf("MASTERCARD\n");
            }
            else if (number / 1000000000000000 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }

        }
        // visa with 13 digits
        else if (c == 13 && number / 1000000000000 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}