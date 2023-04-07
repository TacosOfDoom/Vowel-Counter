//  Kevin, Arrays, Strings, and Structs

#include<stdio.h>
#include<ctype.h>   // tolower and to upper
#include<string.h>  // for strn
#define SIZE 30

typedef struct {
	char inputWord[SIZE];
	int length;
	char upperWord[SIZE];
	char revWord[SIZE];
	int vowels;
} wordInfo;

//function prototypes:

// A function that greets the user and gets the first name of the user
void Greeting(char name[]);

//A function that gets a word from the user and makes a copy of that word
void GetWord(char input[], char copy[]); //character arrays

//A function that changes a word to all uppercase letters
void UppercaseWord(char upper[]);

//reverse a word
void ReverseTheWord(char upper[], char reverse[]);

//input: character array (string)
//display the number of A.s and list the index locations
//display the number of E.s and list the index locations
//display the number of I.s and list the index locations
//display the number of O.s and list the index locations
//display the number of U.s and list the index locations
int CountVowels(char upper[]);

//call from main after the while loop
void SaveToFile(FILE* outPtr, wordInfo wordlist[], int num);

int main()
{
	//declare 4 character arrays
	char firstName[30];
    char input[25];
    char upper[25];
    char reverse[25];
	char quit;
	int vowelCount = 0;
    wordInfo currentWord;
	wordInfo wordList[50];      //list of all the words entered
	int num = 0;        //number of wordInfo words in the list

	//declare file pointer and connect to "wordsProgram10.txt"
    FILE* inPtr; //for input & output

    inPtr = fopen("wordsProgram10.txt", "w");   //connect to file

    Greeting(firstName);     //greet the user

printf("\n----------------------------------------\n");

	printf("Would you like to enter a word Y (YES) or N (NO)? ");
	scanf(" %c", &quit);

	while (quit != 'N' && quit != 'n')
	{
		GetWord(currentWord.inputWord, currentWord.upperWord);

        currentWord.length = (int)strlen(currentWord.inputWord);
        printf("\nThe input word has %d letters\n", currentWord.length);

        UppercaseWord(currentWord.upperWord);
		ReverseTheWord(currentWord.upperWord, currentWord.revWord);

		printf("\nPrinting the words in the main function:\n\n");
		printf("original word:\t%s\nuppercase:\t%s\nreverse:\t%s\n", currentWord.inputWord, currentWord.upperWord, currentWord.revWord);

		currentWord.vowels = CountVowels(currentWord.upperWord);
		printf("\nPrinting total number of vowels in the main function:\n\n");
		printf("\nThe total number of vowels is %d\n", currentWord.vowels);


        strcpy(wordList[num].inputWord, currentWord.inputWord);
        strcpy(wordList[num].upperWord, currentWord.upperWord);
        strcpy(wordList[num].revWord, currentWord.revWord);
        wordList[num].length = strlen(currentWord.inputWord);
        wordList[num++].vowels = vowelCount;

        printf("\n----------------------------------");

        printf("\n%s,", firstName);
        printf("\nWould you like to enter a word Y (YES) or N (NO)? ");
		scanf(" %c", &quit);
	}


    printf("\n----------------------------------");
	printf("\nsaving all the information in the word list to the output file");
    SaveToFile(inPtr, wordList, num);

    printf("\n%s,\nHave a great day!\n\n", firstName);

    return 0;
}

//call from main after the while loop
void SaveToFile(FILE* outPtr, wordInfo wordList[], int num)
{
	int i;

    if (outPtr == NULL)
    {
        return;
    }

	for (i = 0; i < num; i++)
    {
        //write info of the wordInfo struct into file
        if (i < num - 1)

            fprintf(outPtr, "--------------------------------------\n"
                    "The input word was: %s\n"
                    "The input word has %d letters\n"
                    "The uppercase version is: %s\n"
                    "The reverse is: %s\n"
                    "The total number of vowels is %d--------------------------------------\n", wordList[i].inputWord, wordList[i].length, wordList[i].upperWord, wordList[i].revWord, wordList[i].vowels);
        else
            fprintf(outPtr, "--------------------------------------\n"
                    "The input word was: %s\n"
                    "The input word has %d letters\n"
                    "The uppercase version is: %s\n"
                    "The reverse is: %s\n"
                    "The total number of vowels is %d--------------------------------------\n", wordList[i].inputWord, wordList[i].length, wordList[i].upperWord, wordList[i].revWord, wordList[i].vowels);
    }
}




void Greeting(char name[])
{
    printf("What is your first name? ");
    scanf(" %s", name);
    printf("\n*** Hello Welcome %s to my practice program ***\n", name);

}

void GetWord(char input[], char copy[])
//display the current account balance
{
    printf("Enter a word: ");
    scanf(" %s", input);

    strcpy( copy, input);

    return;
}

void UppercaseWord(char upper[])
{
    int len = (int)strlen(upper);
    int i;
    int j = 0;

        for (i = 0; i < len; i++)
        {
            upper[i] = toupper(upper[i]);
        }

}

void ReverseTheWord(char upper[], char reverse[])
//

{
    int len = (int)strlen(upper);
    int i;
    int j = 0;

    for (i = len -1; i >= 0; i--)
    {
        reverse[j] = upper[i];
        j++;

        reverse[j] = '\0';  //add the null character
    }



}


int CountVowels(char upper[])
{
	int i;
	int len = (int)strlen(upper);
	int total = 0, aCount = 0, eCount = 0, iCount = 0, oCount = 0, uCount = 0;  //add variabels to count e,i,o,and u

	for (i = 0; i < len; i++)
	{
		if (upper[i] == 'A')
		{
			aCount++;
			total++;
			printf("\nThere is an 'A' located at index %d\n", i);
		}

		else if (upper[i] == 'E')
		{
			eCount++;
			total++;
			printf("\nThere is an 'E' located at index %d\n", i);
		}
		else if (upper[i] == 'I')
		{
			iCount++;
			total++;
			printf("\nThere is an 'I' located at index %d\n", i);
		}
		else if (upper[i] == 'O')
		{
			oCount++;
			total++;
			printf("\nThere is an 'O' located at index %d\n", i);
		}

		else if(upper[i] == 'U')
		{
			uCount++;
			total++;
			printf("\nThere is an 'U' located at index %d\n", i);
		}


	}

	printf("\n The total number of A's is %d\n", aCount);
	printf("\n The total number of E's is %d\n", eCount);
	printf("\n The total number of I's is %d\n", iCount);
	printf("\n The total number of O's is %d\n", oCount);
	printf("\n The total number of U's is %d\n", uCount);



	return total;
}









