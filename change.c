#include "head.h"
/*该函数实现的是对指定订单号进行修改*/
/*形参num用于判断所要更改的订单号*/ 

struct Order *change(struct Order *head,long num){
	struct Order *p;//定义结构体指针 
	int a=-1;//定义变量，a为选择需要修改的信息 
	p=head;//令p指向头结点 
	while(p!=NULL){//遍历链表 
		if(p->num==num){//查询到订单信息时 
			printf("查询到%ld订单信息：\n",num);//打印提示语 
			print(p,0);//打印对应结果 
			while(1){//让程序一直运行直到结束
				printf("请选择您要修改的信息：\n");//打印提示语 
				printf("1.商品名 2.商品价格 3.收货地址 4.交易日期 0.退出\n"); //打印提示语 
				scanf("%d",&a);//输入选择 
				while(getchar()!='\n');//清空缓存区 
				switch (a){
					case 1://修改商品名 
						printf("请输入新商品名：");//打印提示语 
						scanf("%s",p->name);//输入新商品名 
						printf("修改成功！\n");//打印提示语 
						break;
					case 2://修改商品价格 
						printf("请输入新商品价格：");//打印提示语 
						scanf("%f",&p->price);//输入新商品价格 
						printf("修改成功！\n");//打印提示语
						break;
					case 3://修改收货地址 
						printf("请输入新收货地址：");//打印提示语
						scanf("%s",p->address);//输入新收货地址 
						printf("修改成功！\n");//打印提示语
						break;
					case 4://修改交易日期 
						printf("请输入新交易日期（年 月 日）：");//打印提示语
						scanf("%d %d %d",&p->date.year,&p->date.month,&p->date.day);//输入新交易日期 
						printf("修改成功！\n");//打印提示语
						break;
					case 0://退出 
						return (head);//结束运行 
						break;
					default://输入错误 
						printf("输入错误！请重新输入!");//打印提示语
						system("pause");//暂停程序 
						break;
				}
			} 
		}
		else if(p->next==NULL&&p->num!=num) {//遍历到最后一个结点都查询不到订单信息 
			printf("查找不到%ld号订单！",num);//打印提示语
			system("pause");//暂停程序 
			return NULL;//返回NULL 
		}
		p=p->next;//令p指向下一个结点 
	}
} 
