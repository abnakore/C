#include <cs50.h>
#include <stdio.h>
#include <string.h>

#include "invoice.h"

int main()
{
    
    // Getting the costomers name of the customer
    printf("Customer's name: ");
    string name = GetString();
    
    // Getting the date
    printf("date (DD/MM/YYYY): ");
    string date = GetString();
    
    // Number of items bougth by the customer
    printf("How many items did %s bought: ", name);
    int no_of_items = GetInt();
    
    
    invoices invoice[no_of_items];
    invoice[1].name = name;
    
    int total = 0;
    // Prompting the user for the items, quantity and prize
    // And calculating the total
    for(int i = 0; i < no_of_items; i++)
    {
        
        printf("Item%d: ", i + 1);
        invoice[i].data.item = GetString();
        printf("Quantity: ");
        invoice[i].data.quantity = GetInt();
        printf("price/unit: ");
        invoice[i].data.prize = GetInt();
        invoice[i].data.total = invoice[i].data.prize * invoice[i].data.quantity;
        total += invoice[i].data.total;
        printf("\n");
    }
          
    printf("\n\t\t\tSALAMA BAKERY INVOICE\n\n");
    printf("Customer's name : %s\t\t\tDate: %s\n", invoice[1].name, date);
    printf("\nS/N\tItems\t\tQuantity\tPrize/unit\tTotal\n");
    for(int i = 0; i < no_of_items; i++)
    {
        printf("%d)\t%s\t\t%d\t\t%d\t\t%d\n", i + 1, invoice[i].data.item, invoice[i].data.quantity, invoice[i].data.prize, invoice[i].data.total);
        
    }
    printf("\t\t\t\t\t\t\t======\n");
    printf("\t\t\t\t\tTotal\t\t%d\n\n", total);
}
