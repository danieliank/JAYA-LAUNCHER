//TicTacToe
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int arrXO[4][4];
int sizeXO=3;

void printXO(){
	for(int a=0;a<=sizeXO*4;a++){
		printf("%c",char(219));
	}
	puts("");
	for(int a=1;a<=sizeXO;a++){
		printf("%c",char(219));
		for(int b=1;b<=sizeXO;b++){
			if(arrXO[a][b]==1)printf("\\_/%c",char(219));
			else if(arrXO[a][b]==2) printf("%c%c%c%c", char(201), char(205), char(187), char(219));
			else printf(" %d %c", (a-1)*3+b, char(219));
		}
		printf("\n%c",char(219));
		for(int b=1;b<=sizeXO;b++){
			if(arrXO[a][b]==1)printf("/ \\%c",char(219));
			else if(arrXO[a][b]==2) printf("%c%c%c%c", char(200), char(205), char(188), char(219));
			else printf("   %c",char(219));
		}
		printf("\n");
		for(int a=0;a<=sizeXO*4;a++){
			printf("%c",char(219));
			//if(a==0 || a==sizeXO*3)printf("|");
			//else printf("_");
		}
		puts("");
	
	}
}

int winner(){
	int hasil=0;
	for(int a=1;a<=3;a++){
		if(hasil!=0)break;
		for(int b=1;b<=3;b++){
			if(hasil!=0)break;
			if(arrXO[a][b]!=0){
	//			printf("%d %d ",a,b);
				if     (arrXO[a-1][b]  ==arrXO[a][b] && arrXO[a][b]==arrXO[a+1][b])  hasil=arrXO[a][b];
				else if(arrXO[a][b-1]  ==arrXO[a][b] && arrXO[a][b]==arrXO[a][b+1])  hasil=arrXO[a][b];
				else if(arrXO[a-1][b-1]==arrXO[a][b] && arrXO[a][b]==arrXO[a+1][b+1])hasil=arrXO[a][b];
				else if(arrXO[a+1][b-1]==arrXO[a][b] && arrXO[a][b]==arrXO[a-1][b+1])hasil=arrXO[a][b];
	//			printf("bukan\n");
			}
		}
	}
	return hasil;
}


bool empty(){
	for(int a=1;a<=3;a++){
		for(int b=1;b<=3;b++){
			if(arrXO[a][b]==0)return 1;
		}
	}
	return 0;
}

