/******************************************
 *                                        *
 *    This code defines some functions    * 
 *    to deal with strings.               *
 *    Obs: header in "words.h" and        *
 *    test in "wordsTest.c"               *
 *                                        *
 ******************************************/

#include "words.h"
#include <stdio.h>

// Functions
void toLower(char word[])
{
	int counter = 0;

	while (word[counter] != '\0')
	{
		if (word[counter] >= 65 && word[counter] <= 90)
		{
			word[counter] = word[counter] + 32;
		}
		else
		{
			word[counter] = word[counter];
		}
		counter++;
	}
	word[counter] = '\0';
}

void toUpper(char word[])
{
	int counter = 0;

	while (word[counter] != '\0')
	{
		if (word[counter] >= 97 && word[counter] <= 122)
		{
			word[counter] = word[counter] - 32;
		}
		else
		{
			word[counter] = word[counter];
		}
		counter++;
	}
	word[counter] = '\0';
}

void capitalize(char *word)
{
	toLower(word);
	if(isAlphaChar(word[0]))
	{
		word[0] = word[0] - 32;
	}
}

void title(char word[])
{
	toLower(word);
	if (isAlphaChar(word[0]))
	{
		word[0] = word[0] - 32;
	}

	for (int i = 1; i <= lenght(word); i++)
	{
		if(word[i] == 32 && word[i + 1] != '\0')
			word[i + 1] = word[i + 1] - 32;
	}
}

int lenght(char word[])
{
	int count = 0;
	while(word[count] != '\0')
	{
		count++;
	}
	return count;
}

bool isAlphaChar(char letter)
{
	if ((letter >= 97 && letter <= 122) || (letter >= 65 && letter <= 90))
		return true;
	else
		return false;
}

bool isAlpha(char word[])
{
	for (int i = 0; i <= lenght(word); i++)
	{
		if(!isAlphaChar(word[i]))
		{
			return false;
		}
	}
	return true;
}

bool isAlphaNumericChar(char letter)
{
	if(isAlphaChar(letter) || (letter >= 48 && letter <= 57))
		return true;
	else
		return false;
}

bool isAlphaNumeric(char word[])
{
	for (int i = 0; i <= lenght(word); i++)
	{
		if(!isAlphaNumericChar(word[i]))
		{
			return false;
		}
	}
	return true;
}

bool compare(char word1[], char word2[])
{
	int counter = 0;

	while (!(word1[counter] == '\0' && word2[counter] == '\0'))
	{
		if (word1[counter] != word2[counter])
		{
			return false;
		}
		counter++;
	}
	return true;
}