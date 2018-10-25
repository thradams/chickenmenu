/*
*/

#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

struct MenuItem
{
  int number;
  int price;
  bool bUsed;
};

#define SIZE 40
struct MenuItem Menu[SIZE] = {
{4, 455},
{5, 570},
{6, 680},
{7, 795},
{8, 910},
{9, 1020},
{10, 1135},
{11, 1250},
{12, 1360 },
{13 ,1475 },
{14 ,1590 },
{15 , 1700},
{16 , 1815},
{17 , 1930},
{18 , 2040},
{19 , 2155},
{20 , 2270},
{21 , 2380},
{22 , 2495},
{23 , 2610},
{24 , 2725},
{25 , 2780},
{26 , 2895},
{27 , 3010},
{28 , 3120},
{29 , 3235},
{30 , 3350},
{35 , 3915},
{40 , 4480},
{45 , 5050},
{50 , 5560},
{60 , 6700},
{70 , 7830},
{75 , 8345},
{80 , 8910},
{90 , 10045},
{100 , 11125},
{125 , 13900},
{150 , 16685},
{200 , 22250}
};




bool BuyOneMore(int* bestPrice, int currentCost, int remaning, int *buy, int buycount)
{
  bool result = false;
  for (int i = 0; i < SIZE; i++)
  {
    if (Menu[i].number > remaning)
    {
      break;
    }
    else if (Menu[i].number == remaning)
    {
      currentCost += Menu[i].price;

      if (*bestPrice > currentCost)
      {
        *bestPrice = currentCost;
        printf("*");
      }
      else
      {
        printf(" ");
      }

      buy[buycount] = i;
      printf("Total = %d [", currentCost);
      for (int j = buycount; j >= 0; j--)
      {
        printf(" %d", Menu[buy[j]].number);
      }
      printf(" ]\n");
      result = true;
      break;
    }
    else
    {
      buy[buycount] = i;
      BuyOneMore(bestPrice, currentCost + Menu[i].price, remaning - Menu[i].number, buy, buycount + 1);
    }

  }
  return result;
}

bool Buy(int N)
{
  int buy[100] = { 0 };
  int buycount = 0;
  int remaning = N;
  int bestPrice = INT_MAX;
  int currentCost = 0;
  return BuyOneMore(&bestPrice, currentCost, remaning, buy, buycount);
}

int main()
{
  int N = 0;
  printf("How many chickens do you want to buy? ");
  scanf("%d", &N);

  printf("you can buy.. (* best prices see botton to up)\n\n");

  if (!Buy(N))
  {
    printf("no match");
  }
}
