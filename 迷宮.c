#include <stdio.h>
#include <stdlib.h>
#define MAP_MAXSIZE_X 100
#define MAP_MAXSIZE_Y 100
#define MAXSTACK (MAP_MAXSIZE_X*MAP_MAXSIZE_Y)/2  /*定義最大堆疊容量*/



int a,b;
int last_x,last_y;
int stack_x[MAXSTACK]={0};
int stack_y[MAXSTACK]={0};  //堆疊的陣列宣告 
char map[MAP_MAXSIZE_X][MAP_MAXSIZE_Y]={0};
char runmap[MAP_MAXSIZE_X][MAP_MAXSIZE_Y]={0};
int top=0;		//堆疊的頂端
int isEmpty();
void push(int,int); 
int pop(int,int);
void printrunmap(int a,int b);
void run(int ,int );


/*判斷是否為空堆疊*/
int isEmpty(){
	if(top==-1){
		return 1; 
	}else{
		return 0;
	}
} 
/*將指定的資料存入堆疊*/
void push(int x,int y){
	if(top>=MAXSTACK){
		printf("堆疊已滿,無法再加入\n");	
	}else{
		
		stack_x[top]=x;
		stack_y[top]=y;
		top++;
		
	}
 
} 
/*從堆疊取出資料*/
int  pop(int x,int y){
	
	if(isEmpty()){
		return -1;
		
	}else{
		runmap[x][y]='4';
		top--;
		return top;
		
	}
}
void printrunmap(int a,int b)
{
 int i,j;
 for(i=0;i<a+2;i++)
 {
    for(j=0;j<b+2;j++)
	{
	   switch(runmap[i][j])
	   {
				                             
          case '1':
         	      printf("■ ");
                  break;
          case '0': 
                  printf("  ");
                  break;
          case '2':
                  printf("A ");//起點
                  break;
          case '3': 
                  printf("B ");//終點
                  break;
		  case '4': 
                  printf("⊠ "); //已走過
                  break;
				  
		  case '5':
         	      printf("→ ");
                  break;
          case '6': 
                  printf("↓ ");
                  break;
          case '7':
                  printf("← ");
                  break;
          case '8': 
                  printf("↑ ");
                  break;
				  
							
        }
								     
    }
   printf("\n");
 }
printf("\n");
}

void run(int x,int y) //開始點
{
	
	int now_x,now_y;
	now_x = x;
	now_y = y;
	

	
   while(now_x!=last_x || now_y!=last_y){
	   
    if(runmap[now_x][now_y+1]=='0'||runmap[now_x][now_y+1]=='3') //往東
	{
		
		
		runmap[now_x][now_y]='5';
		now_y=now_y+1;
		push(now_x,now_y);
		
		printrunmap(a,b);
		
		
	}else if(runmap[now_x+1][now_y]=='0'||runmap[now_x+1][now_y]=='3')//往南
	{
		
		
		runmap[now_x][now_y]='6';
		now_x=now_x+1;
		push(now_x,now_y);
		
		printrunmap(a,b);
		
	}else if(runmap[now_x][now_y-1]=='0'||runmap[now_x][now_y-1]=='3')//往西
	{
		
		
		runmap[now_x][now_y]='7';
		now_y=now_y-1;
		push(now_x,now_y);
		
		printrunmap(a,b);
		
		
	}else if(runmap[now_x-1][now_y]=='0'||runmap[now_x-1][now_y]=='3')//往北
	{
		
		
		
		runmap[now_x][now_y]='8';
		now_x=now_x-1;
		push(now_x,now_y);
		
		printrunmap(a,b);

	}else
	{
		if(pop(now_x,now_y)==-1){
			break;
		}
		else
		{
		 printrunmap(a,b);
		 printf("此方向找不到出口\n");
		 now_x=stack_x[top];
		 now_y=stack_y[top];
		}
	
	
	}
	 //push(runmap[now_x][now_y]);
	 //printrunmap(a,b);
   
	}
	
	if(now_x==last_x && now_y==last_y)
	{
	    printrunmap(a,b);
		printf("恭喜找到出口!\n");
	  
	}else
	{
		printrunmap(a,b);
		printf("此迷宮找不到出口!\n");
	  
	}
		

}

int main()
{
    FILE *fp1;
    int i,j;
    
	int start_x,start_y;

	
    fp1 = fopen("test1.txt","r");
    if(!fp1)
    {
        printf("File loaded error!\n");
        return 0;
    }
    
 
    fscanf(fp1, "%d,%d\n",&a, &b);
    if(a==0 || b==0)
        return 0;
    for(i=0;i<(a+2);i++)
    {
        for(j=0;j<(b+2);j++)
        {
           fscanf(fp1, " %c", &map[i][j]);
		   runmap[i][j]=map[i][j];

           if(map[i][j]=='2')
           {
               start_x=i;
			   start_y=j;
			   push(start_x,start_y);
           }
		   if(map[i][j]=='3')
           {
               last_x=i;
			   last_y=j;
			   
           }
           
           
        }
    }
    fclose(fp1);
	
	

    for(i=0;i<a+2;i++)
    {
        for(j=0;j<b+2;j++)
        {
           printf("%c ", map[i][j]);
        }
        printf("\n");
    }
	printf("\n");
    
	
	
	for(i=0;i<a;i++){
			 for(j=0;j<b;j++){
								  
								   switch(map[i][j]){
				                             case '1':
         	                                    printf("■ ");
						                        break;
				                             case '0': 
				                                printf("  ");
						                        break;
							                 case '2':
         	                                    printf("A ");
						                        break;
				                             case '3': 
				                                printf("B ");
						                        break;
							

			               
								   }
								     
							   }
							   printf("\n");
	}
	printf("\n");
	//printf("%d %d\n",stack_x[0],stack_y[0]);
    
    run(start_x,start_y);
	
	

}


