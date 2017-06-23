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

	printf("게임을 시작하시겠습니까?(yes:1/no:0)");
	scanf("%d",&num);

	if(num == 1){
		twoPlayer();
		printf("당신이 갖고 있는 카드입니다.\n");
		for(j = 0; j < 7; j++){
			printf("%d	", player1[j]);
		}
		twoPlay();
		
		if(result == true){
			printf("축하합니다 승리하셨습니다.");
		}
		else{
			printf("저런... 패배하셨습니다."); 
		}
	}
	else
		printf("프로그램을 종료합니다.");
	
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
			printf("\n어떤 카드를 내시겠습니까? ");
			scanf("%d", &ans);
			if(ans == 1){	
				for(i=0;i<7;++i){
						if(player1[i]==ans){
							printf("%d를 내셨군요.당신의 차례입니다. 다시 카드를 내세요\n", player1[i]);
							i = 100;
							player1[i] = 100;
						}
						else{
							if(i==7){
								printf("가지고 계시지 않은 카드입니다!\n");
							}
						}
					}
				j = 0;
			}
			else if(ans == 0){
				printf("pass!\n");
				printf("초기화 되었습니다.");
				k = 10; 
				j = 0;
			}
			else{
				for(i=0;i<7;++i){
					if(player1[i]==ans){
						printf("%d를 내셨군요. player2가 카드를 고르는 중입니다...\n", player1[i]);
						i = 100;
						player1[i] = 100;
					}
					else{
						if(i==6){
							printf("가지고 계시지 않은 카드입니다!\n");
						}
						j = 0;
					}
				}
				for(i=0;i<8;){
					if(ans>player2[i]){
						printf("player2가 %d를 냈습니다.\n",player2[i]);
						k = player2[i];
						i = 10;
						player2[i] = 100;
					}
					else{
						if(i==7){
							printf("player2가 낼 수 있는 카드가 없습니다. 턴을 넘깁니다.\n");
						}
						++i;
						j = 0;
					}
				}	
			}
			if(ans > k){
				printf("player2의 숫자보다 높습니다. 다시 카드를 내세요\n");
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

