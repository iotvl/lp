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
	string key = argv[1];
	int length = strlen(key);
    for (int index=0; index<length; index++)
    {
		if (key[index]<'A' || key[index]>'z') 
		{ 
			printf("Usage: ./asciimath key"); 
			return 1;
		}
    }
    string s = GetString();
    for (int index=0, n=strlen(s); index<n; index++)
    {
        int modulo=index%length;
        if (s[index]>='A' && s[index]<='Z') 
        {
            if(key[modulo]>='A' && key[modulo]<='Z')
            {
                s[index]=(s[index]-65+key[modulo]-65)%26;
                s[index]=s[index]+65;
            }
            else
            {
              s[index]=(s[index]-65+key[modulo]-97)%26;
              s[index]=s[index]+65;
            }
        }
        else if (s[index]>='a' && s[index]<='z') 
        {
            if(key[modulo]>='A' && key[modulo]<='Z')
            {
               s[index]=(s[index]-97+key[modulo]-65)%26;
               s[index]=s[index]+97;
            }
            else
            {
               s[index]=(s[index]-97+key[modulo]-97)%26;
               s[index]=s[index]+97;
            }
        }
    }
    printf("%s\n",s);
}
