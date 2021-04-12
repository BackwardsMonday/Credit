#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    long long cardNumber = get_long_long("card number:");
    long long originalNumber = cardNumber;
    int total = 0;
    int i = 0;
    string cardType;
    /*Test Luhn's Algorithm*/
    while(cardNumber != 0)
    {
        int digit = cardNumber%10;
        if (i % 2 == 1)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = (digit%10) + (digit/10);
            }
            total += digit;
        }
        else
        {
            total += digit;
        }
        cardNumber = cardNumber/10;
        i++;
    }
    if (total % 10 == 1)
    {
        cardType = "INVALID";
    }
    else
    {
        long long place = pow(10, i-2);
        long long firstDigits = (originalNumber/place);
        if (i == 15 && (firstDigits == 34 || firstDigits == 37))
        {
            cardType = "AMEX";
        }
        else if (i == 16 && (firstDigits == 51 || firstDigits == 52 || firstDigits == 53 || firstDigits == 54 || firstDigits == 55))
        {
            cardType = "MASTERCARD";
        }
        else if ((i == 13 || i == 16) && firstDigits/10 == 4)
        {
            cardType = "VISA";
        }
        else
        {
            cardType = "INVALID";
        }
        printf("%s\n", cardType);
    }       
}