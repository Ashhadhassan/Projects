#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
int Verify_Roll (char Str[10]) {
	char Temp[10];
	strupr(Str);
	strcpy(Temp,Str);
	if (strlen(Temp) < 8 || strlen(Temp) > 8) {
		return 0;
	} else {
		if  (Temp[0] <= '9' && Temp[0] >= '0') {
			if (Temp[1] <= '9' && Temp[1] >= '0') {
				if (Temp[2] == 'K') {
					if (Temp[3] == '-') {
						for (int I = 4; I < strlen(Temp); I++) {
							if (Temp[I] > '9' || Temp[I] < '0') {
								return 0;
							}

						}
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int Verify_Name(char Str[20]) {
	char Temp[20];
	strcpy(Temp,Str);
	strupr(Temp);
	for (int i = 0; i < strlen(Temp); i++) {
		if (Temp[i] < 'A' || Temp[i] > 'Z') {
			return 0;
		}
	}
	return 1;
}

void PrintChallan(char Route[]) {
	fflush(stdin);
	system("cls");
	char First_Name[20];
	char Last_Name[20];
	char rollNum[10];
	char fullname[40];
	do {
		printf("Enter First Name: ");
		gets(First_Name);
		if (Verify_Name(First_Name) == 0) {
			printf("Enter Valid First Name for example (Ahmed)\n");
		}
	} while (Verify_Name(First_Name) == 0);
	do {
		printf("Enter Last Name: ");
		gets(Last_Name);
		if (Verify_Name(Last_Name) == 0) {
			printf("Enter Valid Last Name for example (Siddique)\n");
		}
	} while (Verify_Name(Last_Name) == 0);
	strcpy(fullname,First_Name);
	strcat(fullname," ");
	strcat(fullname,Last_Name);
	do {
		printf("Enter roll number (23K-XXXX): ");
		gets(rollNum);
		if (Verify_Roll(rollNum) == 0) {
			printf("Follow The Format Provided\n");
		}
	} while (Verify_Roll(rollNum) == 0);
	printf("Processing...\n");
	sleep(1);
	FILE *fptr;
	fptr = fopen("Voucher.txt","w");
	fputs("FAST Transport Services\n\n",fptr);
	fputs("A Cooperation of Nadeem and Jadoon Enterprises\n\n",fptr);
	fputs("Student's Name: ",fptr);
	fputs(fullname,fptr);
	fputs("\n",fptr);
	fputs("Student's Roll Number: ",fptr);
	fputs(rollNum,fptr);
	fputs("\n\n\n",fptr);
	fputs("Route # ",fptr);
	fputs(Route,fptr);
	fputs("\n\n\nDue Date: 5-Dec-23\nPayment Before Due Date: 31000\nPayment After Due Date: 32000\n",fptr);
	fclose(fptr);
	printf("Process Completed Successfully");
}

void Print_Route(char Route[][2][40],int N) {
	for (int I = 0; I<N; I++) {
		int Count = 0;
		for (int J = 0; J<35; J++) {
			Count++;
			if (Count <= strlen(Route[I][0])) 
			{
				printf("%c",Route[I][0][J]);
			} 
			else 
			{
				printf(" ");
			}
		}
		printf("|%s AM\n",Route[I][1]);
	}
}

int User_Route(char Route[5]) {
	char route_2[10][2][40] = {{"KHATM.E.NABVOT CHOWK","6:25"},{"KANEEZ FATIMA","6:30"},{"MADRAS CHOKE","6:32"},{"G3 STOP","6:37"},{"SUCHAL GOATH","6:45"},{"CHAPAL","6:50"},{"MEMON HP","6:55"},{"GULL ESTATE","7:00"},{"SAFOORA","7:02"},{"FAST NU","7:45"}};
	char route_3[7][2][40] = {{"RABIA CITY","6:30"},{"PAHALWAN GOATH","6:35"},{"SINDH BALOCH","6:40"},{"BAITHAK MARRIAGE LAWN","6:43"},{"NAWAZSHARIF SCHEME","6:47"},{"BISMILLAH TOWER(PIA)","6:48"},{"FAST","7:45"}};
	char route_3B[5][2][40] = {{"KAMRAN CHOWRANGI","6:40"},{"SARDAR CNG","6:45"},{"MUNAWAR CHOWRANGI","6:46"},{"JOHAR MORE","6:50"},{"FAST NU","7:45"}};
	char route_4[7][2][40] = {{"MAYMAR GATE","6:30"},{"JAMALI PULL","6:45"},{"AL ASIF","6:48"},{"ABBAS TOWN","6:50"},{"PARADISE BAKERY","6:52"},{"MASKAN","6:55"},{"FAST NU","7:45"}};
	char route_4B[5][2][40] = {{"MASKAN","6:55"},{"DISCO BAKERY","6:58"},{"RIMJIM HALL","7:00"},{"FAST NU","7:45"}};
	char route_5[9][2][40] = {{"4K STOP","6:30"},{"2 MINUTE","6:32"},{"POWER HOUSE","6:37"},{"SALEEM CENTER","6:39"},{"UP-MORE","6:42"},{"NAGAN","6:45"},{"SHADMAN 2-1","6:48"},{"SAKHI HASSAN","6:50"},{"FAST NU","7:45"}};
	char route_5B[7][2][40] = {{"DOLMIN MALL","6:45"},{"5 STAR","6:46"},{"FAROOQ.E.AZAM","6:47"},{"LUCKY ONE","7:02"},{"MOTI MAHAL","7:04"},{"GULSHAN DHAKA","7:05"},{"FAST NU","7:45"}};
	char route_6[11][2][40] = {{"AJMAIR NAGRI","6:30"},{"BOMBAY BAKERY","6:31"},{"OXFORD SCHOOL","6:32"},{"BARA DARI","6:33"},{"BABUL ISLAM","6:35"},{"DISCO MORE","6:37"},{"QALANDRIA CHOWKE","6:40"},{"K.I.H.D HOSPITAL","6:50"},{"FAZAL MILL","6:55"},{"CENTRUM","6:56"},{"FAST NU","7:45"}};
	char route_6B[13][2][40] = {{"ANDA MORE","6:40"},{"HAIDER FOOD","6:41"},{"DC OFFICE","6:45"},{"PEOPLES CHOWRANGI","6:47"},{"KAIF.E.PIYALA","6:48"},{"GULBERG","6:49"},{"RAHEEM HOSPITAL","6:50"},{"WATER PUMP MORE","6:51"},{"CALTEX PETROLIUM","6:52"},{"ANCHOLI","6:53"},{"SUHRAB GOTH","6:54"},{"FAZAL MILL","6:55"},{"FAST NU","7:45"}};
	char route_7[6][2][40] = {{"DONISAL","6:40"},{"LANDIKOTAL","6:45"},{"TAHIR VILLAS","6:50"},{"SHADAB MASJID","6:52"},{"GULBERG THANA","6:53"},{"FAST NU","7:45"}};
	char route_8[9][2][40] = {{"MASJID USMAN GHANI","6:35"},{"MOCHI GALI","6:37"},{"SHIPOWNER","6:40"},{"LADY BIRD","6:45"},{"MATEEN FOOD","6:47"},{"DENTAL COLLEGE","6:50"},{"NIAZ MANZIL","6:51"},{"GREEN HOUSE","6:52"},{"FAST NU","7:45"}};
	char route_9[9][2][40] = {{"ANDA MORE","6:45"},{"RED HOUSE","6:47"},{"AL HABIB","6:49"},{"CAFE 2DAYS","6:50"},{"NAMAK BANK","6:55"},{"SHAFEEQ MORE","6:57"},{"AL NOOR","7:00"},{"EDHI CENTER","7:02"},{"FAST NU","7:45"}};
	char route_17[7][2][40] = {{"KARIMABAD","6:35"},{"AYESHA MANZIL","6:37"},{"BHAIJAAN CHOWKE","6:39"},{"GULSHAN E SHAMEEM","6:43"},{"13 D GULSHAN","6:48"},{"RAB MEDICAL","6:50"},{"FAST NU","7:45"}};
	char route_18[8][2][40] = {{"7 NO NAZIMABAD","6:25"},{"ABBASI HP","6:27"},{"KHILAFAT CHOWKE","6:30"},{"BOARD OFFICE","6:34"},{"MOUSA COLONY","6:40"},{"MEENA BAZAR","6:42"},{"USMAN MEMORIAL","6:45"},{"FAST NU","7:45"}};
	char route_20[8][2][40] = {{"BIN HASHIM","6:25"},{"COMANDER CNG","6:30"},{"KAZIMABAD","6:45"},{"TANK CHOWKE","6:48"},{"MODEL MORE","6:50"},{"MODEL COLONY","6:55"},{"BARAF KHANA TO KALA BOAT","7:00"},{"FAST NU","7:45"}};
	char route_22[4][2][40] = {{"AYESHA MANZIL","6:40"},{"BHAIJAAN CHOWKE","6:42"},{"RAB MEDICAL","6:47"},{"FAST NU","7:45"}};
	char route_23[6][2][40] = {{"ORANGI TOWN # 5","6:30"},{"ABDULLAH COLLEGE","6:36"},{"ASGHAR ALI SHAH","6:36"},{"KATTI PAHARI","6:38"},{"KDACHOWRANGI","6:45"},{"FAST NU","7:45"}};
	char route_23B[7][2][40]= {{"HAYDERI SUPPER MART","6:35"},{"ZIAUDDIN","6:40"},{"LANDIKOTAL","6:55"},{"TAHIR VILLAS","6:57"},{"AYESHA MANZIL STORE","6:58"},{"NASEER ABAD","7:00"},{"FAST NU","7:45"}};
	char route_24[10][2][40] = {{"LALA ZAR NIPA","6:35"},{"SAFARI PARK","6:40"},{"SAMAMA","6:43"},{"CONTINENTAL","6:45"},{"KESC","6:46"},{"JOHAR CHOWRANGI","6:47"},{"PERFUME CHOWKE","6:50"},{"HILL TOP","6:52"},{"JOHAR MORE","6:55"},{"FAST NU","7:45"}};
	char route_24B[6][2][40]= {{"PCSIR","6:35"},{"MADRAS CHOWKE","6:37"},{"DARUL SEHAT","6:45"},{"RADO","6:46"},{"JDC","6:47"},{"FAST NU","7:45"}};
	char route_25[7][2][40] = {{"DOW UNIVERSITY","6:40"},{"RIZVIA","6:45"},{"AL-HIRA","6:55"},{"SAIMA FLAT","6:56"},{"SADI TOWN","7:00"},{"FALCON","7:05"},{"FAST NU","7:45"}};
	char route_25B[13][2][40] = {{"FARIYA CHOWKE","6:30"},{"MALIK SOCIETY","6:35"},{"KDA","6:40"},{"QUITA TOWN","6:45"},{"SUMAIRA FLAT","6:47"},{"ALAZHAR","6:50"},{"CAPITAL SOCIETY","6:50"},{"TULIP TOWER","6:55"},{"GULSHAN HUMAIR","7:00"},{"6NO CHECK POST","7:01"},{"6 NO CHECK POST","7:02"},{"SECURITY PRINTING","7:15"},{"FAST NU","7:45"}};
	char route_26[8][2][40] = {{"QALANDARABAD","6:40"},{"SAADABAD","6:42"},{"PSO PUMP NEAR KU","6:50"},{"MOSAMIYAT","6:52"},{"JOHAR COMPLEX","6:47"},{"COMANDER CNG","6:55"},{"G-10 GULL HOUSE","7:00"},{"FAST NU","7:45"}};
	char route_11[7][2][40] = {{"Soldier Bazaar", "6:30"},	{"GURU MANDIR", "6:35"},	{"ISLAMIYA COLLEGE", "6:40"},	{"STADIUM ROAD", "6:45"},	{"DALMIA", "6:55"},	{"NATA KHAN", "7:05"},	{"FAST NU", "7:45"}};
	char route_12[9][2][40] = {{"JAIL ROAD", "6:35"},{"JAMSHED ROAD", "6:40"},{"KHUDABAD COLONY", "6:45"},{"KASHMIR ROAD", "6:47"},{"SIR SYED ROAD", "6:50"},{"KHALID BIN WALEED ROAD", "6:55"},{"TARIQ ROAD", "7:00"},{"TIPU SULTAN ROAD", "7:05"},{"FAST NU", "7:45"}};
	char route_13[10][2][40] = {{"RACE COURSE", "6:30"},{"CANT STATION", "6:35"},{"ASKARI I ", "6:40"},{"KALA PULL", "6:45"},{"CSD", "6:47"},{"FTC", "6:50"},{"DRIG ROAD", "7:00"},{"COLONY GATE", "7:12"},{"STAR GATE", "7:14"},{"FAST NU", "7:45"}};
	char route_14[7][2][40] = {{"SHARFABAD", "6:45"},{"BAHADRABAD", "6:48"},{"DHORAJI", "6:55"},{"M ALI SOCIETY", "7:00"},{"WIRELESS GATE", "7:10"},{"MALIR HALT", "7:12"},{"FAST NU", "7:45"}};
	char route_15[8][2][40] = {{"FORUN SSHOPPING MALL", "6:35"},{"ZAMZAMA", "6:40"},{"GHIZRI", "6:50"},{"PHASE-IV", "7:00"},{"PHASE II", "7:05"},{"PHASE-II KFC", "7:07"},{"AKHTAR COLONY", "7:08"},{"FAST NU", "7:45"}};
	char route_16[8][2][40] = {{"BILAWAL HOUSE", "6:30"},{"HYPER STAR", "6:35"},{"KH MUJAHID", "6:40"},{"SABA AVENUE", "6:45"},{"KH BUKHARI", "6:50"},{"kH ITTEHAD", "6:55"},{"KFC PHASE-II", "7:05"},{"FAST NU", "7:45"}};
	char route_19[6][2][40] = {{"HASSAN SQUARE", "6:50"},{"MUMTAZ MALL", "6:52"},{"BAIT-UL-MUKKARRAM", "6:55"},{"URDU SCIENCE COLLEGE", "6:57"},{"AZIZ BHATTI PARK", "7:00"},{"FAST NU", "7:45"}};
	char route_21[8][2][40] = {{"TOWER", "6:30"},{"JANG PRESS", "6:35"},{"SINDH SECRETARIAT", "6:40"},{"SADDAR", "6:45"},{"LUCKY STAR", "6:50"},{"FTC", "6:55"},{"SHAHRA-E-FAISAL NURSERY", "7:00"},{"FAST NU", "7:45"}};
	char route_30[8][2][40] = {{"JAHANGIRABAD", "6:35"},{"GOLIMAR CHOWRANGI", "6:38"},{"NAZ PETROL PUMP", "6:40"},{"LIAQUATABAD", "6:43"},{"GHAREEBABAD", "6:45"},{"BALOCH HOTEL", "6:48"},{"KARSAZ", "6:55"},{"FAST NU", "7:45"}};
	char route_31[5][2][40] = {{"KPT BRIDGE", "6:52"},{"IQRA UNIVERSITY", "6:55"},{"MANZOOR COLONY", "7:00"},{"PAF CHAPTER", "7:05"},{"FAST-NU", "7:45"}};
	char route_32[10][2][40] = {{"BOAT BASIN","06:30"},{"BILAWAL CHOWRANGI","06:35"},{"26 STREET","06:40"},{"BADAR COMMERCIAL","06:45"},{"KHAYABAN-E-SEHER","06:50"},{"NEXER COLLEGE","06:52"},{"KHAYABAN-E-SHAHBAZ","06:55"},{"KFC PHASE II","07:00"},{"SINGER CHOWRANGI","07:20"},{"FAST-NU","07:45"}};
	char route_33[8][2][40] = {{"NAZ PETROL PUMP","06:35"},{"ESA NAGRI","06:40"},{"MASHRIQ CENTER","06:42"},{"STADIUM","06:45"},{"DALMIA","06:55"},{"MILLENNIUM","06:57"},{"DRIG ROAD","07:00"},{"FAST-NU","07:45"}};
	char route_34[10][2][40] = {{"DHA PHASE II KFC","06:45"},{"QAYYUMABAD","06:50"},{"KORANGI CROSSING","06:55"},{"NASIR JUMP","07:00"},{"KORANGI NO 2","07:05"},{"KORANGI NO 5","07:10"},{"LANDHI NO 4","07:15"},{"LANDHI 89","07:20"},{"DAWOOD CHOWRANGI","06:25"},{"FAST-NU","07:45"},};
	char route_35[8][2][40] = {{"AGHAZ MARKET","06:35"},{"TEEN TALWAR","06:40"},{"RACE COURSE","06:45"},{"BACHA PARTY","06:50"},{"PUNJAB CHOWRANGI","06:55"},{"DHA PAHSE 1 NADRA OFFICE","07:00"},{"AKHTAR COLONY","07:05"},{"FAST-NU","07:45"},};
	char route_36[9][2][40] = {{"POLICE HEADQUARTER GARDEN","06:35"},{"UNCLE SARIYA","06:37"},{"MOBILE MARKET","06:40"},{"NAZ PLAZA","06:43"},{"NUMAISH","06:45"},{"ISLAMIA COLLEGE","06:50"},{"NEW TOWN CHANDNI CHOWK","06:55"},{"DALMIA","07:00"},{"FAST-NU","07:45"}};
	char route_37[14][2][40] = {{"RAM SAWAMI","06:35"},{"GARDEN ZOO","06:38"},{"ALI BHAI","06:40"},{"GARDEN JAMAT KHANA","06:45"},{"FATIMIA BLOOD BANK","06:47"},{"KHURASAN","06:50"},{"NUMAISH","06:52"},{"KHUDADAD COLONY","06:57"},{"NOORANI KABAB","06:59"},{"SHAHRA-E-QUIDEEN","07:00"},{"NURSREY","07:05"},{"NHS 4","07:10"},{"NATA KHAN","07:15"},{"FAST-NU","07:45"}};
	char route_39[8][2][40] = {{"SHAMA SHOPPING CENTER","06:50"},{"SHAH FAISAL NO 2","06:55"},{"SHAH FAISAL NO 2","07:00"},{"KALMA CHOWK","07:05"},{"AZEEM PORA","07:10"},{"MILLAT TOWN","07:15"},{"MALIR 15","07:20"},{"FAST-NU","07:45"}};
	char route_40[5][2][40] = {{"MATKA STOP","07:00"},{"ALADIN PARK","07:01"},{"LAL FLAT","07:03"},{"LASANI RESTAURANT","07:05"},{"FAST-NU","07:45"}};
	char route_41[4][2][40] = {{"ASKARI 4","07:00"},{"COD","07:02"},{"DRIG ROAD","07:05"},{"FAST-NU","07:45"}};
	if (strcmp(Route,"2") == 0) {
		Print_Route(route_2,10);

	} else if(strcmp(Route,"3") == 0) {
		Print_Route(route_3,7);

	} else if(strcmp(Route,"3B") == 0) {
		Print_Route(route_3B,5);

	} else if(strcmp(Route,"4") == 0) {
		Print_Route(route_4,7);

	} else if(strcmp(Route,"4B") == 0) {
		Print_Route(route_4B,5);

	} else if(strcmp(Route,"5") == 0) {
		Print_Route(route_5,9);

	} else if(strcmp(Route,"5B") == 0) {
		Print_Route(route_5B,7);

	} else if(strcmp(Route,"6") == 0) {
		Print_Route(route_6,11);

	} else if(strcmp(Route,"6B") == 0) {
		Print_Route(route_6B,13);

	} else if(strcmp(Route,"7") == 0) {
		Print_Route(route_7,6);

	} else if(strcmp(Route,"8") == 0) {
		Print_Route(route_8,9);

	} else if(strcmp(Route,"9") == 0) {
		Print_Route(route_9,9);

	} else if(strcmp(Route,"17") == 0) {
		Print_Route(route_17,7);

	} else if(strcmp(Route,"18") == 0) {
		Print_Route(route_18,8);

	} else if(strcmp(Route,"20") == 0) {
		Print_Route(route_20,8);

	} else if(strcmp(Route,"22") == 0) {
		Print_Route(route_22,4);

	} else if(strcmp(Route,"23") == 0) {
		Print_Route(route_23,6);

	} else if(strcmp(Route,"23B") == 0) {
		Print_Route(route_23B,7);

	} else if(strcmp(Route,"24") == 0) {
		Print_Route(route_24,10);

	} else if(strcmp(Route,"24B") == 0) {
		Print_Route(route_24B,6);

	} else if(strcmp(Route,"25") == 0) {
		Print_Route(route_25,7);

	} else if(strcmp(Route,"25B") == 0) {
		Print_Route(route_25B,13);

	} else if(strcmp(Route,"26") == 0) {
		Print_Route(route_26,8);

	} else if(strcmp(Route,"11") == 0) {
		Print_Route(route_11,7);

	} else if(strcmp(Route,"12") == 0) {
		Print_Route(route_12,9);

	} else if(strcmp(Route,"13") == 0) {
		Print_Route(route_13,10);

	} else if(strcmp(Route,"14") == 0) {
		Print_Route(route_14,7);

	} else if(strcmp(Route,"15") == 0) {
		Print_Route(route_15,8);

	} else if(strcmp(Route,"16") == 0) {
		Print_Route(route_16,8);

	} else if(strcmp(Route,"19") == 0) {
		Print_Route(route_19,6);

	} else if(strcmp(Route,"21") == 0) {
		Print_Route(route_21,8);

	} else if(strcmp(Route,"30") == 0) {
		Print_Route(route_30,8);

	} else if(strcmp(Route,"31") == 0) {
		Print_Route(route_31,5);

	} else if(strcmp(Route,"32") == 0) {
		Print_Route(route_32,10);

	} else if(strcmp(Route,"33") == 0) {
		Print_Route(route_33,8);

	} else if(strcmp(Route,"34") == 0) {
		Print_Route(route_34,10);

	} else if(strcmp(Route,"35") == 0) {
		Print_Route(route_35,8);

	} else if(strcmp(Route,"36") == 0) {
		Print_Route(route_36,9);

	} else if(strcmp(Route,"37") == 0) {
		Print_Route(route_37,14);

	} else if(strcmp(Route,"39") == 0) {
		Print_Route(route_39,8);

	} else if(strcmp(Route,"40") == 0) {
		Print_Route(route_40,5);

	} else if(strcmp(Route,"41") == 0) {
		Print_Route(route_41,4);

	} else {
		printf("Route Not Available/Invalid Route\n");
		return 0;
	}
	return 1;
}

int Comfirmation_B (int Range,char Data[Range][10]) {
	char Decision[30];
	if (Range <= 1) {
		int Check;
		do {
			Check = 0;
			printf("Is This Route Yours? Yes or No\n");
			gets(Decision);
			strupr(Decision);
			if (strcmp(Decision,"YES") == 0) {
				Check = 1;
				char Temp[10];
				strcpy(Temp,Data[0]);
				PrintChallan(Temp);
				return 1;
			} else if (strcmp(Decision,"NO") == 0) {
				return 0;
			}
		} while(Check == 0);
	} else {
		int Check;

		do {
			Check = 0;
			printf("Is Any Route Yours? Yes or No\n");
			gets(Decision);
			strupr(Decision);
			if (strcmp(Decision,"YES") == 0) {
				Check = 1;
				int Choice;
				do {
					printf("Kindly Select Your Route From The Earlier List For e.g (1,2,3)\n");
					scanf("%d",&Choice);
					fflush(stdin);
				} while(Choice > Range || Choice < 1);
				char Temp[10];
				strcpy(Temp,Data[Choice - 1]);
				PrintChallan(Temp);
				return 1;
			} else if (strcmp(Decision,"NO") == 0) {
				return 0;
			}
		} while(Check == 0);
	}
}

int Comfirmation(int Size,char Routes[Size][10]) {
	printf("These Routes Are Found\n");
	for (int I = 1; I <= Size; I++) {
		printf("%d) %s\n",I,Routes[I - 1]);
	}
	int Ok = 0;
	char Decision[10];
	do {
		printf("Do U Want To See The Complete Routes? Yes or No\n");
		gets(Decision);
		strupr(Decision);
		if (strcmp(Decision,"YES") == 0) {
			Ok = 1;
			char Temp[5];
			for (int I = 0; I<Size; I++) {
				strcpy(Temp,Routes[I]);
				printf("Route # %s\n",Routes[I]);
				User_Route(Temp);
				printf("\n");
			}
			return Comfirmation_B(Size,Routes);
		} else if (strcmp(Decision,"NO") == 0) {
			Ok = 1;
			return Comfirmation_B(Size,Routes);
		}
	} while(Ok == 0);
}

int File(char Loc[40]) {
	int Routes = 0;
	char **List = NULL;
	char Route[5],Length[5];
	FILE *Document;
	Document = fopen("Document.txt","r");
	while (fgets(Route,5,Document) != NULL) {
		Route[strlen(Route) - 1] = '\0';
		fgets(Length,5,Document);
		int Limit = atoi(Length);
		char Location[40];
		for (int I = 0; I < Limit; I++) {
			fgets(Location,40,Document);
			Location[strlen(Location) - 1] = '\0';
			strupr(Location);
			if (strcmp(Location,Loc) == 0) {
				Routes++;
				List = (char**) realloc(List,Routes*sizeof(char*));
				List[Routes - 1] = (char*) malloc(10*sizeof(char));
				strcpy(List[Routes - 1],Route);
			}
		}
	}
	fclose(Document);
	if (Routes == 0) {
		return 0;
	} else {
		char New_List[Routes][10];
		for (int i = 0; i<Routes; i++) {
			strcpy(New_List[i],List[i]);
		}
		for (int i = 0; i < Routes; i++) {
			free(List[i]);
		}
		free(List);
		return Comfirmation(Routes,New_List);
	}
}

void Final(void) {
	printf("Did You Find Your Route?\n");
	char Choice[10];
	int Check = 0;
	do {
		gets(Choice);
		strupr(Choice);
		if (strcmp(Choice,"YES") == 0) {
			Check = 1;
			int Ok;
			do {
				printf("Enter Route Name\n");
				gets(Choice);
				strupr(Choice);
				Ok = User_Route(Choice);
				sleep(1.2);
				if (Ok == 1) {
					PrintChallan(Choice);
				} else {
					printf("Enter Correct Route\n");
				}
			} while (Ok == 0);
		} else if (strcmp(Choice,"NO") == 0) {
			system("cls");
			Check = 1;
			printf("Then There Must Be No Route For Your Location Kindly Commute On Your Own\nGood Luck\n");
		} else {
			printf("Invalid Choice\n");
		}
	} while (Check == 0);
}

void PrintLoc(void) {
	FILE *Document;
	Document = fopen("Document.txt","r");
	char Route[5],Length[4],Location[40];
	while (fgets(Route,5,Document) != NULL) {
		int Limit;
		printf("Route # %s",Route);
		fgets(Length,4,Document);
		Limit = atoi(Length);
		for (int i = 0; i<Limit; i++) {
			fgets(Location,40,Document);
			strupr(Location);
			printf("%s",Location);
		}
		printf("\n");
		sleep(1);
	}
	fclose(Document);
	Final();
}

int main() {
	do {
		system("cls");
		printf("Welcome To Track Konnect\n");
		printf("Enter 1 To Continue\n");
		fflush(stdin);
		int Choice;
		scanf("%d",&Choice);
		if (Choice == 1) {
			fflush(stdin);
			char choice[10];
			int Done = 0;
			do {
				system("cls");
				printf("Do you know your routes?\nEnter Yes or no: ");
				gets(choice);
				strupr(choice);
				if (strcmp(choice,"YES") == 0) {
					Done = 1;
					int Check,Count = 0;
					do {
						system("cls");
						printf("Enter Route Number = ");
						char Number[10];
						gets(Number);
						strupr(Number);
						Check = User_Route(Number);
						if (Check == 1) {
							int Ok = 0;
							do {
								printf("Is This Your Route\n");
								char Decide[10];
								gets(Decide);
								strupr(Decide);
								if (strcmp(Decide,"YES") == 0) {
									PrintChallan(Number);
									Ok = 1;
								} else if ((strcmp(Decide,"NO") == 0)) {
									Ok = 1;
									Check = 0;
								} else {
									printf("Invalid Choice\n");
									sleep(1);
								}
								
							} while (Ok == 0);
						}
						Count++;
						sleep(1.1);
						if (Count == 3 && Check == 0) {
							Count = 0;
							int Ok = 0;
							do {
								system("cls");
								char Decide[10];
								printf("Do You Really Remember Your Route? \nEnter Yes or No\n");
								gets(Decide);
								strupr(Decide);
								if (strcmp(Decide,"YES") == 0) {
									system("cls");
									printf("Ok Continue\n");
									Ok = 1;
								} else if (strcmp(Decide,"NO") == 0) {
									system("cls");
									printf("Going Back To Main Menu...\n");
									sleep(1.5);
									Check = 1;
									Done = 0;
									Ok = 1;
								} else {
									printf("Invalid Choice\n");
								}
							} while (Ok == 0);
						}
					} while (Check == 0);

				} else if (strcmp(choice,"NO") == 0) {
					int Check,Count = 0;
					Done = 1;
					char Location[40];
					do {
						system("cls");
						printf("Kindly Enter Location/Known Landmark \n");
						gets(Location);
						strupr(Location);
						Check = File(Location);
						Count++;
						if (Check == 0 && Count < 3) {
							printf("Maybe Try Another Route\n");
							sleep(1.5);
						}
						if (Count == 3 && Check == 0) {
							Count = 0;
							char Choice[10];
							int Comfirm = 0;
							do {
								system("cls");
								printf("Seems You Are Having A Issue Do You Want To See The List Of Routes With Locations?\nEnter Yes Or No\n");
								gets(Choice);
								strupr(Choice);
								if (strcmp(Choice,"YES") == 0) {
									Comfirm = 1;
									Check = 1;
									PrintLoc();
								} else if (strcmp(Choice,"NO") == 0) {
									system("cls");
									printf("Ok Continue\n");
									Comfirm = 1;
									sleep(1);
								}
							} while (Comfirm == 0);
						}
					} while (Check == 0);
				} else {
					system("cls");
					printf("Invalid Choice\n");
					sleep(2);
				}
			} while (Done == 0);
			sleep(2);
		}
	} while(1);
}
