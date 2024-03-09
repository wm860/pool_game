#include <Windows.H>
#include <stdlib.h>
#include <stdio.h>
#include "winbgi2.h"
#include <time.h>
#include <math.h>

void init(double *x, double *y, int n)
{
	for (int i = 0; i < (n+1); i++)
	{
		x[i] = (double)(rand() % 400 + 390);
		y[i] = (double)(rand() % 800 + 55);
	}
	/*for (int i = 0; i < (n + 1); i++)
	{
		for (int j = i+1; j < (n + 1); j++)
		{
			if((fmod(x[i],x[j])<25.0) && (fmod(y[i], y[j])<25.0))
			goto start;
		}
	}*/
}

void display(double *x, double *y, int n)
{
	line(360, 20, 360, 880);
	line(360, 880, 840, 880);
	line(840, 880, 840, 20);
	line(840, 20, 360, 20);
	setcolor(GREEN);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++)	//zielone bile sa jednego zawodnika
		{
			circle(x[i], y[i], j);
		}
		if (i > (n/2-1))				//niebieskie bile sa drugiego zawodnika
		{
			setcolor(BLUE);
		}
		if (i == (n - 2))		//czerwona bila konczy gre
		{
			setcolor(RED);
		}
	}
	setcolor(WHITE);
	for (int i = 0; i < 10; i++)//pokazuje na ekranie bile biala
	{
		circle(x[n], y[n], i);
	}
}
void podzialka()
{
	setcolor(LIGHTBLUE);
	int k = 30;
	while(k<880)
	{
		line(340, k, 360, k);
		k += 20;
	}
	k = 370;
	while (k < 840)
	{ 
		line(k, 880, k, 900);
		k += 30;
	}
	outtextxy(360, 900, "10");
	outtextxy(390, 900, "40");
	outtextxy(420, 900, "70");
	outtextxy(450, 900, "100");
	outtextxy(480, 900, "130");
	outtextxy(510, 900, "160");
	outtextxy(540, 900, "190");
	outtextxy(570, 900, "220");
	outtextxy(600, 900, "250");
	outtextxy(630, 900, "280");
	outtextxy(660, 900, "310");
	outtextxy(690, 900, "340");
	outtextxy(720, 900, "370");
	outtextxy(750, 900, "400");
	outtextxy(780, 900, "430");
	outtextxy(810, 900, "460");
	
	outtextxy(320, 30, "10");
	outtextxy(320, 50, "30");
	outtextxy(320, 70, "50");
	outtextxy(320, 90, "70");
	outtextxy(320, 110, "90");
	outtextxy(320, 130, "110");
	outtextxy(320, 150, "130");
	outtextxy(320, 170, "150");
	outtextxy(320, 190, "170");
	outtextxy(320, 210, "190");
	outtextxy(320, 230, "210");
	outtextxy(320, 250, "230");
	outtextxy(320, 270, "250");
	outtextxy(320, 290, "270");
	outtextxy(320, 310, "290");
	outtextxy(320, 330, "310");
	outtextxy(320, 350, "330");
	outtextxy(320, 370, "350");
	outtextxy(320, 390, "370");
	outtextxy(320, 410, "390");
	outtextxy(320, 430, "410");
	outtextxy(320, 450, "430");
	outtextxy(320, 470, "450");
	outtextxy(320, 490, "470");
	outtextxy(320, 510, "490");
	outtextxy(320, 530, "510");
	outtextxy(320, 550, "530");
	outtextxy(320, 570, "550");
	outtextxy(320, 590, "570");
	outtextxy(320, 610, "590");
	outtextxy(320, 630, "610");
	outtextxy(320, 650, "630");
	outtextxy(320, 670, "650");
	outtextxy(320, 690, "670");
	outtextxy(320, 710, "690");
	outtextxy(320, 730, "710");
	outtextxy(320, 750, "730");
	outtextxy(320, 770, "750");
	outtextxy(320, 790, "770");
	outtextxy(320, 810, "790");
	outtextxy(320, 830, "810");
	outtextxy(320, 850, "830");
	outtextxy(320, 870, "850");	
	setcolor(WHITE);
}
void predkosci(double *vx, double *vy, int n)
{
	for (int i = 0; i < (n + 1); i++)
	{
		vx[i] = 0;
		vy[i] = 0;
	}
}
void run(double *x, double *y, double *vx, double *vy, int n, double &j)
{
	for (int i = 0; i < (n+1); i++)
	{
		x[i] = x[i] + vx[i];
		y[i] = y[i] + vy[i];
		if (((x[i] - 362) < 5) || ((int)(838.0 - x[i]) < 5))
		{
			vx[i] = -vx[i];
		}
		if (((y[i] - 22) < 5) || ((878.0 - y[i]) < 5))
		{
			vy[i] = -vy[i];
		}
	}
}

