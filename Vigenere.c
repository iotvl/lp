#include <cs50.h>
#include <stdio.h>
#include <string.h>

//const
#define BIG_A 65
#define SMALL_A 97
#define BIG_Z 90
#define SMALL_Z 122
#define LETTERS_BETWEEN_A_Z 26

int main(int argc, string argv[])
{
	if (argc !=2) //check if argument isn't 2
	{
		printf("Usage: ./asciimath key");
		return 1;
	}
	string key = argv[1]; //get key
	int keyLength = strlen(key);
	for (int index=0; index<keyLength; index++) //validate key
	{
		if (key[index]<'A' || key[index]>'z') 
		{ 
			printf("Usage: ./asciimath key"); 
			return 1;
		}
	}
	string String = GetString(); // get String
	for (int index=0, stringLength=strlen(String); index<stringLength; index++) //encrypt characters
	{
		int modulo=index%keyLength;
		if (String[index]>=BIG_A && String[index]<=BIG_Z) //encrypt big String characters
		{
			if(key[modulo]>=BIG_A && key[modulo]<=BIG_Z) //encrypt for big key characters
			{
				String[index]=(String[index]-BIG_A+key[modulo]-BIG_A)%LETTERS_BETWEEN_A_Z;
				String[index]=String[index]+BIG_A;
			}
			else //encrypt for small key characters
			{
				String[index]=(String[index]-BIG_A+key[modulo]-SMALL_A)%LETTERS_BETWEEN_A_Z;
				String[index]=String[index]+BIG_A;
			}
		}
		else if (String[index]>=SMALL_A && String[index]<=SMALL_Z) //encrypt small String characters
		{
			if(key[modulo]>=BIG_A && key[modulo]<=BIG_Z) //encrypt for big key characters
			{
				String[index]=(String[index]-SMALL_A+key[modulo]-BIG_A)%LETTERS_BETWEEN_A_Z;
				String[index]=String[index]+SMALL_A;
			}
			else //encrypt for small key characters
			{
				String[index]=(String[index]-SMALL_A+key[modulo]-SMALL_A)%LETTERS_BETWEEN_A_Z;
				String[index]=String[index]+SMALL_A;
			}
		}
	}
	printf("%s\n",String);
}
