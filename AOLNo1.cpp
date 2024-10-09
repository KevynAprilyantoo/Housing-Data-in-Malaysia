#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct Malaysia{
	char loc1[100];
	char loc2[100];
	double price;
	int room;
	int bathroom;
	int carparks;
	char type[100];
	long long int area;
	char furnish[100];
} Wisata[5000];

int main(){
	FILE *File;
	File = fopen("./file.csv","r");
	char copy[100];
	fscanf(File,"%[^\n]\n",copy);
	int total;
	while (!feof(File)){
		fscanf(File,"%[^,],%[^,],%lf,%d,%d,%d,%[^,],%lld,%s\n",Wisata[total].loc1,Wisata[total].loc2,&Wisata[total].price,&Wisata[total].room,&Wisata[total].bathroom,&Wisata[total].carparks,Wisata[total].type,&Wisata[total].area,Wisata[total].furnish);
		total++;
	}
	system("cls");
	int count = 0;
	int sum[5000]={0};
	char find[100];
	int Update;
	int max = 0;
	int min;
	long long int value;
	printf("Option : loc1 | loc2 | price | room | bathrooms | carparks | type | area | furnish |\n");
	printf("Choose one to view information : ");
	scanf("%s",find); getchar();
	if(strcmp(find,"loc1")==0){
		for(int i=0;i<total;i++){
			count = 1;
			if(strcmp(Wisata[i].loc1,"-1")!=0){
				for(int j=i+1 ;j<total ;j++){
						if(strcmp(Wisata[i].loc1,Wisata[j].loc1)==0){
							count++;
							strcpy(Wisata[j].loc1,"-1");
						}
					}
					sum[i] = count;
				}
			}
			for(int i=0; i<total; i++){
				if(strcmp(Wisata[i].loc1,"-1")!=0){
					printf("%s : %d\n",Wisata[i].loc1,sum[i]);
				}
			}
			
			for(int i=0; i<total; i++){
				if(sum[i] > max && sum[i] != -1){
					max = sum[i];
					Update = i;
				}
			}
			
			printf("Maximum Value: %s with frequency: %d\n",Wisata[Update].loc1,max);
			min = sum[0];
			for(int i=0; i<total; i++){
				if(min >= sum[i]&&sum[i]!=0){
					min = sum[i];
					Update = i;
				}
			}
			printf("Minimum Value: %s with frequency: %d",Wisata[Update].loc1,min);
		}
		else if(strcmp(find,"loc2")==0){
			for(int i=0 ;i<total ;i++){
				count = 1;
				if(strcmp(Wisata[i].loc2,"-1")!=0){ 
					for(int j=i+1 ;j<total ;j++){
						if(strcmp(Wisata[i].loc2,Wisata[j].loc2)==0){
							count++;
							strcpy(Wisata[j].loc2,"-1");
						}
					}
					sum[i] = count;
				}
			}
			for(int i=0; i<total ;i++){
				if(strcmp(Wisata[i].loc2,"-1")!=0){
					printf("%s : %d\n",Wisata[i].loc2,sum[i]);
				}
			}
			for(int i=0 ;i<total ;i++){
				if(sum[i] > max ){
					max = sum[i];
					Update = i;
				}
			}
			printf("Maximum Value: %s with frequency: %d\n",Wisata[Update].loc2,max);
			min = sum[0];
			for(int i=0; i<total; i++){
				if(min >= sum[i]&&sum[i]!=0){
					min = sum[i];
					Update = i;
				}
			}
			printf("Minimum Value: %s with frequency: %d",Wisata[Update].loc2,min);
		}
		else if(strcmp(find,"room")==0){
			for(int i=0 ;i<total ;i++){
				count = 1;
				if(Wisata[i].room != -1){ 
					for(int j=i+1; j<total; j++){
						if(Wisata[i].room == Wisata[j].room){
							count++;
							Wisata[j].room = -1;
						}
					}
					sum[i] = count;
				}
			}
			for(int i=0; i<total; i++){
				if(Wisata[i].room != -1){
					printf("%d : %d\n",Wisata[i].room,sum[i]);
				}
			}
			for(int i=0; i<total ;i++){
				if(sum[i] > max ){
					max = sum[i];
					Update = i;
				}
			}
			printf("Maximum Value: %d with frequency: %d\n",Wisata[Update].room,max);
			min = sum[0];
			for(int i=0 ;i<total ;i++){
				if(min >= sum[i]&&sum[i]!=0){
					min = sum[i];
					Update = i;
				}
			}
			printf("Minimum Value: %d with frequency: %d",Wisata[Update].room,min);
		}
		else if(strcmp(find,"bathrooms")==0){
			for(int i=0; i<total; i++){
				count = 1;
				if(Wisata[i].bathroom != -1){ 
					for(int j=i+1; j<total; j++){
						if(Wisata[i].bathroom==Wisata[j].bathroom){
							count++;
							Wisata[j].bathroom = -1;
						}
					}
					sum[i] = count;
				}
			}
			for(int i=0; i<total; i++){
				if(Wisata[i].bathroom!=-1){
					printf("%d : %d\n",Wisata[i].bathroom,sum[i]);
				}
			}
			for(int i=0; i<total; i++){
				if(sum[i] > max ){
					max = sum[i];
					Update = i;
				}
			}
			printf("Maximum Value: %d with frequency: %d\n",Wisata[Update].bathroom,max);
			min = sum[0];
			for(int i=0; i<total; i++){
				if(min >= sum[i]&&sum[i]!=0){
					min = sum[i];
					Update = i;
				}
			}
			printf("Minimum Value: %d with frequency: %d",Wisata[Update].bathroom,min);
		}
		else if(strcmp(find,"carparks")==0){
			for(int i=0;i<total;i++){
				count = 1;
				if(Wisata[i].carparks != -1){ 
					for(int j=i+1; j<total; j++){
						if(Wisata[i].carparks==Wisata[j].carparks){
							count++;
							Wisata[j].carparks = -1;
						}
					}
					sum[i] = count;
				}
			}
			for(int i=0; i<total; i++){
				if(Wisata[i].carparks!=-1){
					printf("%d : %d\n",Wisata[i].carparks,sum[i]);
				}
			}
			for(int i=0; i<total; i++){
				if(sum[i] > max ){
					max = sum[i];
					Update = i;
				}
			}
			printf("Maximum Value: %d with frequency: %d\n",Wisata[Update].carparks,max);
			min = sum[0];
			for(int i=0; i<total; i++){
				if(min >= sum[i]&&sum[i]!=0){
					min = sum[i];
					Update = i;
				}
			}
			printf("Minimum Value: %d with frequency: %d",Wisata[Update].carparks,min);
		}
		else if(strcmp(find,"type")==0){
			for(int i=0; i<total; i++){
				count = 1;
				if(strcmp(Wisata[i].type,"-1")!=0){
					for(int j=i+1; j<total; j++){
						if(strcmp(Wisata[i].type,Wisata[j].type)==0){
							count++;
							strcpy(Wisata[j].type,"-1");
						}
					}
					sum[i] = count;
				}
			}
			for(int i=0; i<total; i++){
				if(strcmp(Wisata[i].type,"-1")!=0){
					printf("%s : %d\n",Wisata[i].type,sum[i]);
				}
			}
			for(int i=0; i<total; i++){
				if(sum[i] > max ){
					max = sum[i];
					Update = i;
				}
			}
			printf("Maximum Value: %s with frequency: %d\n",Wisata[Update].type,max);
			min = sum[0];
			for(int i=0; i<total; i++){
				if(min >= sum[i]&&sum[i]!=0){
					min = sum[i];
					Update = i;
				}
			}
			printf("Minimum Value: %s with frequency: %d",Wisata[Update].type,min);
		}
		else if(strcmp(find,"furnish")==0){
			for(int i=0; i<total; i++){
				count = 1;
				if(strcmp(Wisata[i].furnish,"-1")!=0){
					for(int j=i+1; j<total; j++){
						if(strcmp(Wisata[i].furnish,Wisata[j].furnish)==0){
							count++;
							strcpy(Wisata[j].furnish,"-1");
						}
					}
					sum[i] = count;
				}
			}
			for(int i=0; i<total; i++){
				if(strcmp(Wisata[i].furnish,"-1")!=0){
					printf("%s : %d\n",Wisata[i].furnish,sum[i]);
				}
			}
			for(int i=0; i<total; i++){
				if(sum[i] > max ){
					max = sum[i];
					Update = i;
				}
			}
			printf("Maximum Value: %s with frequency: %d\n",Wisata[Update].furnish,max);
			min = sum[0];
			for(int i=0; i<total; i++){
				if(min >= sum[i]&&sum[i]!=0){
					min = sum[i];
					Update = i;
				}
			}
			printf("Minimum Value: %s with frequency: %d\n",Wisata[Update].furnish,min);
		}
		
		if(strcmp(find,"area")==0){
			min = Wisata[0].area;
			for(int i=0; i<total; i++){
				if(min > Wisata[i].area){
					min = Wisata[i].area;
					Update = i;
				}
			}
			printf("Minimum Value: %lld\n",Wisata[Update].area);
			for(int i=0; i<total; i++){
				if(max < Wisata[i].area){
					max = Wisata[i].area;
					Update = i;
				}
			}
			printf("Maximum Value: %lld\n",Wisata[Update].area);
			for(int i=0; i<total; i++){
				value += Wisata[i].area;
			}
			double average = value/total;
			printf("Average Value: %0.2lf",average);
		}
		else if(strcmp(find,"price")==0){
			min = Wisata[0].price;
			for(int i=0; i<total; i++){
				if(min > Wisata[i].price){
					min = Wisata[i].price;
					Update = i;
				}
			}
			printf("Minimum Value: %.0lf\n",Wisata[Update].price);
			for(int i=0; i<total; i++){
				if(max < Wisata[i].price){
					max = Wisata[i].price;
					Update = i;
				}
			}
			printf("Maximum Value: %.0lf\n",Wisata[Update].price);
			for(int i=0; i<total; i++){
				value += Wisata[i].price;
			}
			double average = value/total;
			printf("Average Value: %.2lf\n",average);
		}
	}


