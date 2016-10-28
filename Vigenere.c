#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    int length ,j,o;
    if (argc !=2)
    {
        printf("Usage: ./asciimath key");
        return 1;
    }
    string key = argv[1];
    for (j=0, length=strlen(key); j<length; j++)
    {
        if (key[j]<'A' || key[j]>'z') 
		{ 
			printf("Usage: ./asciimath key"); 
			return 1;
		}
    }
    string s = GetString();
    j=0;
    for (int i=0, n=strlen(s); i<n; i++)
    {
        o=j%length;
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
        j++;
    }
    printf("%s\n",s);
}
