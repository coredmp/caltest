#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAXDAYS 1000
typedef struct day day;
struct day {
	//char datestr[30];
	time_t rwtime;	
	char t0[100];	/* 07-08*/
	char t1[100];	/* 08-09*/
	char t2[100];	/* 09-10*/
	char t3[100];	/* 10-11*/
	char t4[100];	/* 11-12*/
	char t5[100];	/* 12-13*/
	char t6[100];	/* 13-14*/
	char t7[100];	/* 14-15*/
	char t8[100];	/* 15-16*/
	char t9[100];	/* 16-17*/
	char t10[100];	/* 17-18*/
	char t11[100];	/* 18-19*/
	char t12[100];	/* 19-20*/
	char t13[100];	/* 20-21*/
	char t14[100];	/* 21-22*/

	day* nxt_p;
	day* prev_p;
};




/* List of days */
day* begin;



/* Funktionen */
day* mkday(time_t *t);
int insertday(day* newday);

int main()
{
	begin = NULL;
	time_t now; 
	time(&now);
	day* d = mkday(&now);	
	insertday(d);
	printf("%s\n", ctime( &now));
	printlist();


}




/*
 * Alloziert Speicher für ein day Objekt und setzt das Datum
 */
day* mkday(time_t *t)
{
	day* newday;
	newday = (day*)malloc(sizeof(day));	
	
	newday->rwtime = *t;
	newday->nxt_p = NULL;
	newday->prev_p = NULL;
	return newday;
}


/*
 * Fügt ein Day Objekt in die Liste an der richtigen Stelle ein
 * 	1) Suche den richtigen Ort
 * 	2) Setzte die Pointer richtig und neu
 */
int insertday(day* newday)
{
	int i, b;
	b = i = 0;
	day *cur;

	cur = begin;
	// Noch kein Element in der Liste
	if( begin == NULL )
		begin = newday;
	else{
		while( 1 ){
		if( newday->rwtime >= cur->rwtime ){
				cur = cur->nxt_p;
			}else if( newday->rwtime < cur->rwtime ){
				//einfügen!

			}
		}
	
	}

}


/*
 * Zeige die Liste an
 */
int printlist()
{
	int i;
	i = 0;
//
//	while( listofdays[i] != NULL ){
//		printf("%s\n", ctime(&(listofdays[i])->rwtime));
//		i++;
//	}
}
