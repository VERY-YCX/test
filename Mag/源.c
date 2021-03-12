#include <stdio.h>
#include"readline.h"
#define NAME_LEN 25
#define MAX_PARTS 100

void insert(void);
void search(void);
void update(void);
void print(void);
int find_part(int number);

struct part {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
}inventory [MAX_PARTS];
int num_parts = 0;

int main(void)
{
	char code;
	for (;;) {
		printf("Enter operation code:");
		scanf_s("%c", &code);
		while (getchar() != '\n')
			;
			switch (code) {
			case 'i':insert();
				break;
			case 's':search();
				break;
			case 'u':update();
				break;
			case 'p':print();
				break;
			case 'q':return 0;
			default:printf("Illegal code!\n");
			}
			printf("\n");
		}
}
	//判断零件编号是否存在并寻找零件编号对应的数组中的位置
	int find_part(int number)
	{
		int i;
		for (i = 0;i < num_parts;i++) {
			if (inventory[i].number == number)
				return i;
			return -1;
		}
	}
	//输入函数
	void insert(void){
			int part_number;
			if (num_parts == MAX_PARTS) {
				printf("Database is full;can't add more parts!");
				return;
			}
			printf("enter part number:");
			scanf_s(" %d", &part_number);
			if (find_part(part_number >= 0)) {
				printf("The number aleady exits!");
				return;
			}
			inventory[num_parts].number = part_number;
			printf("enter the part name:");
		 read_line(inventory[num_parts].name, NAME_LEN);
			printf("enter the quantity on hand:");
			scanf_s("%d", &inventory[num_parts].on_hand);
			num_parts++;
		}
  //查询零件信息
	void search(void){
			int part_number;
			int i;
			printf("enter part number:");
			scanf_s("%d", &part_number);
			i = find_part(part_number);
			if (i >= 0) {
				printf("Part name:%s\n", inventory[i].name);
				printf("Quantity on hand:%d\n", inventory[i].on_hand);
			}
			else printf("Not found\n");
		}
    //更新零件数量
	void update(void) {
			int part_number=0,i,change;
			printf("enter part number:");
			scanf_s("%d", part_number);
			i = find_part(part_number);
			if (i >= 0) {
				printf("Enter the change number of the part:");
				scanf_s("%d", &change);
				inventory[i].number += change;
			}
			else printf("Not found\n");
		}
  //打印现有所有的零件相关信息
	void print(void){
			int i;
			for (i = 0;i < num_parts;i++) {
				printf("number:%d\n", inventory[i].number);
				printf("name:%s\n", inventory[i].name);
				printf("quantity:%d\n", inventory[i].on_hand);
				printf("\n");
			}
		}