#include<stdio.h>
#include<stdlib.h>

struct pnode {
    int value;
    int bit;
    struct pnode *left;
    struct pnode *right;
};
static struct pnode *header;

int find_firstbit_diffrence(x,y)
{
    int temp = x ^ y;
    int pos=0;
    while(1<<pos & temp) pos++;

    return pos;
}

struct pnode * newnode(int val)
{
    struct pnode *p;
    p = (struct pnode *) malloc(sizeof(struct pnode));
    p->value = val;
    p->bit   = 0;
    p->left = p->right = p;

    return p;
}
void insert(int x)
{
    struct pnode *p = newnode(x);
    int dir,prev_bit, bit_field;
    if(header == NULL)
    {
        header = p;
        header->left = header;
        header->right = header;
        return;
    }

    //search for node and find bit position
    struct pnode *pt = header->left;
    prev_bit = 0;
    while(1)
    {    
        //find the diffrence in bit pos for direction
        dir  = x & (1<<pt->bit);
        //cache the prev bit before moving ahead
        prev_bit = pt->bit;

        if(dir == 0)
            pt = pt->left;
        else
            pt = pt->right;

        if(prev_bit >= pt->bit)
        {
            if(pt->value == x)
            {
                free(p);
                printf("\n Found the element\n");
                return; //already there;
            }
            break;
        }
    }
    
    p->bit = find_firstbit_diffrence(pt->value , x);
    
    while(1)
    {
        //find the diffrence in bit pos for direction
        dir  = x & (1<<pt->bit);
        //cache the prev bit before moving ahead
        prev_bit = pt->bit;

        if(dir == 0)
        {   if(pt->left->bit >= p->bit)
                break;
            pt = pt->left;
        }
        else
        {
            if(pt->right->bit >= p->bit)
                break;
            pt = pt->right;
        }

        if(prev_bit == pt->bit)
            break;
    }
    
    //Now we have dir pointing to insert in left or right
    //pt as prev node
    // p as node to insert
    //p-> bit as bit value we are comparing

    //first set left and right pointers for p
    if(p->value & 1<<p->bit)    //change right pointer
    {    p->right = pt->right;
         pt->right = p;
    }
    else 
    {
        p->left = pt->left;
        pt->left = p;
    }
    
}

void main()
{
    insert(10);
    insert(30);
    insert(60);
    insert(20);
    insert(30);
}

    




