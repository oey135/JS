#include <stdio.h>
#include <string.h>

typedef struct info {
	char name[20];
	int birth;
	char live[10];
	char clas[5];
} Info;
	

void scan(Info *, char *, char *, int *);
void search(Info *);

int main() {
	
	Info info[5];
	
	char gender[7];
	char rel[20];
	
	int static count = 0;
	
	int dfd=0;
	while(dfd==0) {
		
		
		printf("1.입력 2.검색 3.종료 : ");
		int m=0;
		scanf("%d", &m);
		scanf("%c");
		
		switch (m) {
			case 1:
				printf("\n");
				scan(info, rel, gender, &count);
				break;
				
			case 2:
				printf("\n");
				printf("%d", count);
				search(info);
				break;
				
			case 3:
				dfd=1;
				break;
		}
	}
	
	for(int i=0; i<count+1; i++) {
		printf("\n%s %s %d %s", info[i].clas, info[i].name, info[i].birth, info[i].live);
	}
	
	
	
	return 0;
}

void search(Info *info) {
	char fam[10];
	
	printf("\n찾을 정보의 성 : ");
	gets_s(fam, 9);
	
	
	printf("%s | %s", strchr(info[0].name, ' '), info[0].name);
	
	
}

void scan(Info *info, char *rel, char *gender, int *count) {
	
	printf("성 이름 : ");
	gets_s((info+*count)->name, 19);
		
	printf("성별(여자, 남자) : ");
	gets_s(gender, 7);
			
	printf("출생년도 : ");
	scanf("%d", &info[*count].birth);
	scanf("%c");
		
	printf("거주지역 : ");
	gets_s(info[*count].live, 10);
	
	printf("관계(가족, 친구, 동료) : ");
	gets_s(rel, 20);
	
	
	if(strcmp(rel,"가족")==0) {
		strcpy(info[*count].clas, "00");
	}
	else if(strcmp(rel,"친구")==0) {
		strcpy(info[*count].clas, "01");
	}
	else if(strcmp(rel,"동료")==0) {
		strcpy(info[*count].clas, "02");
	}
	
	if(strcmp(gender,"여자")==0) {
		strcat(info[*count].clas,"-2");
	}
	else if(strcmp(gender, "남자")==0) {
		strcat(info[*count].clas,"-1");
	}
	 
	count++;

}

