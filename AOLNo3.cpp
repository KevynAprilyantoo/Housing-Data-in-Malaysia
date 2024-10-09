#include <stdio.h>
#include <string.h>
#include <windows.h>

struct Malaysia{
	char loc1[255];
	char loc2[255];
	char price[255];
	char room[255];
	char bathrooms[255];
	char carparks[255];
	char type[255];
	char area[255];
	char furnish[255];
};

struct Malaysia Wisata[5000];

void sorting(struct Malaysia Wisata[5000], int total){
	for(int i=0; i<total-1; i++){
		for(int j=0; j<total-1-i; j++){
			struct Malaysia temp;
			if(strcmp(Wisata[j].loc1, Wisata[j+1].loc1) > 0){
				temp = Wisata[j];
				Wisata[j] = Wisata[j+1];
				Wisata[j+1] = temp;
			}
		}
	}
}

int main(){
	int total = 0;
	char read[500];
	FILE *File = fopen("file.csv", "r");
	fscanf(File, "%[^\n]\n", read);
	while(!feof(File)){
		fscanf(File, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", Wisata[total].loc1, Wisata[total].loc2, &Wisata[total].price, &Wisata[total].room, &Wisata[total].bathrooms, &Wisata[total].carparks, Wisata[total].type, &Wisata[total].area, Wisata[total].furnish);
		total++;
	}
	sorting(Wisata, total);
	for(int i=0; i<total; i++){
		printf("%-24s | %-13s | %-9s | %-2s | %-2s | %-2s | %-9s | %-6s | %s\n", Wisata[i].loc1, Wisata[i].loc2, Wisata[i].price, Wisata[i].room, Wisata[i].bathrooms, Wisata[i].carparks, Wisata[i].type, Wisata[i].area, Wisata[i].furnish);
	}
	
	fclose(File);
	
	return 0;
}
