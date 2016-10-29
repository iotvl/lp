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
		if (String[index]>='A' && String[index]<='Z') 
		{
			if(key[modulo]>='A' && key[modulo]<='Z')
			{
				String[index]=(String[index]-'A'+key[modulo]-'A')%26;
				String[index]=String[index]+'A';
			}
			else
			{
				String[index]=(String[index]-'A'+key[modulo]-'a')%26;
				String[index]=String[index]+'A';
			}
		}
		else if (String[index]>='a' && String[index]<='z') 
		{
			if(key[modulo]>='A' && key[modulo]<='Z')
			{
				String[index]=(String[index]-'a'+key[modulo]-'A')%26;
				String[index]=String[index]+'a';
			}
			else
			{
				String[index]=(String[index]-'a'+key[modulo]-'a')%26;
				String[index]=String[index]+'a';
			}
		}
	}
	printf("%s\n",String);
}
