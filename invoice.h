
typedef struct list
{
    char * item;
    int  quantity;
    int  prize;
    int  total;
}
list;

typedef struct invoices
{
    char * name;
    list data;
}
invoices;
