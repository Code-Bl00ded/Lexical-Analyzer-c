#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
	char str[100];
	char * p;
	char * q;
	char copy[100];
	int i, flag=1,k,v,c,d,f;
	k=f=v=c=d=7;


	clrscr();
	printf("****************************/ LEXICAL ANALYZER /****************************");

	printf("\n\nEnter the Expression : ");
	scanf("%[^\n]s", str);
	strcpy(copy, str);
	printf("\n\nKeyword\t\tFunction\tVariable\tConstant\tDelimiter");
	printf("\n--------------------------------------------------------------------------");


		p = strtok(str, " ,/;:?|\_~$#%&*-+<>()[]{}=\"`");    //to seperate tokens
		while (p != NULL)
		{
	    //keyword
			if (strcmp("auto", p) == 0 || strcmp("break", p) == 0 || strcmp("case", p) == 0 ||
				strcmp("char", p) == 0 || strcmp("const", p) == 0 || strcmp("continue", p) == 0 || strcmp("default", p) == 0 || strcmp("do", p) == 0 || strcmp("double", p) == 0 || strcmp("else", p) == 0 || strcmp("enum", p) == 0 || strcmp("extern", p) == 0 || strcmp("float", p) == 0 || strcmp("for", p) == 0 || strcmp("goto", p) == 0 || strcmp("if", p) == 0 || strcmp("int", p) == 0 || strcmp("long", p) == 0 || strcmp("near", p) == 0 || strcmp("register", p) == 0 || strcmp("return", p) == 0 || strcmp("short", p) == 0 || strcmp("signed", p) == 0 || strcmp("static", p) == 0 || strcmp("struct", p) == 0 || strcmp("switch", p) == 0 || strcmp("typedef", p) == 0 || strcmp("union", p) == 0 || strcmp("unsigned", p) == 0 || strcmp("void", p) == 0 || strcmp("while", p) == 0 || strcmp("far", p) == 0)
			{
				gotoxy(2, k);
				cprintf("\n%s", p);
				k++;
				goto abc;
			}
	   //function
			if (strcmp("printf", p) == 0 || strcmp("scanf", p) == 0 || strcmp("clrscr", p) == 0 ||
			strcmp("getch", p) == 0 || strcmp("strcat", p) == 0 || strcmp("strlen", p) == 0  ||
			strcmp("strcpy", p) == 0 || strcmp("strcmp", p) == 0 || strcmp("calloc", p) == 0 ||
			strcmp("malloc", p) == 0 )
			{
				gotoxy(17, f);
				cprintf("\n%s",p);
				f++;
				goto abc;
			}

	   //variable
			if (strcmp("auto", p) == 0 || strcmp("break", p) == 0 || strcmp("case", p) == 0 ||           //keywords are not variables
				strcmp("char", p) == 0 || strcmp("const", p) == 0 || strcmp("continue", p) == 0 ||
				strcmp("default", p) == 0 || strcmp("do", p) == 0 || strcmp("double", p) == 0 ||
				strcmp("else", p) == 0 || strcmp("enum", p) == 0 || strcmp("extern", p) == 0 ||
				strcmp("float", p) == 0 || strcmp("for", p) == 0 || strcmp("goto", p) == 0 ||
				strcmp("if", p) == 0 || strcmp("int", p) == 0 || strcmp("long", p) == 0 ||
				strcmp("near", p) == 0 || strcmp("register", p) == 0 || strcmp("return", p) == 0 ||
				strcmp("short", p) == 0 || strcmp("signed", p) == 0 || strcmp("static", p) == 0 ||
				strcmp("struct", p) == 0 || strcmp("switch", p) == 0 || strcmp("typedef", p) == 0 ||
				strcmp("union", p) == 0 || strcmp("unsigned", p) == 0 || strcmp("void", p) == 0 ||
				strcmp("while", p) == 0 || strcmp("far", p) == 0 || strcmp("printf", p) == 0 || strcmp("scanf", p) == 0 || strcmp("clrscr", p) == 0 ||
				strcmp("getch", p) == 0 || strcmp("strcat", p) == 0 || strcmp("strlen", p) == 0  ||
				strcmp("strcpy", p) == 0 || strcmp("strcmp", p) == 0 || strcmp("calloc", p) == 0 ||
				strcmp("malloc", p) == 0)
			{
				goto abc;
			}
			else
			{
				for (i = 0; i < strlen(p); i++)                    //strlen to calculate the length of a token
				{
					if ((p[i] >= 65 && p[i] <= 90) || (p[i] >= 97 && p[i] <= 122))          //scanning ascii values of token
					{

						for (i = 1; i < strlen(p);)
						{
							if ((p[i] >= 65 && p[i] <= 90) || (p[i] >= 97 && p[i] <= 122) || (p[i] >= 48 && p[i] <= 57))
							{
								++i;
							}

						}//nested for
					}
					else
					{
						goto xyz;
					}

				}//for

				if (flag != 0)
				{
					gotoxy(34, v);
					cprintf("\n%s", p);
					v++;
				}

				//constant
			xyz:for (i = 0; i < strlen(p);)
				{
					if ((p[i] >= 48 && p[i] <= 57) || (p[i] == 46) || (p[i] == 45))  //scanning ascii value of tokens
					{
						i++;
					}
					else
					{
						goto abc;
					}

				} //for

				if (flag != 0)
				{
					gotoxy(50, c);
					cprintf("\n%s", p);
					c++;
				}



			}
		abc:	p = strtok(NULL, " ,;:/?|\_~$#%&*-+<>()[]{}\"=");
		}

		q = strtok(copy, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ");
			while (q != NULL)
			{
				gotoxy(67, d);
				cprintf("\n%s", q);
				d++;
				q = strtok(NULL, " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
			}//while

			printf("\n\n--------------------------------------------------------------------------");


  getch();
}


/*	if (strcmp("printf", p) == 0 || strcmp("scanf", p) == 0 || strcmp("clrscr", p) == 0 ||
	strcmp("getch", p) == 0 || strcmp("strcat", p) == 0 || strcmp("strlen", p) == 0  ||
	strcmp("strcpy", p) == 0 || strcmp("strcmp", p) == 0 || strcmp("calloc", p) == 0 ||
	strcmp("malloc", p) == 0 ) */