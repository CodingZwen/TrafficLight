/*

Traffic Example
2 Traffic lights standing on one street across from each other


*/



//also works with this as parameter but idk how to animate without array
//				 rog rog -> red yellow green -> second traffic light
#define PHASE1 0b100100
#define PHASE2 0b110100
#define PHASE3 0b001100
#define PHASE4 0b010100
#define PHASE5 0b100100
#define PHASE6 0b100110
#define PHASE7 0b100001
#define PHASE8 0b100 010
#define PHASE9 0b100 100
#define PHASE10 0b100 100
#define MAXPHASES 10




#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

enum trafficlightstatus {RED,YELLOW,GREEN,RED2,YELLOW2,GREEN2};
char trafficLights[6][MAXPHASES] = { 0 };
unsigned char phasearray[MAXPHASES] = { 0b100100,0b110100,0b001100,0b010100,0b100100,0b100110,0b100001,0b100010,0b100100,0b100100 };

const char highflank = '-';
const char lowflank = '_';

void setState(unsigned int currentphase,unsigned  int binaryphase)
{
	if(currentphase >0)currentphase -=1;


	unsigned int phase = binaryphase;
	unsigned int shiftbits = 0b100000;


	for (int i = 0; i < MAXPHASES; i++) {
		
		unsigned int currentbit = phase & shiftbits;

		trafficLights[i][currentphase] = currentbit ? highflank : lowflank;
		shiftbits >>= 1;

	
	}


}




void printDiagram(char field[][MAXPHASES])
{
	for (int i = 0; i < 6; i++) {

		switch (i) {
		case trafficlightstatus::RED: printf("R: "); break;
		case trafficlightstatus::YELLOW: printf("Y: "); break;
		case trafficlightstatus::GREEN: printf("G: "); break;
		case trafficlightstatus::RED2: printf("R: "); break;
		case trafficlightstatus::YELLOW2: printf("Y: "); break;
		case trafficlightstatus::GREEN2: printf("G: "); break;
		default: break;
		}

		for (int j = 0; j< MAXPHASES; j++) {


			

			printf("%c",field[i][j]);
		}
		printf("\n");
	}

}



void initfield(char field[][MAXPHASES])
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < MAXPHASES; j++) {
			field[i][j] = '_';
		}
		
	}
}

int main()
{
	
	initfield(trafficLights);

	for (int i = 1; i <= MAXPHASES; i++) {

		setState(i, phasearray[i-1]);
	}

	
	int count = 0;

	while (1)
	{
		for (int i = 1; i <= MAXPHASES; i++) {

			setState(i, phasearray[count % MAXPHASES - 1]);
			count++;
		}
		count++;

		printDiagram(trafficLights);
		Sleep(500);
		system("cls") ;
	}
	system("pause");

}