void solo(){
	for(int a=1;a<=5;a++){
		system("cls");
		printXO();
		puts("Jomblo's Turn");
		int input;
		bool valid=0;
		while(!valid){
			scanf("%d",&input);
			if(input!=0 && arrXO[(input-1)/3+1][(input-1)%3+1]==0){
				arrXO[(input-1)/3+1][(input-1)%3+1]=1;
				valid=1;
			}
			else printf("\ninvalid, dasar jomblo!\n");
		}	
		
		int win=winner();
		if(win==1){
			system("cls");
			printXO();
			printf("Selamat, Jomblo menang\n");
			getch();
			break;
		}else if(win==2){
			system("cls");
			printXO();
			printf("Udah Jomblo, Kalah lagi :'(\n");
			getch();
			break;
		}else if(!empty()) {
			system("cls");
			printXO();
			printf("Damai yah mblo :)\n");
			getch();
			break;
		}
		
		int cntEmpty=0;
		bool fill=0;
		for(int a=1;a<=3;a++){
			if(fill)break;
			for(int b=1;b<=3;b++){
				if(fill)break;
				if(arrXO[a][b]==0)cntEmpty++;
				else{
				//	printf("%d %d\n",a ,b );
					if(arrXO[a-1][b]==arrXO[a][b] || arrXO[a][b]==arrXO[a+1][b]){
					//	printf("First\n");
					//	getch();
						if(arrXO[a-1][b]==0){
							arrXO[a-1][b]=2;
							fill=1;
							break;
						}else if(arrXO[a+1][b]==0){
							arrXO[a+1][b]=2;
							fill=1;
							break;
						}
					}
					else if(arrXO[a][b-1]==arrXO[a][b] || arrXO[a][b]==arrXO[a][b+1]){
					//	printf("Second %d %d\n", a,b);
						if(arrXO[a][b-1]==0){
							printXO();
					//		printf("first\n\n");
							arrXO[a][b-1]=2;
							fill=1;
							break;
						}else if(arrXO[a][b+1]==0){
							printXO();
					//		printf("sec\n\n");
							arrXO[a][b+1]=2;
							fill=1;
							break;
						}
					}
					else if(arrXO[a-1][b-1]==arrXO[a][b] || arrXO[a][b]==arrXO[a+1][b+1]){
						//printf("third\n");
					//	getch();
						if(arrXO[a-1][b-1]==0){
							arrXO[a-1][b-1]=2;
							fill=1;
							break;
						}else if(arrXO[a+1][b+1]==0){
							arrXO[a+1][b+1]=2;
							fill=1;
							break;
						}
					}
					else if(arrXO[a+1][b-1]==arrXO[a][b] || arrXO[a][b]==arrXO[a-1][b+1]){
						//printf("Fourth\n");
					//	getch();
						if(arrXO[a+1][b-1]==0){
							arrXO[a+1][b-1]=2;
							fill=1;
							break;
						}else if(arrXO[a-1][b+1]==0){
							arrXO[a-1][b+1]=2;
							fill=1;
							break;
						}
					}
				} 
			}
		}
		if(!fill){
			int randXO=rand()%cntEmpty+1,cnt=0;
			for(int a=1;a<=3;a++){
				for(int b=1;b<=3;b++){
					if(arrXO[a][b]==0)cnt++;
					if(cnt==randXO){
						arrXO[a][b]=2;
						fill=1;
					}
				}
			}
		}
		
		win=winner();
		if(win==1){
			system("cls");
			printXO();
			printf("Selamat, Jomblo menang\n");
			getch();
			break;
		}else if(win==2){
			system("cls");
			printXO();
			printf("Udah Jomblo, Kalah lagi :'(\n");
			getch();
			break;
		}else if(!empty()) {
			system("cls");
			printXO();
			printf("Damai yah mblo :)\n");
			getch();
			break;
		}
	}
		
}


void duo(){
	for(int a=1;a<=9;a++){
		system("cls");
		printXO();
		if(a%2==1)puts("Your Turn");
		else puts("Mantan's Turn");
		int input=0;
		//masuk jika input==0 input invalid

		while(input==0 || arrXO[(input-1)/3+1][(input-1)%3+1]!=0){
			scanf("%d",&input);
			if(input!=0 && arrXO[(input-1)/3+1][(input-1)%3+1]==0){
				arrXO[(input-1)/3+1][(input-1)%3+1]=(a-1)%2+1;
				input=12;
			}
			else printf("\ninvalid pak!\n");
		}	
		int win=winner();
		if(win==1){
			system("cls");
			printXO();
			printf("Selamat, Mantan anda Kalah\n");
			break;
		}else if(win==2){
			system("cls");
			printXO();
			printf("Selamat kepada Mantan\n");
			break;
		}else if(!empty()) {
			system("cls");
			printXO();
			printf("Damai aja yah :)\n");
		}
	}
	getch();
	
}

void playXO(){
	int choice;
	do{
		memset(arrXO,-1,sizeof(arrXO));
		for(int a=1;a<=3;a++){
			for(int b=1;b<=3;b++){
				arrXO[a][b]=0;
			}
		}
		system("cls");
		printf("Welcome to TicTacToe!!\n\n");
		printf("How to Play\n");
		puts("_____________");
		puts("| 1 | 2 | 3 |");
		puts("|___|___|___|");
		puts("| 4 | 5 | 6 |");
		puts("|___|___|___|");
		puts("| 7 | 8 | 9 |");
		puts("|___|___|___|");
		printf("press the number and press enter\n\n");
		
		printf("1. Jomblo(1 player)\n");
		printf("2. Bersama Mantan(2 player)\n");
		printf("0. Back to Jaya\n");
		scanf("%d",&choice);
		switch(choice){
			case 0:{
				break;
			}
			case 1:{
				solo();
				break;
			}
			case 2:{
				duo();
				break;
			}
			default:{
				printf("ngisinya yang bener dong :(\n");
				getch();
				break;
			}
		}	
	}while(choice!=0);
}

int main(){
	playXO();
	
}
