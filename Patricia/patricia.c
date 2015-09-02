#include<stdio.h>
#include<stdlib.h>

#define QLOG(format, args...) printf(" %s(%d): "format"\n",__FUNCTION__,__LINE__,##args)
struct pnode {
    int value;
    int bit;
    struct pnode *left;
    struct pnode *right;
};
static struct pnode *header;

int find_firstbit_diffrence(int x, int y)
{
    int temp,pos;
    temp = x ^ y;
    pos=0;
    while(!(1<<pos & temp))  
        pos++;
    return pos;
}

struct pnode * newnode(int val)
{
    struct pnode *p;
    p = (struct pnode *) malloc(sizeof(struct pnode));
    p->value = val;
    p->bit   = -1;
    p->left = p->right = p;

    return p;
}
void insert(int x)
{
    QLOG("Inserting %d",x);
    struct pnode *p = newnode(x);
    int dir,prev_bit, bit_field;
    if(header == NULL)
    {
        QLOG("Initial case");
        header = p;
        header->left = header;
        header->right = header;
        return;
    }
    //second node
    if(header ->left == header)
    {
        QLOG("Case 2");
        header->left = p;
        p->bit = 0;
        if(x & 1 ) {
            p->left = header;
        } else {
            p->right = header;
        }
        return;
    }

    //search for node and find bit position
    struct pnode *pt = header->left;
    prev_bit = -1;
    while(1)
    { 
       QLOG("prev_bit %d new bit %d",prev_bit,pt->bit);
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
    
        //find the diffrence in bit pos for direction
        dir  = x & (1<<pt->bit);
        QLOG("Movin in direction %d ",dir);
        //cache the prev bit before moving ahead
        prev_bit = pt->bit;
        if(dir == 0)
            pt = pt->left;
        else
            pt = pt->right;
    }


    p->bit = find_firstbit_diffrence(pt->value , x);
    QLOG("Setting bit to (pt->value= %d, x =%d :  %d",pt->value,x,p->bit);
    
    
    pt = header->left;
    prev_bit = -1;
    while(1)
    {
        QLOG("prev_bit %d new bit %d",prev_bit,pt->bit);
        
        //find the diffrence in bit pos for direction
        dir  = x & (1<<pt->bit);

        QLOG("Movin in direction %d ",dir);
        QLOG("About pt value = %d , bit = %d, left->bit = %d, right->bit = %d, left->value = %d, right->vlaue = %d",
            pt->value,pt->bit, pt->left->bit, pt->right->bit, pt->left->value, pt->right->value);
        if(dir == 0)
        {   
                        
            if((pt->left->bit > p->bit)||(prev_bit >= pt->left->bit))
            {
                QLOG("Inside If");
                break;
            }
            //cache the prev bit before moving ahead
            prev_bit = pt->bit;
            pt = pt->left;
        }
        else
        {
            if((pt->right->bit > p->bit)||(prev_bit >= pt->right->bit))
                break;
            //cache the prev bit before moving ahead
            prev_bit = pt->bit;
            pt = pt->right;
        }
    }
    
    //Now we have dir pointing to insert in left or right
    //pt as prev node
    // p as node to insert
    //p-> bit as bit value we are comparing

    //first set left and right pointers for p
    QLOG("Prev node %d ",pt->value);
    if(p->value & 1<<pt->bit)    //change right pointer
    {    QLOG("Changing right pointers of %d",pt->value);
         if(p->value & 1<<p->bit) {
            p->left = pt->right;
            QLOG("Changing left pointers of %d",p->value);
         } else {
            p->right = pt->right;
            QLOG("Changing right pointers of %d",p->value);
         }
         pt->right = p;
    }
    else 
    {   QLOG("Changing left pointers of %d",pt->value);
        if(p->value & 1<< p->bit) {
            p->left = pt->left;
            QLOG("Changing left pointers of %d",p->value);
        } else { 
            p->right = pt->left;
            QLOG("Changing right pointers of %d",p->value);
        }
        pt->left = p;
    }
    
}

void delete_node(int x)
{
    int dir;
    struct pnode *current,*parent = NULL ,*gparent;
    struct pnode *pt = header->left;
    int prev_bit = -1; 
    while(1)
    {

        if(prev_bit >= pt->bit)
        {
            if(pt->value == x)
            {
                QLOG("Parent is %d to be deleted %d",parent->value,pt->value);
                //now we have to delete it 
                current = pt;
                break;
            }
            else 
            {
                printf("Not found \n");
                return;
            }
        }
        //find the diffrence in bit pos for direction
        dir  = x & (1<<pt->bit);
        //cache the prev bit before moving ahead
        prev_bit = pt->bit;
        parent  = pt;

        if(dir == 0)
            pt = pt->left;
        else
            pt = pt->right;
    }
    
    //we have now current and parent
    //now search again and stop befor that bit pos of parent
    
    prev_bit = -1;
    gparent = header;
    pt = header->left;
    QLOG("Starting from left parent->bit : %d",parent->bit);
    while(1)
    {
        QLOG("Node is %d",pt->value);
        //find the diffrence in bit pos for direction
        dir  = x & (1<<pt->bit);
        //cache the prev bit before moving ahead
        prev_bit = pt->bit;
        QLOG("Moving in direction %d",dir);
        QLOG("Prevvious bit for comparison : %d",prev_bit);
        if(dir == 0)
        {   QLOG("Bit of left one is %d",pt->left->bit);
            if((pt->left->bit <=  prev_bit)||(parent->bit <= pt->left->bit))
                break;
            pt = pt->left;
        }
        else
        {
           QLOG("Bit of right one is %d",pt->right->bit);
            if((pt->right->bit <= prev_bit)||(parent->bit <= pt->right->bit))
                break;
            pt = pt->right;
        }

    }
    gparent = pt;

    QLOG("Gparent is %d",pt->value);
    //now copy data 
    current->value = parent->value;
    if(gparent->left == parent) {
        gparent->left = current;        
    } else {
        gparent->right = current;
    }

    free(parent);
    parent = NULL;
}
void inorder(struct pnode *node,int bit)
{
    if(node->bit <= bit) { 
        printf("  -> %d (%d)",node->value,node->bit);
        return;
    }
    inorder(node->left,node->bit);
    inorder(node->right,node->bit);
    
}

void display()
{
    if(header == NULL)
        return;
    printf("\nPrinting Paricia\n");
    inorder(header->left,-1);
    printf("\n");
}
int main()
{
    printf("\nInserting %d\n",10);
    insert(10);
    display();
    printf("\nInserting %d\n",3);
    insert(3);
    display();
    printf("\nInserting %d\n",6);
    insert(6);
    display();
    printf("\nInserting %d\n",2);
    insert(2);
    display();
    printf("\nInserting %d\n",5);
    insert(5);
    printf("\nInserting %d\n",8);
    insert(8);
    printf("\nInserting %d\n",1);
    insert(1);
    printf("\nInserting %d\n",12);
    insert(12);
    display();

  int x ;
  scanf("%d",&x);
   printf("\nDeleting %d\n",x);
   delete_node(x);
    display();
   /* printf("\nDeleting %d\n",10);
    delete_node(10);
    display();
    printf("\nDeleting %d\n",6);
    delete_node(6);
    display();
    printf("\nDeleting %d\n",3);
    delete_node(3);
    display();
    */
    return 0;
}

    




