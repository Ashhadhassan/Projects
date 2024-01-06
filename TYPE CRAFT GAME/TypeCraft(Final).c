#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<unistd.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"
#define COLOR_MAGENTA "\033[0;35m"
#define COLOR_CYAN "\033[0;36m"
#define COLOR_ORANGE "\033[38;2;255;165;0m"

#define TEXT_BOLD "\033[1m"
#define TEXT_RESET "\033[0m"

void disp_features(char *playerName, int level, int score, int lives)
{
	system("cls");
    printf(TEXT_BOLD COLOR_YELLOW "\n\t\t\t\t\t\t\t\t\t\t\t\tPlayer Name: %s" COLOR_RESET TEXT_RESET, playerName);
    printf(TEXT_BOLD COLOR_BLUE "\n\t\t\t\t\t\t\t\t\t\t\t\tLevel: %d" COLOR_RESET TEXT_RESET, level);
	printf(TEXT_BOLD COLOR_GREEN "\n\t\t\t\t\t\t\t\t\t\t\t\tScore: %d" COLOR_RESET TEXT_RESET, score);
    printf(TEXT_BOLD COLOR_RED "\n\t\t\t\t\t\t\t\t\t\t\t\tLives: %d" COLOR_RESET TEXT_RESET, lives);
 
}

void LetterTypingGame(char *playerName, int level)
{

    int seconds;
    switch (level)
	{	
        case 1:
            seconds = 6;
            printf(TEXT_BOLD COLOR_GREEN "LEVEL:"COLOR_GREEN" EASY" TEXT_RESET COLOR_RESET);
            printf("\nYou will have %d seconds to type each letter.\n", seconds);
            sleep(3);
            break;
        case 2:
            seconds = 3;
            printf(TEXT_BOLD COLOR_ORANGE"LEVEL: MEDIUM" TEXT_RESET COLOR_RESET);
            printf("\nYou will have %d seconds to type each letter.\n", seconds);
            sleep(3);
            break;
        case 3:
            seconds=1;
            printf(TEXT_BOLD COLOR_RED "LEVEL: HARD" TEXT_RESET COLOR_RESET);
            printf("\nYou will have %d seconds to type each letter.\n", seconds);
            sleep(3);
            break;
        default:
            seconds = 6;
            printf("Wrong Input, Defaulting to\n");
            printf(TEXT_BOLD COLOR_GREEN "LEVEL: EASY" TEXT_RESET COLOR_RESET);
            printf("\nYou will have %d seconds to type each letter.\n", seconds);
            sleep(4);
            break;
        }

        int score=0;
        int lives=3;
        int i=0;

    while (lives>0) 
	{        
        disp_features(playerName, level, score, lives);
        srand(time(NULL));
        char randomLetter='A'+rand()%52;       
        printf(TEXT_BOLD "\nLetter: %c\n" TEXT_RESET ,randomLetter);
    
        time_t startTime = time(NULL);
        char userLetter;
        printf("\n");
        userLetter=getch();
        time_t endTime = time(NULL);
        int GuessTime=difftime(endTime, startTime);

        if (userLetter==randomLetter && GuessTime<=seconds)
		{
            printf(COLOR_GREEN "\nCorrect! +1 points:)\n" COLOR_RESET);
            score++;
        } 
        else if (userLetter != randomLetter)
		{
            printf(COLOR_RED "\nWrong guess! You lost a life :(\n" COLOR_RESET);
            lives--;
        }
        else if (GuessTime>seconds) 
		{
            printf(COLOR_RED "\nYou guessed late! You lost a life :(\n" COLOR_RESET);
            lives--;
        }

        sleep(1);
        i++;
    }
    disp_features(playerName, level, score, lives);
    if (lives == 0)
		{
            printf("\n\n-------------------------------------------------------------------------------------------------------");
            printf(TEXT_BOLD COLOR_RED "\n\n\t\t\t\t\tGame Over! You've ran out of lives.\n" COLOR_RESET TEXT_RESET);
        }
    printf(COLOR_GREEN "\nYour final score: %d", score);
    float accuracy=(float)score/i*100;
    printf("\nYour typing accuracy is %.2f" COLOR_RESET  ,accuracy);
}

