#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
	if (argc !=2)
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
		if (String[index]>='A' && String[index]<='Z') //encrypt big String characters
		{
			if(key[modulo]>='A' && key[modulo]<='Z') //encrypt big key characters
			{
				String[index]=(String[index]-'A'+key[modulo]-'A')%('Z'-'A');
				String[index]=String[index]+'A';
			}
			else //encrypt small key characters
			{
				String[index]=(String[index]-'A'+key[modulo]-'a')%('Z'-'A');
				String[index]=String[index]+'A';
			}
		}
		else if (String[index]>='a' && String[index]<='z') //encrypt small String characters
		{
			if(key[modulo]>='A' && key[modulo]<='Z') //encrypt big key characters
			{
				String[index]=(String[index]-'a'+key[modulo]-'A')%('Z'-'A');
				String[index]=String[index]+'a';
			}
			else //encrypt small key characters
			{
				String[index]=(String[index]-'a'+key[modulo]-'a')%('Z'-'A');
				String[index]=String[index]+'a';
			}
		}
	}
	printf("%s\n",String);
}
