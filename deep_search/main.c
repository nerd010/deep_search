//
//  main.c
//  deep_search
//
//  Created by Charles Wang on 16/3/24.
//  Copyright © 2016年 CHW. All rights reserved.
//

#include <stdio.h>

int a[10],book[10],n;

void dfs (int step);

int main(void)
{
    
    printf("请输出 1 ~ 9 之间的数字：\n");
    scanf("%d", &n);
    dfs(1);
    getchar();getchar();
    
    return 0;
}

void dfs (int step)
{
    //表示前 N 个盒子已经放好扑克牌
    if (step == n + 1)
    {
        //输出一种排列（1 ~ n 号盒子中的扑克牌编号）
        for (int j = 1; j <= n; j++)
        {
            printf("%d", a[j]);
        }
        printf("\n");
        
        return; //最后一次调用dfs函数的地方
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (book[i] == 0)
        {
            a[step] = i;
            book[i] = 1;
            
            //下一步
            dfs(step + 1);//递归
            book[i] = 0;
        }
    }
    
    return;
}