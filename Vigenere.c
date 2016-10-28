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
    for (int i=0; i<length; i++)
    {
        if (key[i]<'A' || key[i]>'z') 
		{ 
			printf("Usage: ./asciimath key"); 
			return 1;
		}
    }
    string s = GetString();
    for (int i=0, n=strlen(s); i<n; i++)
    {
        int o=i%length;
        if (s[i]>='A' && s[i]<='Z') 
        {
            if(key[o]>='A' && key[o]<='Z')
            {
                s[i]=(s[i]-65+key[o]-65)%26;
                s[i]=(s[i]+65);
            }
            else
            {
              s[i]=(s[i]-65+key[o]-97)%26;
              s[i]=(s[i]+65);
            }
        }
        else if (s[i]>='a' && s[i]<='z') 
        {
            if(key[o]>='A' && key[o]<='Z')
            {
               s[i]=(s[i]-97+key[o]-65)%26;
               s[i]=(s[i]+97);
            }
            else
            {
               s[i]=(s[i]-97+key[o]-97)%26;
               s[i]=(s[i]+97);
            }
        }
    }
    printf("%s\n",s);
}
