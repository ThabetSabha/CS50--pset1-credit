#include <stdio.h>
#include <string.h>

int main(void)
{
    char cardNumber[21];
    printf("what's your card number?\n");
    scanf("%s", cardNumber);
    if (strlen(cardNumber) > 20)
    {
        printf("Max length is 20\n");
        return 0;
    }
    int secondLastSum = 0 ;
    int lastSum = 0;
    int cardLen = strlen(cardNumber);
    int j = cardLen - 1;
    int i = cardLen - 2;


    while (i >= 0 || j >= 0)
    {
        if (i >= 0)
        {
            int elem = (cardNumber[i] - '0') * 2;
            if (elem >= 10)
            {
                secondLastSum += 1 + elem % 10;
            }
            else
            {
                secondLastSum += elem;
            }

        }

        if (j >= 0)
        {
            int elem = cardNumber[j] - '0';
            lastSum += elem;
        }

        i -= 2;
        j -= 2;
    }


    int firstNumber = cardNumber[0] - '0';
    int secondNumber = cardNumber[1] - '0';

    if ((lastSum + secondLastSum) % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    if (firstNumber == 5 && cardLen == 16)
    {
        if (secondNumber < 6 && secondNumber > 0)
        {
            printf("MASTERCARD\n");
            return 0;
        }
    }


    if (firstNumber == 3 && cardLen == 15)
    {
        if (secondNumber == 4 || secondNumber == 7)
        {
            printf("AMEX\n");
            return 0;
        }
    }

    if (firstNumber == 4 && (cardLen == 13 || cardLen == 16))
    {
        printf("VISA\n");
        return 0;
    }

    printf("INVALID\n");
    return 0;
}


