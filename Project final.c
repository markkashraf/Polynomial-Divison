#include <stdio.h>

//create an object for a variable

typedef struct variable
{
    float coeff;
    int power;
} var;
//prototyping the function
void Division(var Numerator[] , var Denominator[] ,var quotient[] ,  int HighestNomi , int HighestDenomi);

int main()
{   //create variables to get max powers
    int HighestNomi, HighestDenomi;

    printf("Please enter the highest power of the nominator and the denominator respectevly >");
    //get the max powers from the user
    scanf("%d", &HighestNomi);
    scanf("%d", &HighestDenomi);
    //if the power of the numerator higher than the power of the denominator, exit the program and print an error message.
    if(HighestDenomi>HighestNomi)
    {
        printf("ERROR: Please Enter a Correct input!\r\n");
        return 1;
    }






    //create arrays to contain the numerator and denominator
    var Numerator[HighestNomi + 1];
    var Denominator[HighestDenomi + 1];
    var quotient[HighestNomi];

    //get the coeffs from the user
    for (int i = 0; i <= HighestNomi; i++)
    {
        printf("please enter the coeff. of x^%d in the Numerator ", HighestNomi - i);
        scanf("%f", &Numerator[i].coeff);
        Numerator[i].power = HighestNomi - i;
    }

    for (int i = 0; i <= HighestDenomi; i++)
    {
        printf("please enter the coeff. of x^%d in Denominator ", HighestDenomi - i);
        scanf("%f", &Denominator[i].coeff);
        Denominator[i].power = HighestDenomi - i;
    }

    //calling the function
   Division(Numerator,Denominator,quotient,HighestNomi,HighestDenomi);


    //print the Quotient
    printf("Quotient : ");
    for (int i = 0; i < HighestNomi; i++)
    {
        if(quotient[i].power==0)
        {
           printf("(%.1f)", quotient[i].coeff); continue;
        }



          if (i == HighestNomi-1) //if this is the last element, remove the plus sign
        {
            printf("(%.1f)X^%d", quotient[i].coeff, quotient[i].power);
            break;
        }


        printf("(%.1f)X^%d + ", quotient[i].coeff, quotient[i].power);
    }

    printf("\n");

    //print the Remainder
    printf("Remainder : ");
    for (int i = 0; i <= HighestNomi; i++)
    {
        if(Numerator[i].coeff==0)//if the coeff = 0, no need to print it
        continue;




        if(Numerator[i].power==0)
        {
           printf("(%.1f)", Numerator[i].coeff); break;
        }





        if (i == HighestNomi) //if this is the last element, remove the plus sign
        {
            printf("(%.1f)X^%d", Numerator[i].coeff, Numerator[i].power);
            break;
        }



        printf("(%.1f)X^%d + ", Numerator[i].coeff, Numerator[i].power);
    }
}


void Division(var Numerator[] , var Denominator[] ,var quotient[] ,  int HighestNomi , int HighestDenomi)
{

    //counter for quotient, eg: i=0 first quotient, i=1 second quotient, etc
    int i = 0;

    while (i < HighestNomi) //the number of quotient terms equals the power of the highest term in the nominator
    {
        //to get the quotient, divide the highest power term in the Numerator by the first term in the Denominator
        quotient[i].coeff = Numerator[i].coeff / Denominator[0].coeff;
        quotient[i].power = Numerator[i].power - Denominator[0].power;

        // if the element's power equal the result of Multiplication of the quotient and the Denominator,
        //change the coeff else, search for the element with the same power and change it's coeff.
        for (int j = 0; j <= HighestDenomi; j++)
        {
            if (quotient[i].power + Denominator[j].power == Numerator[j].power)
            {
                Numerator[j].coeff = Numerator[j].coeff - (quotient[i].coeff * Denominator[j].coeff);
                continue;
            }
            else
            {
                for (int k = 0; k <= HighestNomi; k++)
                {
                    if (Numerator[k].power == quotient[i].power + Denominator[j].power)
                    {
                        Numerator[k].coeff = Numerator[k].coeff - (quotient[i].coeff * Denominator[j].coeff);
                        break;
                    }
                }
            }
        }

        i++;
    }




}
