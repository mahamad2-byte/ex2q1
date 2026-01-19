#include <stdio.h>
int main (void) {
    /* Prices and quantities of products*/

   const float apple_price= 5.99;
   const float carrot_price= 3.99;
   const float chips_price=2.99;
   const float candy_price= 1.50;

   const float apple_quantity = 7.2;
   const float carrot_quantity = 4.1;
   const int chips_quantity = 9;
   const int candy_quantity = 3;
   const float tax_rate = 0.05;


   /*User Input*/

   float apples = 0.0;
   float carrots = 0.0;
   int chips = 0;
   int candy = 0;

   printf("Apple    (7.2kg):    ");
   if(scanf("%f", &apples) !=1 ||apples < 0 || apples > apple_quantity) {
    return 1;

   }
   
   printf("Carrots  (4.1kg):    ");
   if (scanf("%f", &carrots) !=1 || carrots < 0 || carrots > carrot_quantity) {
    return 1;

   }
   printf("Chips   (9 units):   "); 
   if(scanf("%d", &chips) !=1|| chips < 0 || chips > chips_quantity) {
    return 1;
   }
   printf("Candy    (1.50 units):");
   if(scanf("%d", &candy) != 1 || candy < 0 || candy > candy_quantity) {
    return 1;
   }

   /* Cost Calculations*/

   float apple_cost = apples * apple_price;
   float carrot_cost = carrots * carrot_price;
   float chips_cost = chips * chips_price;
   float candy_cost = candy * candy_price;

   float apple_discount = 0.0;
   float carrot_discount = 0.0;
   float chips_discount = 0.0;
   float candy_discount = 0.0;

  
   /*Promotion: Buy 2 chips and get 1 candy 50% discount*/
   if (chips >= 2) {
    if (candy >= 1){
        candy_discount = candy_price * 0.5;
    }
   }

    float apple_total = apple_cost - apple_discount;
    float carrot_total = carrot_cost - carrot_discount;
    float chip_total = chips_cost - chips_discount;
    float candy_total = candy_cost - candy_discount;

   /* Print the rceipt */
 
    printf("-------------------------------------------------------------------\n");
    printf("| Item     | Quantity     | Cost       | Discount    | Total      |\n");

    if (apples > 0) {
        printf("| Apples  | %-8.2f   kg | $ %8.2f | -$ %8.2f | $ %8.2f |\n",
               apples, apple_cost, apple_discount, apple_total);
    }

    if (carrots > 0) {
        printf("| Carrots | %-8.2f   kg | $ %8.2f | -$ %8.2f | $ %8.2f |\n",
               carrots, carrot_cost, carrot_discount, carrot_total);
    }

    if (chips > 0) {
        printf("| Chips    | %-12d | $ %8.2f | -$ %8.2f | $ %8.2f |\n",
               chips,chips_cost,chips_discount, chip_total);
    }

    if (candy > 0) {
        printf("| Candy    | %-12d | $ %8.2f | -$ %8.2f | $ %8.2f |\n",
               candy, candy_cost, candy_discount, candy_total);
    }

    printf("-------------------------------------------------------------------\n");

    /*Subtotal*/
    float subtotal = apple_total + carrot_total + chip_total + candy_total;
    float buyer_discount = 0.0;
    /* Buy at least 1 of everything and get 10% off  */

    if (apples >= 1.0 && carrots >= 1.0 && chips >= 1 && candy >= 1) {
        buyer_discount = subtotal * 0.10;
    }
    float final_subtotal = subtotal - buyer_discount;
    float tax = final_subtotal * tax_rate;
    float total = final_subtotal + tax;

    if (buyer_discount > 0.0) {
        printf("Subtotal    : $%.2f - $%.2f = $%.2f\n",
             subtotal, buyer_discount, final_subtotal);

    } else{
        printf("Subtotal    : $%.2f\n", subtotal);
    }
    printf(" Tax (5%%)      : $%.2f\n", tax);
    printf("---------------------------------------------------------------------------------\n");
    printf("Total           : $%.2f\n", total);
    
    return 0;
   
}
