#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void twoPlayer();
void twoPlay();
static int player1[7];
static int player2[8];
static bool result = false;
static int ans;

int main(){
	int num;
	int j;
	int cardOfNum;

	printf("������ �����Ͻðڽ��ϱ�?(yes:1/no:0)");
	scanf("%d",&num);

	if(num == 1){
		twoPlayer();
		printf("����� ���� �ִ� ī���Դϴ�.\n");
		for(j = 0; j < 7; j++){
			printf("%d	", player1[j]);
		}
		twoPlay();
		
		if(result == true){
			printf("�����մϴ� �¸��ϼ̽��ϴ�.");
		}
		else{
			printf("����... �й��ϼ̽��ϴ�."); 
		}
	}
	else
		printf("���α׷��� �����մϴ�.");
	
	return 0; 
}

void twoPlayer(){
	int num[15] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
	int num2[15];
	bool bCheckExistOfNum[45] = {false, };
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<15;){
		int tmp = (rand()%15);
		if(bCheckExistOfNum[tmp] == false){
			bCheckExistOfNum[tmp] == true;
			num2[i] = num[tmp];
			++i;
		}
	}
	for(i=0;i<7;++i){
		player1[i] = num2[i];
	}
	for(i;i<15;++i){
		player2[i] = num2[i];
	}
}
void twoPlay(){
	int i;
	int j=1;
	int k = 10;
	int result1[7] = {100, 100, 100, 100, 100, 100, 100};
	int result2[8] = {100, 100, 100, 100, 100, 100, 100, 100};
	while(player1 != result1 || player2 != result2){
		while(j=1){
			printf("\n� ī�带 ���ðڽ��ϱ�? ");
			scanf("%d", &ans);
			if(ans == 1){	
				for(i=0;i<7;++i){
						if(player1[i]==ans){
							printf("%d�� ���̱���.����� �����Դϴ�. �ٽ� ī�带 ������\n", player1[i]);
							i = 100;
							player1[i] = 100;
						}
						else{
							if(i==7){
								printf("������ ����� ���� ī���Դϴ�!\n");
							}
						}
					}
				j = 0;
			}
			else if(ans == 0){
				printf("pass!\n");
				printf("�ʱ�ȭ �Ǿ����ϴ�.");
				k = 10; 
				j = 0;
			}
			else{
				for(i=0;i<7;++i){
					if(player1[i]==ans){
						printf("%d�� ���̱���. player2�� ī�带 ���� ���Դϴ�...\n", player1[i]);
						i = 100;
						player1[i] = 100;
					}
					else{
						if(i==6){
							printf("������ ����� ���� ī���Դϴ�!\n");
						}
						j = 0;
					}
				}
				for(i=0;i<8;){
					if(ans>player2[i]){
						printf("player2�� %d�� �½��ϴ�.\n",player2[i]);
						k = player2[i];
						i = 10;
						player2[i] = 100;
					}
					else{
						if(i==7){
							printf("player2�� �� �� �ִ� ī�尡 �����ϴ�. ���� �ѱ�ϴ�.\n");
						}
						++i;
						j = 0;
					}
				}	
			}
			if(ans > k){
				printf("player2�� ���ں��� �����ϴ�. �ٽ� ī�带 ������\n");
				j = 0;
			}
		}
		j = 1;
		k = 10;
	}
	if(player1 == result1){
		result = true;
	}
	if(player2 == result2){
		result = false;
	}
}