void searchAndCollide(double *x, double *y, double *vx, double *vy, int a)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = i + 1; j < a; j++)
		{
			double s = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
			double sx, sy, vnx, vny;
			if (s < 21)
			{
				double vwx, vwy;
				vwx = vx[i] - vx[j];	//przechodze do 2 ukladu odniesienia
				vwy = vy[i] - vy[j];	//ita pilka ma predkosc -v predkosci jtej pilki
				sx = (x[i] - x[j]) / s;	//wspolrzedne wektora odleglosci miedzy pilkami
				sy = (y[i] - y[j]) / s;	//wektory jednostkowe
				vnx = (vwx*sx + vwy * sy)*sx;	//predkosc
				vny = (vwx*sx + vwy * sy)*sy;
				vx[i] = vx[i] - vnx;
				vy[i] = vy[i] - vny;
				vx[j] = vx[j] + vnx;
				vy[j] = vy[j] + vny;
			}
		}
	}
}
void showpocket()
{
	arc(360, 880, 0, 90, 30);
	arc(360, 20, 270, 0, 30);
	arc(840, 20, 180, 270,30);
	arc(840, 880, 90, 180, 30);
	arc(360, 440, 270, 90, 30);
	arc(840, 440, 90, 270, 30);
}
void pocket(double *x, double *y, double *vx, double *vy, int n, int &zielony, int &niebieski, int &koniec)
{
	for (int i = 0; i < (n/2); i++)
	{
		if ((x[i] < 390) && ((y[i] < 50) || (y[i] > 850) || ((y[i] > 410) && (y[i] < 470))))
		{
			vx[i] = 0; vy[i] = 0;
			printf("punkt dla zielonego\n");
			zielony++;
			time_t start, end;
			time(&start);
			do time(&end);
			while (difftime(end, start) <= 2.0);
			x[i] = 500;
			y[i] = 1000;
		}
		if ((x[i] >810) && ((y[i] < 50) || (y[i] > 850) || ((y[i] > 410) && (y[i] < 470))))
		{
			vx[i] = 0; vy[i] = 0;
			printf("punkt dla zielonego\n");
			zielony++;
			time_t start, end;
			time(&start);
			do time(&end);
			while (difftime(end, start) <= 2.0);
			x[i] = 500.0;
			y[i] = 1000;
		}
	}
	for (int i = (n/2); i < (n-1); i++)
	{
		if ((x[i] < 390) && ((y[i] < 50) || (y[i] > 850) || ((y[i] > 410) && (y[i] < 470))))
		{
			vx[i] = 0; vy[i] = 0;
			printf("punkt dla niebieskiego\n");
			niebieski++;
			time_t start, end;
			time(&start);
			do time(&end);
			while (difftime(end, start) <= 2.0);
			x[i] =500.0;
			y[i] = 1000;
		}
		if ((x[i] > 810) && ((y[i] < 50) || (y[i] > 850) || ((y[i] > 410) && (y[i] < 470))))
		{
			vx[i] = 0; vy[i] = 0;
			printf("punkt dla niebieskiego\n");
			niebieski++;
			time_t start, end;
			time(&start);
			do time(&end);
			while (difftime(end, start) <= 2.0);
			x[i] = 500.0;
			y[i] = 1000;
		}
	}
	if ((x[n-1] < 390) && ((y[n-1] < 50) || (y[n-1] > 850) || ((y[n-1] > 410) && (y[n-1] < 470))))
	{
		x[n-1] = 500.0;
		y[n-1] = 1000.0;
		koniec = 1;
		printf("KONIEC GRY");
	}
	if ((x[n - 1] > 810) && ((y[n - 1] < 50) || (y[n - 1] > 850) || ((y[n - 1] > 410) && (y[n - 1] < 470))))
	{
		x[n - 1] = 500.0;
		y[n - 1] = 1000.0;
		koniec = 1;
		printf("KONIEC GRY");
	}
}
void punkty(int &zielony, int &niebieski)
{
	for (int i = 0; i < zielony; i++)
	{
		circle(60, 30 * i+60, 10);
	}
	for (int i = 0; i < niebieski; i++)
	{
		circle(930, 30 * i + 60, 10);
	}
}
int main()
{
	printf("\t\tWitaj w grze bilard!\n\n");
	printf("Oto kilka niezbednych informacji:\n");
	printf("Stol do bilarda ma wymiar 480x860\n");
	
	printf("w lewym gornym rogu beda sie pojawiac punkty gracza grajacego zielonymi bilami\n");
	printf("w prawym gornym rogu beda sie pojawiac punkty gracza grajacego niebieskimi bilami\n");
	printf("Gra polega na podawaniu komputerowi wspolrzednych punktu na stole do ktorego\n");
	printf("ma zmierzac biala bila i sily uderzenia.\n");
	printf(" Najpierw gracz podaje wspolrzedna x a potem y a nastepnie sile strzalu\n");
	printf("Wartosci podawanych wspolrzednych stolu do ktorej ma leciec biala bila moga byc z przedzialu:\n");
	printf(" dla x\t(0,480)\n dla y\t (0,860)\n");
	printf("Przed kazdym strzalem komputer bedzie ci podawal dokladne wspolrzedne bili bialej na stole\n");
	printf("Gra sie zakonczy jesli ktorys z graczy zbije wszystkie bile jednego koloru badz zbije bile czerwona\n");
	printf("Biala bila nie wpada do luz \n\n");

	graphics(1200, 930);
	int n = 15; //tyle bedzie bil bez bialej
	double *x, *y; // wspó³rzedne pi³ek n+1 komorka to dane bili bialej
	double *vx, *vy; // sk³adowe predkosci pi³ek
	x = (double*)malloc((n + 1) * sizeof(double));
	y = (double*)malloc((n + 1) * sizeof(double));
	vx = (double*)malloc((n + 1) * sizeof(double));
	vy = (double*)malloc((n + 1) * sizeof(double));

	srand(time(NULL));
	init(x, y, n);		//tworze wartosci dla polozen
	display(x, y, n);	//wyswietla na ekranie kulki
	
	podzialka();		//wstawia uklad wspolrzednych
	showpocket();		//tworzy luzy
	predkosci(vx, vy, n);	//zeruje tablice predkosci
	setcolor(GREEN);
	outtextxy(30, 30, "gracz zielony");
	
	setcolor(BLUE);
	outtextxy(900, 30, "gracz niebieski");
	setcolor(WHITE);
	
	double bx, by;	//wspolrzedne ktore podaje gracz
	double wx, wy;	//wektor kierunku bialej bili
	double j;
	int fs;		//wartosc sily
	double highestx = 0.0;
	double highesty = 0.0;
	int zielony = 0, niebieski = 0, koniec=0;
	while (true)
	{
	tutaj:
		setcolor(GREEN);
		outtextxy(30, 30, "gracz zielony");
		setcolor(BLUE);
		outtextxy(900, 30, "gracz niebieski");
		punkty(zielony, niebieski);
		setcolor(WHITE);
		display(x, y, n);
		punkty(zielony, niebieski);
		//printf("\npolozenie bialej bili przed zmiana dla programu  %lf\t%lf\n", x[n], y[n]);
		printf("polozenie bialej bili\t%lf\t%lf\n", x[n]-360, y[n]-20);
		printf("Podaj wspolrzedne punktu na stole bilardowym do ktorego ma zmierzac bila i sile strzalu w skali 1-10\n");
	here:
		scanf("%lf%lf%d", &bx, &by, &fs);
		if (fs > 10 || fs < 0 || bx < 0|| bx>480 || by<0 || by>860)	//jesli gracz podal zle wspolrzedne
		{
			printf("Podaj wspolrzedne punktu na stole bilardowym do ktorego ma zmierzac bila i sile strzalu w skali 1-10 jeszcze raz\n");
			goto here;
		}
		else
		{
		wx = bx + 360.0 - x[n];
		wy = by + 20.0 - y[n];
		
		vx[n] = (wx / sqrt(wx*wx + wy * wy));
		vy[n] = (wy / sqrt(wx*wx + wy * wy));

		vx[n] = vx[n] * fs*0.8;
		vy[n] = vy[n] * fs*0.8;
		
		while (animate(150))
		{
			cleardevice();
			for (int i = 0; i < n+1; i++)	// spowalniam ruch wszystkich kulek
			{
				vx[i] = vx[i] * 0.995;
				vy[i] = vy[i] * 0.995;
			}
			highestx = highestx * 0.995;
			highesty = highesty * 0.995;
			for (int i = 0; i < n+1; i++)
			{
				if ((fabs(vx[i]) > highestx) && (fabs(vx[i]) > 0.005))
				{
					highestx = (fabs(vx[i]));
				}
				if ((fabs(vy[i]) > highesty) && (fabs(vy[i]) > 0.005))
				{
					highesty = (fabs(vy[i]));
				}
			}
			
			run(x, y, vx, vy, n, j);	//kulki sie ruszaja i odbijaj¹ od œcianek
			setcolor(RED);
			display(x, y, n);			//pokazuje sie stol bilardowy
			podzialka();				//pokazuje sie uklad wspolrzednych
			showpocket();				//pokazuje fragmenty okregow jako luzy
			searchAndCollide(x, y, vx, vy, n+1); //kulki siê odbijaj¹ od siebie
			pocket(x,y,vx,vy,n,zielony,niebieski,koniec);					//odpowiada za znikanie pilek w luzach
			
			if ((koniec == 1)||(niebieski==(n/2-1))||(zielony==(n/2-1)))//poprawic
			{
				printf("koniec gry");
				goto tu;
			}
			if ((highestx < 0.01) && (highesty < 0.01))	//warunek zeby petla nie dzialala w inf
			{
				goto tutaj;
			}
		}
		}
	}
	tu:
	wait();
	return 0;
}