void SentenceTypingGame(char *playerName, int level) {

    char sentences[46][700]=
	{
        "Your time is limited, don't waste it living someone else's life.",
        "The only limit to our realization of tomorrow will be our doubts of today.",
        "The future belongs to those who believe in the beauty of their dreams.",
        "Happiness depends upon ourselves.",
        "Life is 10 percent what happens to us and 90 percent how we react to it.",
        "Success is not final, failure is not fatal: It is the courage to continue that counts.",
        "Life is like a camera. Focus on what's important, capture the good times, develop from the negatives, and if things don't work out, take another shot.",
        "The only way to do great work is to love what you do.",
        "You miss 100 percent of the shots you don't take.",
        "Strive not to be a success, but rather to be of value.",
        "The best revenge is massive success.",
        "In the midst of winter, I found there was, within me, an invincible summer.",
        "Believe you can and you're halfway there.",
        "We may encounter many defeats but we must not be defeated.",
        "The only person you are destined to become is the person you decide to be.",
        "Success is walking from failure to failure with no loss of enthusiasm.",
        "You get what you give, so give kindly.",
        "You have to expect things of yourself before you can do them.",
        "Change your thoughts and you change your world.",
        "The secret of getting ahead is getting started.",
        "I can't change the direction of the wind, but I can adjust my sails to always reach my destination.",
        "If opportunity doesn't knock, build a door, and then knock that door.",
        "Success is not how high you have climbed, but how you make a positive difference to the world.",
        "The only true wisdom is in knowing you know nothing.",
        "The road to success and the road to failure are almost exactly the same, its the little decision you take in the middle that define it",
        "Either you run the day, or the day runs you its your choice entirely.",
        "The best way to predict the future is to invent it and you have got to work hard to get it.",
        "Whether you think you can or you think you can't, you're right.",
        "The only thing standing between you and your goal is the story you keep telling yourself as to why you can't achieve it.",
        "It always seems impossible until it's done.",
        "Your positive action combined with positive thinking results in success.",
        "Wake up with determination, go to bed with satisfaction.",
        "Believe in yourself and all that you are. Know that there is something inside you that is greater than any obstacle.",
        "Don't watch the clock; do what it does. Keep going.",
        "The only place where success comes before work is in the dictionary.",
        "The quick brown fox jumps over the lazy dog.",
        "By the crackling fireplace, she sipped hot cocoa, wrapped in a cozy blanket. Outside, snowflakes fell, creating a winter wonderland. A magical night, embraced by warmth and tranquility.",
        "Sunflowers nodded in the sun-dappled meadow as children played tag. Laughter blended with melodies of chirping birds. Nature's symphony echoed through the radiant scene of joy.",
        "An old bookstore on the corner, shelves lined with stories waiting to be explored. Aged paper and ink scents filled the air, inviting readers into a world of endless possibilities.",
        "In the bustling market, vendors showcased vibrant fruits and vegetables. The rich aroma of spices created a sensory feast. Visitors immersed themselves in the vibrant tapestry of market life.",
        "Shadows danced on walls as a lone streetlamp flickered in the quiet alley. A prowling cat and distant footsteps added a mysterious rhythm to the night, creating an enigmatic atmosphere.",
		"Rows of tulips stood proudly in the sunlit garden, petals a vibrant symphony of colors. Bees buzzed happily, collecting nectar. A living canvas unfolded, capturing the essence of nature's beauty.",
		"With a canvas in hand, she painted strokes mirroring the sunset. The evening sky transformed into a masterpiece, capturing the essence of a peaceful day in vibrant hues.",
		"A rustic wooden bridge crossed a babbling brook in the heart of the forest. Sunlight filtered through leaves, dappling the path. Nature's tranquility embraced the scene, a peaceful haven.",
		"Moonlit night cast a silvery glow on the calm lake. Frogs croaked softly, fireflies danced. A magical scene unfolded under the starry sky, blending nature's elements into a mesmerizing panorama.",
		"In the quiet alley, shadows played on walls. A flickering streetlamp and prowling cat added mystery. Distant footsteps echoed, creating an enigmatic ambiance in the heart of the night."		
    };

    int seconds;
    switch (level)
	{
        case 1:
            seconds=40;
            printf(TEXT_BOLD COLOR_GREEN "LEVEL:"COLOR_GREEN" EASY" TEXT_RESET COLOR_RESET);
            printf("\nYou will have %d seconds to type each sentence.\n", seconds);
            sleep(3);
            break;
        case 2:
            seconds=32;
            printf(TEXT_BOLD COLOR_ORANGE"LEVEL: MEDIUM" TEXT_RESET COLOR_RESET);
            printf("\nYou will have %d seconds to type each sentence.\n", seconds);
            sleep(3);
            break;
        case 3:
            seconds=25;
            printf(TEXT_BOLD COLOR_RED "LEVEL: HARD" TEXT_RESET COLOR_RESET);
            printf("\nYou will have %d seconds to type each sentence.\n", seconds);
            sleep(3);
            break;
        default:
            seconds=40;
            printf("Wrong Input, Defaulting to\n");
            printf(TEXT_BOLD COLOR_GREEN "LEVEL:"COLOR_GREEN" EASY" TEXT_RESET COLOR_RESET);
            printf("\nYou will have %d seconds to type each sentence.\n", seconds);
            sleep(4);
            break;
        }

        int score = 0;
        int lives = 3;
        int i = 0;

    while (lives > 0)
	{        
        srand(time(NULL));
        int randomIndex = rand()%46;
        char sentence[500];
        strcpy(sentence, sentences[randomIndex]);

        disp_features(playerName, level, score, lives);
        printf(TEXT_BOLD "\nType this sentence:\n\n%s\n" TEXT_RESET ,sentence);
        
        time_t startTime = time(NULL);
        char userSentence[500];
        printf("\n");
        scanf(" %[^\n]s", userSentence);
        userSentence[strcspn(userSentence, "\n")] = '\0';
        time_t endTime = time(NULL);
        int GuessTime = difftime(endTime, startTime);

        if (strcmp(userSentence, sentence) == 0 && GuessTime <= seconds) {
            printf(COLOR_GREEN "\nCorrect! +5 points :)\n" COLOR_RESET);
            score = score + 5;
            }

        else if (strcmp(userSentence, sentence) != 0){
            printf(COLOR_RED "\nWrong Sentence! You lost a life :(\n" COLOR_RESET);
            lives = lives - 1;
            }
         
        else if (GuessTime > seconds) {
            printf(COLOR_RED "\nYou did not type within the time limit! You lost a life :(\n" COLOR_RESET);
            lives = lives - 1;
        }

        sleep(2);
        i = i + 5;
    }
		disp_features(playerName, level, score, lives);
    if (lives == 0)
		{
            printf("\n\n-------------------------------------------------------------------------------------------------------");
            printf(TEXT_BOLD COLOR_RED "\n\n\t\t\t\t\tGame Over! You've ran out of lives.\n" COLOR_RESET TEXT_RESET);
        }
    printf(COLOR_GREEN "\nYour final score: %d", score);
    float accuracy = (float)score/i * 100;
    printf("\nYour typing accuracy is %.2f" COLOR_RESET  ,accuracy);
}

