#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    int l,j,o;
    if (argc !=2)
    {
        printf("Usage: ./asciimath key");
        return 1;
    }
    string k = argv[1];
    for (j=0, l=strlen(k); j<l; j++)
    {
        if (k[j]<'A' || k[j]>'z') { printf("Usage: ./asciimath key"); return 1;}
    }
    string s = GetString();
    j=0;
    for (int i=0, n=strlen(s); i<n; i++)
    {
        o=j%l;
        if (s[i]>='A' && s[i]<='Z') 
        {
            if(k[o]>='A' && k[o]<='Z')
            {
                s[i]=(s[i]-65+k[o]-65)%26;
                s[i]=(s[i]+65);
                j=j+1;
            }
            else
            {
              s[i]=(s[i]-65+k[o]-97)%26;
              s[i]=(s[i]+65);
              j=j+1;  
            }
        }
        else if (s[i]>='a' && s[i]<='z') 
        {
            if(k[o]>='A' && k[o]<='Z')
            {
               s[i]=(s[i]-97+k[o]-65)%26;
               s[i]=(s[i]+97);
               j=j+1;
            }
            else
            {
               s[i]=(s[i]-97+k[o]-97)%26;
               s[i]=(s[i]+97);
               j=j+1;
            }
        }
    }
    printf("%s\n",s);
}
