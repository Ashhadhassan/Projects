#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int i=0,m=0,c=0;
struct info
{
	char name[20];
	int wins;
};
struct info data[1000];
void display()
{
	int rows=10;
	int columns=10;
		char **arr=(char**) calloc(rows,sizeof(char*));
	for(i=0;i<rows;i++)
	{
		*(arr+i)=(char*) calloc(columns,sizeof(char));
	}
    const int size = 10;
    int board[10][10] = 
	{
        {100, 99, 98, 97, 96, 95, 94, 93, 92, 91},
        {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
        {80, 79, 78, 77, 76, 75, 74, 73, 72, 71},
        {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
        {60, 59, 58, 57, 56, 55, 54, 53, 52, 51},
        {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
        {40, 39, 38, 37, 36, 35, 34, 33, 32, 31},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {20, 19, 18, 17, 16, 15, 14, 13, 12, 11},
        { 1,  2,  3,  4,  5,  6,  7,  8,  9, 10}
    };
    int j ;
	for (i = 0; i < rows; i++)
	{
        for (j = 0; j < columns; j++)
	    {
	        *(*(arr + i) + j) = board[i][j];
        }
    }
    printf("__________________________________________________________________________\n\n");
    for (i = 0; i < rows; i++)
	{
	    printf("*");
        for (j = 0; j < columns; j++)
	    {
	        if((i==0)&&(j==0))
	        {
	             printf("| ");
	        }
	        else
	        {
	             printf("|  ");
	        }
	        if((i==9)&&(j<9))
	        {
	            printf("%d   ",*(*(arr + i) + j));
	        }
	        else
	        {
	            printf("%d  ",*(*(arr + i) + j));
	        }
        }
        printf("|*\n");
    }
    printf("__________________________________________________________________________\n\n");
    printf("LADDER -> 02 - 23\t\tSNAKE -> 31 - 14\nLADDER -> 08 - 12\t\tSNAKE -> 41 - 20\nLADDER -> 17 - 93\t\tSNAKE -> 58 - 37\nLADDER -> 29 - 54\t\tSNAKE -> 67 - 49\nLADDER -> 32 - 51\t\tSNAKE -> 84 - 62\nLADDER -> 39 - 80\t\tSNAKE -> 92 - 76\nLADDER -> 70 - 89\t\tSNAKE -> 99 - 04\nLADDER -> 75 - 96\n");
    printf("__________________________________________________________________________\n\n");
}
void instructions()
{
	printf("Turns: The player and computer take turns rolling the dice and moving their token by the number rolled.\n\nMovement: Move the token forward the number of spaces shown on the dice. If you land on the bottom of a ladder, move your token to the top of the ladder. If you land on the head of a snake, move    your token to the tail of the snake.\n\nExtra Roll: If a player rolls a 6, they get another turn after moving. If a player rolls 3 6's consecutively,their turn will be terminated\n\nWinning: The first player to reach the final square (100) wins\n");
}

void previousWins()
{
	FILE* fptr;
    char content[30];
	fptr = fopen("score.txt","r");
	if(fptr != NULL)
		{
		    while(fgets(content,30,fptr))
		    {
		        printf("%s",content);
		    }
		}
	else
	{
	    printf("No Game played yet\n");
	}
	fclose(fptr);
}

int rollDice() 
{

    int result = (rand() % 6) + 1;

    return result;
}

int snake(int a)
{
	switch(a)
	{
		case 31:
		    printf("Oops! You had a snake encounter\n");
			return 14;
			break;
		case 41:
		    printf("Oops! You had a snake encounter\n");
			return 20;
			break;
		case 58:
		    printf("Oops! You had a snake encounter\n");
			return 37;
			break;	
		case 67:
		    printf("Oops! You had a snake encounter\n");
			return 49;
			break;
		case 84:
		    printf("Oops! You had a snake encounter\n");
			return 62;
			break;
		case 92:
		    printf("Oops! You had a snake encounter\n");
			return 76;
			break;	
		case 99:
		    printf("Oops! You had a snake encounter\n");
			return 4;
			break;
		default:
		    return a;
	}
}

int ladder(int a)
{
	switch(a)
	{
		case 2:
		    printf("Congragulations! You reached a ladder\n");
			return 23;
			break;
		case 8:
		    printf("Congragulations! You reached a ladder\n");
			return 12;
			break;
		case 17:
		    printf("Congragulations! You reached a ladder\n");
			return 93;
			break;	
		case 29:
		    printf("Congragulations! You reached a ladder\n");
			return 54;
			break;
		case 32:
		    printf("Congragulations! You reached a ladder\n");
			return 51;
			break;	
		case 39:
		    printf("Congragulations! You reached a ladder\n");
			return 80;
			break;
		case 70:
		    printf("Congragulations! You reached a ladder\n");
			return 89;
			break;	
		case 75:
		    printf("Congragulations! You reached a ladder\n");
			return 96;
			break;	
		default:
		  return a;
	}
}

int NewGame()
{
	srand(time(NULL));
	char content[20]="Computer";
	char name[20];
	printf("Enter Name = ");
	scanf("%s",name);
	int pos1=0,pos2=0,x=0,z,y;
	while((pos1<100)&&(pos2<100))
	{
		z=0;
		y = 100 - pos1;
		printf("%s's turn!\n",name);
		printf("Press enter to roll the dice \n");
		getchar();
		x = rollDice();
		printf("Dice landed on %d\n",x);
		if(pos1==0)
		{
		    z = z + x;
			if(x==6)
			{
				printf("%s's turn again \n",name);
				printf("Press enter to roll the dice \n");
		        getchar();
				x = rollDice();
				printf("Dice landed on %d\n",x);
				z = z + x;
			    if(x==6)
			    {
			        printf("%s's turn again \n",name);
				    printf("Press enter to roll the dice \n");
		            getchar();
			        x = rollDice();
			    	printf("Dice landed on %d\n",x);
			    	z = z + x;
			    	if(x==6)
			    	{
			    		printf("Too many 6's \nTurn discarded\n");
			    		z = 0;
					}
				}
			}
		}
		else
		{
			z = z + x;
			if(z<=y)
			{
				if(x==6)
			    {
				    printf("%s's turn again \n",name);
				    printf("Press enter to roll the dice \n");
		            getchar();
				    x = rollDice();
				    printf("Dice landed on %d\n",x);
				    z = z + x;
				    if(z<=y)
				    {
				    	if(x==6)
				        {
				        	printf("%s's turn again \n",name);
				            printf("Press enter to roll the dice \n");
		                    getchar();
				            x = rollDice();
				            printf("Dice landed on %d\n",x);
					        z = z + x;
					        if(z<=y)
					        {
					        	if(x==6)
					        	{
					        		printf("Too many 6's \nTurn discarded");
					        		z = 0;
								}
							}
				        }
					}
					else
					{
						z = 0;
					}
			    }
			}
			else
			{
				z = 0;
			}
		}
		pos1 = pos1 + z;
		pos1 = snake(pos1);
		pos1 = ladder(pos1);
		printf("Current position of %s = %d\n\n",name,pos1);
		
		
		z=0;
		y = 100 - pos2;
		printf("Computer's turn!\n");
		x = rollDice();
		printf("Dice landed on %d\n",x);
		if(pos2==0)
		{
		    z = z + x;
			if(x==6)
			{
				printf("Computer's turn again \n");
				x = rollDice();
				printf("Dice landed on %d\n",x);
				z = z + x;
			    if(x==6)
			    {
			        printf("Computer's turn again \n");
			        x = rollDice();
			    	printf("Dice landed on %d\n",x);
			    	z = z + x;
			    	if(x==6)
			    	{
			    		printf("Too many 6's \nTurn discarded");
			    		z = 0;
					}
				}
			}
		}
		else
		{
			z = z + x;
			if(z<=y)
			{
				if(x==6)
			    {
				    printf("Computer's turn again \n");
				    x = rollDice();
				    printf("Dice landed on %d\n",x);
				    z = z + x;
				    if(z<=y)
				    {
				    	if(x==6)
				        {
				        	printf("Computer's turn again \n");
				            x = rollDice();
				            printf("Dice landed on %d\n",x);
					        z = z + x;
					        if(z<=y)
					        {
					        	if(x==6)
					        	{
					        		printf("Too many 6's \nTurn discarded");
					        		z = 0;
								}
							}
				        }
					}
					else
					{
						z = 0;
					}
			    }
			}
			else
			{
				z = 0;
			}
		}
		pos2 = pos2 + z;
		pos2 = snake(pos2);
		pos2 = ladder(pos2);
		printf("Current position of Computer = %d\n\n",pos2);
    }
    FILE* fptr; 
	if(pos1==100)
	{
		printf("Congragulations! You win\n");
		for(i=0;i<m;i++)
		{
			if(strcmp(name,data[i].name)==0)
			{
				data[i].wins = data[i].wins + 1;
				i = m;
				c = 1;
			}
		}
		if(c==0)
		{
			strcpy(data[m].name,name);
		    data[m].wins = 1;
		    m++;
		}
	}
	else if(pos2==100)
	{
		printf("Computer wins! Better luck next time\n");
		for(i=0;i<m;i++)
		{
			if(strcmp(content,data[i].name)==0)
			{
				data[i].wins = data[i].wins + 1;
				c = 1;
				i = m;
			}
		}
		if(c==0)
		{
			strcpy(data[m].name,content);
		    data[m].wins = 1;
		    m++;
		}
	}
	else
	{
	    printf("Error");
	}
	fptr = fopen("score.txt","w");
	for(i=0;i<m;i++)
	{
		fprintf(fptr,"%s  %d\n",data[i].name,data[i].wins);
	}
	fclose(fptr);
}
int main() 
{
    int choice;
    printf("\t\t\t\t*GAME BOARD*\n");
    display();
    while(i>=0)
    {
    	printf("\n\t\t\tWELCOME TO SNAKE & LADDER GAME\n\n1 : Start New Game\n2 : View Instructions\n3 : Display Previous Scores\n\nSelect Option = ");
        scanf("%d",&choice);
	    switch(choice)
	    {
		    case 1:
			    NewGame();
			    break;
		    case 2:
		        instructions();
			    break;
		    case 3:
		        previousWins();
			    break;
		    default:
		        printf("INVALID CHOICE\n");			
	    }
    }
}