void ArithmeticGame(char *playerName, int level) {

    int seconds;
    switch (level) {
        case 1:
            seconds=7;
            printf(TEXT_BOLD COLOR_GREEN "LEVEL:"COLOR_GREEN" EASY" TEXT_RESET COLOR_RESET);
            printf("\nYou will have %d seconds to type the answer.\n", seconds);
            sleep(2);
            break;
        case 2:
            seconds =3;
            printf(TEXT_BOLD COLOR_ORANGE"LEVEL: MEDIUM" TEXT_RESET COLOR_RESET);
            printf("\nYou will have %d seconds to type the answer.\n", seconds);
            sleep(3);
            break;
        case 3:
            seconds =2;
            printf(TEXT_BOLD COLOR_RED "LEVEL: HARD" TEXT_RESET COLOR_RESET);
            printf("\nYou will have %d seconds to type the answer.\n", seconds);
            sleep(3);
            break;
        default:
            seconds =7;
            printf("Wrong Input, Defaulting to\n");
            printf(TEXT_BOLD COLOR_GREEN "LEVEL:"COLOR_GREEN" EASY" TEXT_RESET COLOR_RESET);
            printf("\nYou will have %d seconds to type the answer.\n", seconds);
            sleep(4);
            break;
        }

        int score = 0;
        int lives = 3;
        int i = 0;

        while (lives > 0) {        
        disp_features(playerName, level, score, lives);
        srand(time(NULL));
        int a = rand() % 20; 
        int b = rand() % 12;
        char operators[3] = {'+', '-', '*'};
        char operator = operators[rand() % 3];

        printf(TEXT_BOLD "\nWhat is %d %c %d?\n" TEXT_RESET ,a, operator, b);

        int result;
        switch (operator)
		{
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            default:
                break;
        }
    
        time_t startTime = time(NULL);
        int userAnswer;
        printf("\nAnswer: ");
        scanf("%d", &userAnswer);
        time_t endTime = time(NULL);
        int GuessTime = difftime(endTime, startTime);

        if (userAnswer == result && GuessTime <= seconds) {
            printf(COLOR_GREEN "\nCorrect! +2 points :)\n" COLOR_RESET);
            score = score + 2;
        } 
        else if (userAnswer != result) {
            printf(COLOR_RED "\nWrong answer! You lost a life :(\n" COLOR_RESET);
            lives = lives - 1;
        }
        else if (GuessTime > seconds) {
            printf(COLOR_RED "\nYou guessed late! You lost a life :(\n" COLOR_RESET);
            lives = lives - 1;
        }

        sleep(1);
        i+=2;
    }
	disp_features(playerName, level, score, lives);
    if (lives == 0)
		{
            printf("\n\n-------------------------------------------------------------------------------------------------------");
            printf(TEXT_BOLD COLOR_RED "\n\n\t\t\t\t\tGame Over! You've ran out of lives.\n" COLOR_RESET TEXT_RESET);
        }
    printf(COLOR_GREEN "\nYour final score: %d", score);
    float accuracy = (float)score/i * 100;
    printf("\nYour guessing accuracy is %.2f" COLOR_RESET  ,accuracy);
}

