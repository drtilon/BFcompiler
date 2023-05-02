#include <stdio.h>

/*
> = increases memory pointer, or moves the pointer to the right 1 block.
< = decreases memory pointer, or moves the pointer to the left 1 block.
+ = increases value stored at the block pointed to by the memory pointer
- = decreases value stored at the block pointed to by the memory pointer
[ = like c while(cur_block_value != 0) loop.
] = if block currently pointed to's value is not zero, jump back to [
, = like c getchar(). input 1 character.
. = like c putchar(). print 1 character to the console
*/

#define len 2000

int main()
{
   FILE *hello = fopen("hello.bf", "r");
   char array[len];
   char save[len];
   int p, openr, cnt_paren = 0;
   int inst_p = 0;
   char c;
   for (int i = 0; (c = fgetc(hello)) != EOF; i++)
   {
      // printf("%d\n", i);
      save[i] = c;
   }

   while (1)
   {
      printf("%c\n", save[inst_p]);
      switch (save[inst_p])
      {
      case '>':
         p++;
         if (p == len - 1)
         {
            p = 0;
         }
         break;

      case '<':
         p--;
         if (p == 0)
         {
            p = len;
         }
         break;

      case '+':
         array[p]++;
         break;

      case '-':
         array[p]--;
         break;

      case '.':
         putchar(array[p]);
         break;

      case ',':
         array[p] = getchar();
         break;

      case '[':
         cnt_paren++;
         openr = inst_p;
         if (array[p] == 0)
         {
            while (save[inst_p] != ']')
            {
               inst_p++;
            }
         }
         break;

      case ']':

         if (array[p] != 0)
         {
            inst_p = openr;
         }
         break;

      default:
         break;
      }
      inst_p++;
   }
   return 0;
}
