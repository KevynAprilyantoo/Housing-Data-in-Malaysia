#include <stdio.h>
#include <string.h>
#include <windows.h>

struct Malaysia{
	char loc1[50];
	char loc2[50];
	char price[50];
	char room[50];
	char bathrooms[50];
	char carparks[50];
	char type[50];
	char area[50];
	char furnish[50];
};

struct Malaysia Wisata[5000];

void loc1(char object[], int total){
	for(int i=0; i<total; i++){
		if(strstr(Wisata[i].loc1, object)){
			printf("%-24s | %-13s | %-9s | %-2s | %-2s | %-2s | %-9s | %-6s | %s\n", Wisata[i].loc1, Wisata[i].loc2, Wisata[i].price, Wisata[i].room, Wisata[i].bathrooms, Wisata[i].carparks, Wisata[i].type, Wisata[i].area, Wisata[i].furnish);
		}
	}
}

void loc2(char object[], int total){
	for(int i=0; i<total; i++){
		if(strstr(Wisata[i].loc2, object)){
			printf("%-24s | %-13s | %-9s | %-2s | %-2s | %-2s | %-9s | %-6s | %s\n", Wisata[i].loc1, Wisata[i].loc2, Wisata[i].price, Wisata[i].room, Wisata[i].bathrooms, Wisata[i].carparks, Wisata[i].type, Wisata[i].area, Wisata[i].furnish);
		}
	}
}

void room(char object[], int total){
	for(int i=0; i<total; i++){
		if(strcmp(object, Wisata[i].room) == 0){
			printf("%-24s | %-13s | %-9s | %-2s | %-2s | %-2s | %-9s | %-6s | %s\n", Wisata[i].loc1, Wisata[i].loc2, Wisata[i].price, Wisata[i].room, Wisata[i].bathrooms, Wisata[i].carparks, Wisata[i].type, Wisata[i].area, Wisata[i].furnish);
		}
	}
}

void bathrooms(char object[], int total){
	for(int i=0; i<total; i++){
		if(strcmp(object, Wisata[i].bathrooms) == 0){
			printf("%-24s | %-13s | %-9s | %-2s | %-2s | %-2s | %-9s | %-6s | %s\n", Wisata[i].loc1, Wisata[i].loc2, Wisata[i].price, Wisata[i].room, Wisata[i].bathrooms, Wisata[i].carparks, Wisata[i].type, Wisata[i].area, Wisata[i].furnish);
		}
	}
}

void carparks(char object[], int total){
	for(int i=0; i<total; i++){
		if(strcmp(object, Wisata[i].carparks) == 0){
			printf("%-24s | %-13s | %-9s | %-2s | %-2s | %-2s | %-9s | %-6s | %s\n", Wisata[i].loc1, Wisata[i].loc2, Wisata[i].price, Wisata[i].room, Wisata[i].bathrooms, Wisata[i].carparks, Wisata[i].type, Wisata[i].area, Wisata[i].furnish);
		}
	}
}

void type(char object[], int total){
	for(int i=0; i<total; i++){
		if(strstr(Wisata[i].type, object)){
			printf("%-24s | %-13s | %-9s | %-2s | %-2s | %-2s | %-10s | %-6s | %s\n", Wisata[i].loc1, Wisata[i].loc2, Wisata[i].price, Wisata[i].room, Wisata[i].bathrooms, Wisata[i].carparks, Wisata[i].type, Wisata[i].area, Wisata[i].furnish);
		}
	}
}

void furnish(char object[], int total){
	for(int i=0; i<total; i++){
		if(strstr(Wisata[i].furnish, object)){
			printf("%-24s | %-13s | %-9s | %-2s | %-2s | %-2s | %-10s | %-6s | %s\n", Wisata[i].loc1, Wisata[i].loc2, Wisata[i].price, Wisata[i].room, Wisata[i].bathrooms, Wisata[i].carparks, Wisata[i].type, Wisata[i].area, Wisata[i].furnish);
		}
	}
}

void search(char object[], char column[], int total){
	system("cls");	if(strcmp(column, "loc1") == 0) loc1(object, total);
	else if(strcmp(column, "loc2") == 0) loc2(object, total);
	else if(strcmp(column, "room") == 0) room(object, total);
	else if(strcmp(column, "bathrooms") == 0) bathrooms(object, total);
	else if(strcmp(column, "carparks") == 0) carparks(object, total);
	else if(strcmp(column, "type") == 0) type(object, total);
	else if(strcmp(column, "furnish") == 0) furnish(object, total);
}

int main(){
	int total = 0;
	char read[500];
	FILE *File = fopen("file.csv", "r");
	fscanf(File, "%[^\n]\n", read);
	while(!feof(File)){
		fscanf(File, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", Wisata[total].loc1, Wisata[total].loc2, Wisata[total].price, Wisata[total].room, Wisata[total].bathrooms, Wisata[total].carparks, Wisata[total].type, Wisata[total].area, Wisata[total].furnish);
		total++;
	}
	char object[50], column[20];
	printf("Option : loc1 | loc2 | room | bathrooms | carparks | type | furnish\n\n");
	printf("Please input with this format to view the information : DataX in ColumnName\n");
	printf("What do want to search : ");
	scanf("%s in %s", object, column); getchar();
	search(object, column, total);
	
	fclose(File);
	
	return 0;
}