void displayInstructions() {
    system ("cls");
    FILE *filePointer;
    char ch;

    filePointer = fopen("game_instructions.txt", "r");

    if (filePointer == NULL)
	{
        printf("Unable to open the file.\n");
        return;
    }

    printf("--------------------------------------------------------------GAME INSTRUCTIONS--------------------------------------------------------------\n\n\n");

    while ((ch = fgetc(filePointer)) != EOF) {
        printf("%c", ch);
    }

    printf("\n");

    fclose(filePointer);
}

void playGame() 
{
    char playerName[50],retMenu;
    int level;
    int gameChoice;
       
    printf(TEXT_BOLD COLOR_CYAN "\nGAMES:\n" COLOR_RESET TEXT_RESET);
    printf("1. Letter Typing Game\n");
    printf("2. Sentence Typing Game\n");
    printf("3. Arthmetic Game\n");
    printf(COLOR_CYAN "Enter your choice: " COLOR_RESET); 
    scanf("%d", &gameChoice);
	  
    switch (gameChoice) 
	{
        case 1:
        	printf(TEXT_BOLD COLOR_YELLOW "\nDIFFICULTY LEVEL:" COLOR_RESET TEXT_RESET);
    		printf("\n1. Easy\n2. Medium\n3. Hard\n");
    		printf(COLOR_MAGENTA "Enter your choice: " COLOR_RESET);
    		scanf("%d", &level);

    		printf("\nEnter Your Name: ");
   			scanf("%s", playerName);
    		printf("\nWELCOME, ");
    		printf(TEXT_BOLD COLOR_BLUE "%s!\n" COLOR_RESET TEXT_RESET ,playerName);
            LetterTypingGame(playerName, level);
            break;
        case 2:
        	printf(TEXT_BOLD COLOR_YELLOW "\nDIFFICULTY LEVEL:" COLOR_RESET TEXT_RESET);
    		printf("\n1. Easy\n2. Medium\n3. Hard\n");
   			printf(COLOR_MAGENTA "Enter your choice: " COLOR_RESET);
   			scanf("%d", &level);

   			printf("\nEnter Your Name: ");
   			scanf("%s", playerName);
    		printf("\nWELCOME, ");
    		printf(TEXT_BOLD COLOR_BLUE "%s !\n" COLOR_RESET TEXT_RESET ,playerName);
            SentenceTypingGame(playerName, level);
            break;
        case 3:
        	printf(TEXT_BOLD COLOR_YELLOW "\nDIFFICULTY LEVEL:" COLOR_RESET TEXT_RESET);
   			printf("\n1. Easy\n2. Medium\n3. Hard\n");
    		printf(COLOR_MAGENTA "Enter your choice: " COLOR_RESET);
   			scanf("%d", &level);

    		printf("\nEnter Your Name: ");
   			scanf("%s", playerName);
    		printf("\nWELCOME, ");
    		printf(TEXT_BOLD COLOR_BLUE "%s !\n" COLOR_RESET TEXT_RESET ,playerName);
            ArithmeticGame(playerName, level);            
            break;
        default:
            printf("\nInvalid choice!\n");
            printf(TEXT_BOLD COLOR_YELLOW"\n\nReturn To the main menu y/n:"COLOR_RESET TEXT_RESET);
        scanf(" %c",&retMenu);
        if(retMenu=='y')
        {
        	mainMenu();
		}
		else
		exit(0);
        break;
    }
}

