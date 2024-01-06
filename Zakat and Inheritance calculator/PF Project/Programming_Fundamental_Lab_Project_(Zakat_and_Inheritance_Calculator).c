/*
In this project of zakat and inheritance calculator the calculations are based on islamic laws
referred by following scholers (DR. ISRAR AHMED, DR. ZAKIR NAIK, MOLANA TARIQ MASOOD) in there videos 
the links of videos are given below
1. https://www.youtube.com/watch?v=L6sZhqbPSc0
2. https://www.youtube.com/watch?v=XHP8iK77cxU
3. https://www.youtube.com/watch?v=IB8FX3jq2vU
4. https://www.youtube.com/watch?v=NAgUUqsY9T4
5. https://www.youtube.com/watch?v=HPayRACgdi4
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct zakat
{
    float cash, stocks, lent, property, gold, silver;
	float debt, bills, wages;
	float crops;
	int cattle, camels, sheep;
	char irrigation;
}z;
void intro();
int asking_options();
int zakat_page();
void input();
void farming();
void zakat_calculations();
void references_of_Zakat();
int inheritance_page();
void inheritance_calculator();
void references_of_inheritance();


int main()
{ 

	intro();
	int choice=asking_options();
	while(!(choice==1 || choice==2))
	{
			choice=asking_options();
	}
	if(choice==1)
	{
		int n=zakat_page();
		while(!(n==1 || n==2))
		{
			n=zakat_page();
		}
		
		switch(n)
		{
			case 1:
				{
					char ask;
				do
				{
				
				zakat_calculations();
				
				printf("\t\t\t\t-----------------------------------------------------------------\t\n");
				printf("\t\t\t\t|   Do you want to use it again then press 'Y' else press 'N'   |\n");
				printf("\t\t\t\t-----------------------------------------------------------------\t\n");
				printf("\t\t\t\t");
				scanf(" %c",&ask);
				system("cls");
				}while((ask=='y' || ask=='Y'));
				system("cls");
				printf("\t\t\t\t-----------------------------------------------------------------\t\n");
				printf("\t\t\t\t|      Thank you for using our calculator  Assalam Alaikum      |\n");
				printf("\t\t\t\t-----------------------------------------------------------------\t\n");
			}
				break;
			case 2:
				{
				references_of_Zakat();
				}
				break;	 
		}
		
	}
	else if(choice==2)
	{
		int n=inheritance_page();
		switch(n)
		{
			case 1:
				{
					
				inheritance_calculator();
				}
				break;
			case 2:
					{
						references_of_inheritance();
						
					}
		}
		
		
	}
	
	return 0;
}
void intro()
{
	int enter;
	printf("\t\t\t\t-----------------------------------------------------------------\n");
	printf("\t\t\t\t|   In the name of ALLAH who is most kind and most marcifull\t|\n");
	printf("\t\t\t\t-----------------------------------------------------------------\t\n");
	printf("\t\t\t\t|      Welcome to ZAKAT and INHERITANCE calculator        \t|\n");	
	printf("\t\t\t\t-----------------------------------------------------------------\t\n");
	printf("\t\t\t\t|              Press Enter to continue                    \t|\n");
	printf("\t\t\t\t-----------------------------------------------------------------\t\n");
	printf("\n\n\n");
	scanf("%c",&enter);
	system("cls");
	
}
int asking_options()
{
	system("cls");
	int n;
	printf("\t\t\t---------------------------\n");
	printf("\t\t\t|  Select the calculator  |\n");
	printf("\t\t\t---------------------------\n");
	printf("\n\n");
	printf("\t\t\t--------------------------------------\n");
	printf("\t\t\t|    Press 1 for ZAKAT calculator    |\n");
	printf("\t\t\t| Press 2 for INHERITANCE calculator |\n");
	printf("\t\t\t--------------------------------------\n");
	printf("\n\t\t\t");
	scanf("%d", &n);
	system("cls");
	return n;
	
}
int zakat_page()
{
	system("cls");
	int n;
	printf("\t\t\t----------------------------------------\n");
	printf("\t\t\t|   Press 1 for ZAKAT Calculations     |\n");
	printf("\t\t\t| Press 2 for see References of ZAKAT  |\n");
	printf("\t\t\t----------------------------------------\n");
	printf("\n\t\t\t");
	scanf("%d",&n);
	system("cls");
	return n;
}
//Assets
void input(){
	fflush(stdin);
	printf("\t\tWhat is the value of your property in Rs (not in personal use)? else enter 0:  ");
	scanf("%f", &z.property);
	
	if(z.cash>0) {
		printf("\t\tError");
	//	break;
	}
	else 
	printf("\t\tHow much cash do you have? else enter 0:  ");
	scanf("%f", &z.cash);
	if (z.gold >0) {
		printf("\t\tError");
		//breaak;
	}
	
	printf("\t\ttHow much gold do you have (in tola)? else enter 0:  ");
	scanf("%f", &z.gold);
	z.gold = z.gold * 185614;
	if(z.gold<185614*7.5){
		z.gold = 0;
	}
	
	printf("\t\tHow much silver do you have (in tola)? else enter 0:  ");
	scanf("%f", &z.silver);
	z.silver = z.silver * 2550;
	if(z.silver<2550*52.5){
		z.silver = 0;
	}
	
	printf("\t\tWhat is the value of stocks/shares you have invested in? else enter 0:  ");
	scanf("%f", &z.stocks);
	
	printf("\t\tHow much money have you given out as a loan else enter 0:  ");
	scanf("%f", &z.lent);
	
	printf("\t\tDo you have any due bills else enter 0:  ");
	scanf("%f", &z.bills);
	
	printf("\t\tDo you have any due loans that need to be repaid (in debt) else enter 0:  ");
	scanf("%f", &z.debt);
	
	printf("\t\tDo you have any wages to pay workers else enter 0:  ");
	scanf("%f", &z.wages);
}


//Farming
void farming(){
	fflush(stdin);
	printf("\t\tHow many camels do you have?  ");
	scanf("%i", &z.camels);
	printf("\t\tHow many cows do you have?  ");
	scanf("%i", &z.cattle);
	printf("\t\tHow many sheeps/goats do you have?  ");
	scanf("%i", &z.sheep);
	printf("\t\tHow many crops do you have (value in weight)?   ");
	scanf("%f", &z.crops);
	if(z.crops != 0){
		fflush(stdin);
		printf("\t\tWhat was the type of irrigation used (Press R for river, Press W for wells)  ");
		scanf("%c", &z.irrigation);
		int f = 0;
		if(z.irrigation != 'R' || z.irrigation != 'W' || z.irrigation != 'r' || z.irrigation != 'w'){
			f = 1;
		}
		while(f==0){
			printf("\t\tYou did not enter R or W, please enter correctly: ");
			scanf("%c", &z.irrigation);
		}
		if(z.crops > 910){
			if(z.irrigation == 'R' || z.irrigation == 'r'){
				z.crops = z.crops*0.1;
			}
			else if(z.irrigation == 'W' || z.irrigation == 'w'){
				z.crops = z.crops*0.05;
			}
		}
		else{
			z.crops = 0;
		}
	}
}
void zakat_calculations()
{
	char c, name[30];
	char farm, fiqh[20];
	int camel, cow, shee; 
	float sum = 0;
	char sane;
	const float nisaab = 2550*52.5;	
					printf("\t\t\tEnter your full name: ");
					fflush(stdin);
					gets(name);			
					printf("\n\t\tYou are elegible for ZAKAT if and only you are sane adult\n\n");
					printf("\t\tPress 'Y' to confirm that you are adult if not then press 'N'\t");
					scanf(" %c", &sane);
					printf("\n");
					system("cls");
					if (sane != 'Y' && sane != 'y')
					{			
					system("cls");			
					printf("\t\t\t\t-----------------------------------------------------------------\t\n");
					printf("\t\t\t\t|                You don't need to pay zakaat                  \t|\n");
					printf("\t\t\t\t-----------------------------------------------------------------\t\n");
				/*	printf("\t\t\t\t-----------------------------------------------------------------\t\n");
					printf("\t\t\t\t|      Thank you for using our calculator  Assalam Alaikum      |\n");
					printf("\t\t\t\t-----------------------------------------------------------------\t\n");*/
											
					}
					input();
					fflush(stdin);
					printf("\t\t\t\t-----------------------------------------------------------------\t\n");
					printf("\t\t\t\t|              Press Enter to continue                    \t|\n");
					printf("\t\t\t\t-----------------------------------------------------------------\t\n");
					scanf("%c", &c);
					system("cls");
	
					//Calculation for Zakaat
					sum = (z.property + z.cash + z.stocks + z.lent + z.silver + z.gold) - (z.bills + z.debt + z.wages);
					//CLEAR SCREEN AND SHOW ZAKAAT
					if (sum > nisaab)
					{
					printf("\t\t\t\t-----------------------------------------------------------------\t\n");
					printf("\t\t\t\t|Zakaat you have to pay on property and cash is: %f Rs |\n",sum*0.025);
					printf("\t\t\t\t-----------------------------------------------------------------\t\n");
					}
					else
					{
					sum = 0;
					printf("\t\t\t\t-------------------------------------------------------------------------------\n");
					printf("\t\t\t\t|You do not need to pay Zakaat on property and cash, you don't meet the nisaab|\n");
					printf("\t\t\t\t-------------------------------------------------------------------------------\n");
					}
	
					printf("\n\n");
					printf("\t\t\t\t-----------------------------------------------------------------\t\n");
					printf("\t\t\t\t|              Press Enter to continue                    \t|\n");
					printf("\t\t\t\t-----------------------------------------------------------------\t\n");
					scanf("%c", &c);
					system("cls");
	
	
						//Farming
					printf("\t\tIf you are involved in farming press Y if not then press N \n\t\t(Y for yes, N for no)  ");
					scanf("%c", &farm);
					while(farm!='Y' && farm != 'N' && farm != 'y' && farm != 'n')
					{
					  printf("\t\tPlease enter Y or N only\n\t\t");
					  scanf(" %c", &farm);
				    }
				if(farm=='Y' || farm=='y')
				{
					farming();
					fflush(stdin);
					printf("\t\t\t\t-----------------------------------------------------------------\t\n");
					printf("\t\t\t\t|              Press Enter to continue                    \t|\n");
					printf("\t\t\t\t-----------------------------------------------------------------\t\n");
					scanf("%c", &c);
					system("cls");
					camel = z.camels/5;
					if(z.camels > 0 && z.camels <= 40)
					{
						printf("\t\tYou have to give %i sheep on your camels\n", camel);
					}
					else if(z.camels > 40)
					{
						camel = z.camels - 40;
						camel = z.camels/5;
						printf("\t\tYou have to give %i she-camels on your camels\n", camel+1);
					}
		
					if(z.sheep == 40 && z.sheep<121)
					{
						printf("\t\tYou need to give away 1 sheep on your sheeps\n");
					}
					else
					{
					shee = z.sheep/121;
					printf("\t\tYou need to give %i sheep away on your sheeps\n", shee);
					}
					//Cows
					if(z.cattle >= 30)
					{
						z.cattle = z.cattle - 30;
						z.cattle = z.cattle/10;
						printf("\t\tYou need to give away a cow of age %i on your cows\n", z.cattle+1);
					}
					else if(z.cattle <30 && z.cattle==0)
					{
						printf("\t\tYou do not need to give away any cows on your camels\n");
					}
					//Crops
					if(z.crops > 0)
					{
						printf("\t\tYou need to give away %f kg of crops\n", z.crops);
					}
				}
				printf("\t\t\t\t-----------------------------------------------------------------\t\n");
				printf("\t\t\t\t|              Press Enter to continue                    \t|\n");
				printf("\t\t\t\t-----------------------------------------------------------------\t\n");
				scanf("%c", &c);
				system("cls");
					printf("\n\n");
					printf("\t\t\t\t-----------------------------------------------------------------\t\n");
					printf("\t\t\t\t|       Your Zakaat due is: %f                         |\n",sum*0.025);
					printf("\t\t\t\t-----------------------------------------------------------------\t\n");
					printf("\n\n");
}
void references_of_Zakat()
{
	
	int n;
	char c;
	do
	{
	system("cls");
	printf("\n\n");
	printf("\t\t\t----------------------------------------------------\n");
	printf("\t\t\t|    REFERNCES OF ZAKAT FROM QUR'AN AND AHADITH    |\n");
	printf("\t\t\t----------------------------------------------------\n");
	printf("\n\n\n");
	printf("\t\t\t-------------------------------------------------------\n");
	printf("\t\t\t| PRESS 1 FOR QURANIC VERSES |   PRESS 2 FOR AHADITH  |\n");
	printf("\t\t\t-------------------------------------------------------\n");
	printf("\n\t\t\t");
	scanf("%d", &n);
	}while (!(n==1 || n==2));
	system("cls");
	if(n==1)
	{
		printf("\n\n1.\n");
		printf("\n\t\tYet you shall duly establish the Prayer.\n\t\tAnd you shall give the Zakat-Charity,\n\t\tand therewith lend God a most goodly loan.\n\t\tFor whatever good you advance for your souls,\n\t\tyou shall find its reward with God in the Hereafter;\n\t\tyet it shall be far better and much greater in reward\n\t\t(Surat Al-Muzzammil, 73:20).\n");
		printf("\n\n2.\n");
		printf("\n\t\tThen steadfastly continue to duly establish the Prayer,\n\t\tand give the Zakat-Charity\n\t\t(Surat Al-Mujadilah,, 58:13).\n");
		printf("\n\n3.\n");
		printf("\n\t\tFor woe to those who associate gods with God,\n\t\tthose who do not give the Zakat-Charity,\n\t\tthose who are disbelievers in the Hereafter\n\t\t(Surat Fussilat 41:7).\n");
		printf("\n\n4.\n");
		printf("\n\t\tIndeed, prescribed charitable offerings are only to be given to the poor and the indigent,\n\t\tand to those who work on administering it,\n\t\tand to those whose hearts are to be reconciled,\n\t\tand to free those in bondage, and to the debt-ridden, and for the cause of God,\n\t\tand to the wayfarer. This is an obligation from God. And God is all-knowing, all-wise\n\t\t(9:60).\n");
		printf("\n\n5.\n");	
		printf("\n\t\tMy Mercy extends to all things. That (Mercy) I shall ordain for those\n\t\twho have God-consciousness and give their Zakat and those who believe in Our Signs.\n\t\t(Surah Al-A'raf 7:156)\n");
		printf("\n\n6.\n");
		printf("\n\t\tTake from their wealth a charitable offering to cleanse them and purify them thereby\n\t\t(Surat Al-Tawbah, 9:60).\n");
		printf("\n\n7.\n");
		printf("\n\t\tAnd mention also in the Book, the tiding of Ishmael. Indeed, he was ever true to his promise.\n\t\tAnd he was a messenger and an eminent prophet. He used to enjoin his family with the Prayer and the Zakat-Charity.\n\t\tThus, to his Lord, he was ever-pleasing\n\t\t(Surat Maryam, 19:54-55).\n");
		printf("\n\n8.\n");
		printf("\n\t\tAnd we made them exemplary leaders, guiding to faith by Our command.\n\t\tFor We made them prophets and revealed to them Our commandments bidding the doing of good works,\n\t\tand the establishment of the Prayer and the giving of the Zakat-Charity.\n\t\tThus to Us alone did they offer worship\n\t\t(Surat Al-Anbiya, 21:73).\n");
		printf("\n\n9.\n");
		printf("\n\t\tThese are the ones who when We set them in authority over the land, they duly establish the Prayer,\n\t\tand give the Zakat-Charity, and enjoin what is right and forbid what is wrong.\n\t\tYet to God alone belongs the ultimate end of all affairs\n\t\t(Surat Al-Hajj, 22:41).\n");
		printf("\n\n10.\n");
		printf("\n\t\tAnd thus has He made me blessed, wherever I may be. And further,\n\t\tHe has enjoined me to be ever observant of the Prayer, and to give the Zakat-Charity, as long as I am alive\n\t\t(Surat Maryam, 19:31).\n");		
	
	
	}
	else if(n==2)
	{
	
		printf("\n1.\n");
		printf("\n\t\tThe wealth of a person does not decrease by paying Zakat (Sahih Bukhari)\n");
		printf("\n2.\n");
		printf("\n\t\tOne who pays Zakat, Allah will make their wealth increase (Sahih Bukhari)\n");
		printf("\n3.\n");
		printf("\n\t\tThe best charity is to pay Zakat on one's wealth (Sahih Muslim)\n");
		printf("\n4.\n");
		printf("\n\t\tZakat is a right that the poor have upon the rich (Sahih Bukhari)\n");
		printf("\n5.\n");
		printf("\n\t\tZakat is a form of worship, and the one who fulfills it will be rewarded (Sahih Muslim)\n");
		printf("\n6.\n");
		printf("\n\t\tZakat is the right of the poor on the wealth of the rich (Sahih Bukhari)\n");
		printf("\n7.\n");
		printf("\n\t\tThe one who pays Zakat, it is as if they have freed a slave (Sahih Bukhari)\n");
		printf("\n8.\n");
		printf("\n\t\tGiving Zakat is more beloved to Allah than giving in charity during the entire year (Sahih Bukhari)\n");
		
	}
	printf("\n\n\n");
	printf("\t\t\t\t-----------------------------------------------------------------\t\n");
	printf("\t\t\t\t|              Press Enter to continue                    \t|\n");
	printf("\t\t\t\t-----------------------------------------------------------------\t\n");
	printf("\n\n\n");
	fflush(stdin);
	scanf("%c",&c);
	system("cls");
	printf("\n\n\n");
	printf("\t\t\t\t-----------------------------------------------------------------\t\n");
	printf("\t\t\t\t|      Thank you for using our calculator  Assalam Alaikum      |\n");
	printf("\t\t\t\t-----------------------------------------------------------------\t\n");

}
int inheritance_page()
{
	system("cls");
	int n;
	do
	{
	printf("\t\t\t----------------------------------------------\n");
	printf("\t\t\t|     Press 1 for INHERITANCE Calculations   |\n");
	printf("\t\t\t| Press 2 for see References of INHERITANCE  |\n");
	printf("\t\t\t----------------------------------------------\n");
	printf("\n\t\t\t");
	scanf("%d",&n);
	system("cls");
	}while(!(n==1 || n==2));
	return n;
}
void references_of_inheritance()
{
	int n;
	char c;
	do
	{
	system("cls");
	printf("\n\n");
	printf("\t\t\t----------------------------------------------------\n");
	printf("\t\t\t| REFERNCES OF INHERITANCE FROM QUR'AN AND AHADITH |\n");
	printf("\t\t\t----------------------------------------------------\n");
	printf("\n\n\n");
	printf("\t\t\t-------------------------------------------------------\n");
	printf("\t\t\t| PRESS 1 FOR QURANIC VERSES |   PRESS 2 FOR AHADITH  |\n");
	printf("\t\t\t-------------------------------------------------------\n");
	printf("\n\t\t\t");
	scanf("%d", &n);
	}while (!(n==1 || n==2));
	system("cls");
	if(n==1)
	{
		
	printf("\n1.\n");
	printf("\n\t\tAllah enjoins you concerning your children: The male shall have the equal of the portion of two females;\n\t\tand if they are more than two females, then they will have two-thirds of the inheritance; and if there is (only) one,\n\t\tshe will have the half; and as for his parents, each of them shall have a sixth part of the inheritance if he has a child,\n\t\tbut if he has no child and his parents be his heirs, then his mother shall have the third, and if he has brothers,\n\t\tthen his mother shall have the sixth after (the payment of) a bequest he may have bequeathed or a debt. You do not know which of your\n\t\tparents and your children is closer to you in usefulness. (This is) an ordinance from Allah. Verily Allah is All-Knowing, All-Wise.\n\t\t(Surah An-Nisa, Verse 11)\n");
		
	}
	else if(n==2)
	{
		printf("\n1.\n");
		printf("\n\t\tNarrated Jabir bin 'Abdullah:\n\t\tI became sick so Allah's Apostle and Abu Bakr came on foot to pay me a visit.\n\t\tWhen they came, I was unconscious. Allah's Apostle performed ablution and he poured over me the water (of his ablution)\n\t\tand I came to my senses and said, O Allah's Apostle! What shall I do regarding my property?\n\t\tHow shall I distribute it? The Prophet did not reply till the Divine Verses of inheritance were revealed\n");
		printf("\n2.\n");
		printf("\n\t\tNarrated Abu Huraira:\n\t\tAllah's Apostle said, 'Beware of suspicion,\n\t\tfor it is the worst of false tales and don't look for the other's faults and don't spy and don't hate each other,\n\t\tand don't desert (cut your relations with) one another O Allah's slaves, be brothers! (See Hadith No. 90)\n");
		printf("\n3.\n");
		printf("\n\t\tNarrated 'Aisha:\n\t\tFatima and Al 'Abbas came to Abu Bakr, seeking their share from the property of Allah's Apostle and at that time,\n\t\tthey were asking for their land at Fadak and their share from Khaibar.\n\t\tAbu Bakr said to them, I have heard from Allah's Apostle saying, 'Our property cannot be inherited,\n\t\tand whatever we leave is to be spent in charity,\n\t\tthe family of Muhammad may take their provisions from this property. Abu Bakr added, By Allah,\n\t\tI will not leave the procedure I saw Allah's Apostle following during his lifetime concerning this property.\n\t\tTherefore Fatima left Abu Bakr and did not speak to him till she died.\n");
		printf("\n4.\n");
		printf("\n\t\tNarrated 'Aisha:\n\t\tThe Prophet said, Our (Apostles') property should not be inherited, and whatever we leave, is to be spent in charity.\n");
		printf("\n5.\n");
		printf("\n\t\tNarrated Ibn 'Abbas:\n\t\tThe Prophet said, Give the Fara'id (the shares of the inheritance that are prescribed in the Qur'an) to those who are entitled to receive it.\n\t\tThen whatever remains, should be given to the closest male relative of the deceased.\n");	
		
	}
		printf("\n\n\n");
		printf("\t\t\t\t-----------------------------------------------------------------\t\n");
		printf("\t\t\t\t|              Press Enter to continue                    \t|\n");
		printf("\t\t\t\t-----------------------------------------------------------------\t\n");
		printf("\n\n\n");
		fflush(stdin);
		scanf("%c",&c);
		system("cls");
		printf("\n\n\n");
		printf("\t\t\t\t-----------------------------------------------------------------\t\n");
		printf("\t\t\t\t|      Thank you for using our calculator  Assalam Alaikum      |\n");
		printf("\t\t\t\t-----------------------------------------------------------------\t\n");
}
void inheritance_calculator()
{
	char name[20], gender[10], check;
	int age;
	float money, loan, debt, sons, doughters, brothers, sisters;
	printf("Enter the name of Late: ");
	fflush(stdin);
	gets(name);
	printf("Enter the Gender of the Late: ");
	fflush(stdin);
	gets(gender);
	printf("Enter the age of Late: ");
	scanf("%d",&age);
	printf("How much money is left over by late: ");
	scanf("%f",&money);
	printf("How much loan is taken by late (if no loan is taken press 0): ");
	scanf("%f",&loan);
	printf("Any debt on late: (if no debt on late press 0) ");
	scanf("%f",&debt);
	money=money-(loan+debt);
	if(money>0)
	{
		

	printf("Late's perents are alive or not (press 'y' for yes and 'n' for no): ");
	scanf(" %c", &check);
	if(check=='y' || check=='Y')
	{
		double perent=money/6;
		printf("If both father and mother are alive press 'y' else press 'n': ");
		scanf(" %c",&check);
		if(check=='y' || check=='Y')
		{
			money=money-2*perent;
		}
		else
		{
			money=money-perent;
		}
		printf("The part of each (father and monther) is equal to: %.2f\n",perent);
	}
	printf("Was Late marreid or not (press 'y' for yes and 'n' for no): ");
	scanf(" %c", &check);
	if(check=='y' || check=='Y')
	{
		printf("Is the spouse of late is alive or not (press 'y' for yes and 'n' for no): ");
		scanf(" %c", &check);
		if(check=='y' || check=='Y')
		{
			float spouse=money/8;
			money=money-spouse;
			printf("\nThe part of spouse is equal to: %.2f", spouse);
		}
		printf("\nEnter the no. of sons of Late: ");
		scanf("%f",&sons);
		printf("Enter the no. of doughter of late: ");
		scanf("%f",&doughters);
		if(sons==0)
		{
			printf("Enter the no. of brothers of late: ");
			scanf("%f",&brothers);
			printf("Enter the no. of sisters of late: ");
			scanf("%f",&sisters);
			float total=(2*brothers)+sisters+doughters;
			money=money/total;
			printf("\nThe part of each doughter of late is equal to: %.2f", money);
			printf("\nThe part of each sister of late is equal to: %.2f", money);
			printf("\nThe part of each brother of late is equal to: %.2f", 2*money);	
		}
		else
		{
			float total=2*sons+doughters;
			money=money/total;
			printf("\nThe part of each doughter of late is equal to: %.2f", money);
			printf("\nThe part of each son of late is equal to: %.2f", 2*money);	
		}
		
	}
	else if(check=='n' || check=='N')
	{
		
			printf("Enter the no. of brothers of late: ");
			scanf("%f",&brothers);
			printf("Enter the no. of sisters of late: ");
			scanf("%f",&sisters);
			float total=(2*brothers)+sisters;
			money=money/total;
			printf("\nThe part of each brothers of late is equal to: %.2f", 2*money);
			printf("\nThe part of each sister of late is equal to: %.2f", money);	
	}
	
	printf("\n\n\n");
	printf("\t\t\t\t-----------------------------------------------------------------\t\n");
	printf("\t\t\t\t|      Thank you for using our calculator  Assalam Alaikum      |\n");
	printf("\t\t\t\t-----------------------------------------------------------------\t\n");
	}
	else 
	{
	
	printf("\nThe loan and debt taken by Late exceed/equal to the money left over by him so inheritance can not be possible: ");
	printf("\n\n\n");
	printf("\t\t\t\t-----------------------------------------------------------------\t\n");
	printf("\t\t\t\t|      Thank you for using our calculator  Assalam Alaikum      |\n");
	printf("\t\t\t\t-----------------------------------------------------------------\t\n");
	}
}

