#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct varWord{
	char word[128];
	int length;
	bool used;
};

struct varWordGame{
	char word[128];
	int length;
};

varWord words[128];
varWordGame playWord;
int randWord_index;

int usedWord=0,howManyWord=0;

void inputF(){
	FILE *fp = fopen("input.txt","r");
	while(fscanf(fp, "%s %d\n", words[howManyWord].word, &words[howManyWord].length) != EOF)howManyWord++;
	fclose(fp);
}

bool randomWord(){
	if(usedWord==howManyWord){
		return 0;
	}else{
		int unusedWord=howManyWord-usedWord;
		int randWord=rand()%unusedWord+1;
		int count=0;
	//	printf("howmany %d  used %d  unused %d  random %d\n", howManyWord, usedWord, unusedWord, randWord);
		for(int a=0;a<howManyWord;a++){
			if(!words[a].used){
				count++;
				if(randWord==count){
					randWord_index=a;
					strcpy(playWord.word,words[a].word);
					playWord.length=words[a].length;
					words[a].used=1;
					usedWord++;
					return 1;
				}
			}
		}
	}
	return 0;
}

bool lostOne(){
	bool check=randomWord();
	if(check){
		int x=rand() % playWord.length;
		char wordTmp[128];
			strcpy(wordTmp,playWord.word);
			wordTmp[x]='*';
			system("cls");
			
			printf("%s\n", wordTmp);
			printf("\nGuess the missing letter!! (one letter only)\n");
			printf("(You got one chance :*)\n");
			scanf("\n%c", &wordTmp[x]);
			
			if(!strcmp(wordTmp,playWord.word))printf("\nYEY!!\n");
			else printf("\nBOOO!!!\nKamu cupu \n");
			printf("\nThe correct answer is: %s\n\n", playWord);
			
			printf("\nPress anything :) pliss\n");
			getch();
	}
	return check;
}


bool scrambler1(){
	bool check=randomWord();
	if(check){
		
		for(int a=1;a<=playWord.length;a++){
			int x=rand() % playWord.length, y=rand() % playWord.length;
					
	//		printf("%s  %d  %d\n", kata.word, x, y);
			char tmp=playWord.word[x];
			playWord.word[x]=playWord.word[y];
			playWord.word[y]=tmp;
		}
		char guess[128];
		system("cls");
		for(int a=2;a>=0;a--){
			printf("\n%s\n", playWord.word);
			printf("Guess the correct Word!!\n");
			
			scanf("%s", guess);
			system("cls");
			if(!strcmp(guess,words[randWord_index].word)){
				printf("\nYEY\n");
				printf("\nPress anything :) pliss\n");
				getch();
				break;
			}
			else if(a>0){
				printf("Don't worry mate, u still got %d more chance (UwU)\n", a);
			}else{
				printf("Well, I guess you're just suck. Sorry mate (o_o)\n");		
				printf("\nThe correct answer is: %s\n", words[randWord_index].word);
				
				printf("\nPress anything :) pliss\n");
				getch();
			}
		}
		
	}
	return check;	
}

bool scrambler2(){
	bool check=randomWord();
	if(check){
		for(int a=1;a<=playWord.length;a++){
			int pointer=rand()%playWord.length;
			char rev[128],tmp[128];
			memset(rev,0,sizeof(rev));
			memset(tmp,0,sizeof(tmp));
		
			strcpy(rev,playWord.word);
			strrev(rev);
			strncpy(tmp, rev, playWord.length-pointer);
			strncat(tmp, playWord.word, pointer);
			strcpy(playWord.word,tmp);	
		}
		
		char guess[128];
		system("cls");
		for(int a=2;a>=0;a--){
			printf("%s\n\n", playWord.word);
			printf("Guess the correct Word!!\n");
			
			scanf("%s", guess);
			system("cls");
			system("mode con: cols=50 lines=7");
			if(!strcmp(guess,words[randWord_index].word)){
				printf("YEY\n");
				printf("you're good, maybe \\_('v')_/ '\n");
				printf("\nPress anything :) pliss\n");
				getch();
				break;
			}
			else if(a>0){
				printf("Don't worry mate, u still got %d more chance (UwU)\n", a);
			}else{
				printf("Well, I guess you're just suck. Sorry mate (o_o)\n");
				printf("\nThe correct answer is: %s\n", words[randWord_index].word);
				
				printf("\nPress anything :) pliss\n");
				getch();
			}
		}
	}
	return check;
}

void playWordGame(){
	int choice;
	inputF();
	do{
		system("cls");
		system("color 5b");
		system("mode con: cols=35 lines=7");
		
		puts("1. Lost One Letter <(0w0)>");
		puts("2. Scramble (-_-|||)");
		puts("0. Back to Jaya Launcher o_o");
		scanf("\n%d", &choice);
		switch(choice){
			case 1:{
				if(!lostOne()){
					system("mode con: cols=35 lines=7");
					puts("Sorry mate, out of word. Come back later");
					printf("\nPress anything :) pliss\n");
					getch();
					choice=0;
				}
				break;
			}
			case 2:{
				if(!scrambler2()){
					system("mode con: cols=35 lines=7");
					puts("Sorry mate, out of word. Come back later");
					printf("\nPress anything :) pliss\n");
					getch();
					choice=0;
				}
				break;
			}
			case 0:{
				break;
			}
		}
	}while(choice!=0);
}