void mainMenu() 
{
    system("cls");
    int mainMenuChoice;
    char returnMenu;
    printf(TEXT_BOLD COLOR_CYAN "\n\n\t\t\t\t\tTYPECRAFT: WORD & MATH ADVENTURES\n\n" COLOR_RESET TEXT_RESET);
    printf(COLOR_GREEN "\n1. Play Game !\n" COLOR_RESET);
    printf(COLOR_RED "2. Instructions.\n" COLOR_RESET);
    printf("Enter your choice: ");
    scanf("%d", &mainMenuChoice);
    switch (mainMenuChoice)
    {
    case 1:
        playGame();
        break;
    case 2:
        displayInstructions();
        printf(TEXT_BOLD COLOR_YELLOW"\n\nReturn To the main menu y/n:"COLOR_RESET TEXT_RESET);
        scanf(" %c",&returnMenu);
        if(returnMenu=='y')
        {
        	mainMenu();
		}
		else
		exit(0);
        break;
    default:
        printf("\nInvalid choice!\n");
        printf(COLOR_YELLOW"\nDo you want to restart y/n:"COLOR_RESET);
        scanf(" %c",&returnMenu);
        if(returnMenu=='y')
        mainMenu();
        else
        exit(0);
        break;
    }
}

int main() 
{
    int re;
    do 
	{
        mainMenu();
        printf("\n\nDo you want to play again ? (y/n): ");
        scanf(" %c", &re);
    }
    while(re!='n');
    if(re=='n')
	{
        return 0;
    }
    return 0;
}
