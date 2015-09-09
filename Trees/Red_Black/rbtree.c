#include<stdio.h>
#include<stdlib.h>

#define RED 1
#define BLACK 0

#ifdef DEBUG
#define Q_LOG(format, args...) printf(" %s(%d): "format"\n",__FUNCTION__,__LINE__,##args)
#else 
#define Q_LOG(format, args...) printf(" ")
#endif

#define COLOR(x)  x ? x->rb : BLACK 

#define SWAP(T,a,b) do { T temp = a;  a = b; b = temp; } while(0)

struct tnode 
{
    int value:31;
    unsigned int rb:1;
    struct tnode *parent_ptr;
    struct tnode *left;
    struct tnode *right;
};

//right rotate
void rightrotate(struct tnode **root_d, struct tnode * node)
{
    struct tnode *above = node->parent_ptr;
    struct tnode *between = node->left;
    struct tnode *below = node->left->right;
    Q_LOG("Rotating Right");
    //if above is null means it is root
    if(above ==  NULL) {
        Q_LOG("Above is NULL");
        *root_d = node->left;
    } else {
        if(above->right == node)
            above->right = node->left;
        else
            above->left = node->left;
    }
    node->left->parent_ptr = above;


    //between link
    node->parent_ptr = node -> left;
    node->left ->right = node;

    //below link
    if(below)
    {
        below->parent_ptr = node;
        Q_LOG("Below is NULL");
    }
    node->left = below;

}
// rotate left 
void leftrotate(struct tnode **root_d, struct tnode * node)
{
    struct tnode *above = node->parent_ptr;
    struct tnode *between = node->right;
    struct tnode *below = node->right->left;

    Q_LOG("Rotating Right");
    //if above is null means it is root
    if(above ==  NULL) {
        Q_LOG("Above is NULL");
        *root_d = node->right;
    } else {
        if(above->left == node)
            above->left = node->right;
        else
            above->right = node->right;
    }
    node->right->parent_ptr = above;


    //between link
    node->parent_ptr = node -> right;
    node->right->left = node;

    //below link
    if(below) {
        below->parent_ptr = node;
        Q_LOG("Below is NULL");
    }
    node->right = below;

}


void insertFixup(struct tnode **root_d, struct tnode * current)
{
    Q_LOG("Started");
    if(current == NULL || current->parent_ptr == NULL)
        return;
    struct tnode *parent, *gparent,*uncle;
    if(current->parent_ptr->rb == BLACK)
    {   Q_LOG("Current parent is BLACK parent is %d ",current->parent_ptr->value);
        return;
    }
    
    parent = current->parent_ptr;
    gparent = parent->parent_ptr;
    uncle = (parent == gparent->left) ? gparent->right : gparent->left;
    Q_LOG("Uncle is %d(%d)",uncle ? uncle->value : -1, COLOR(uncle));
    //XYR case
    if(COLOR(uncle) == RED)
    {
        Q_LOG("XYR case");
        uncle->rb = BLACK;
        parent->rb = BLACK;
        gparent->rb = RED;
        insertFixup(root_d, gparent);
        return;
    }

    //XYB case
    // LL case
    // 1. swap parent and   gparent color
    // 2. right rotate gparent
    if(parent == gparent->left && current == parent->left)
    {
        printf("\nCase is LL\n");
        //SWAP(int,parent->rb, gparent->rb);
        gparent ->rb = RED;
        parent ->rb  = BLACK;
        rightrotate(root_d,gparent);
    } 
    //LR case
    //1. left rotate gparent
    //2. right rotate parent
    //3. swap current and grandparent color
    else if (parent == gparent->left && current == parent->right )
    {
        printf("\nCase is LR\n");
        leftrotate(root_d, gparent);
        rightrotate(root_d, parent);
        //SWAP(int,gparent->rb, current->rb);
        gparent ->rb = RED;
        current ->rb  = BLACK;
    }

    //RL case
    //1. right rotate gparent
    //2. left rotate parent
    //3. swap current and gparent color
    else if (parent == gparent-> right && current == parent->left)
    {
        printf("\nCase is RL\n");
        rightrotate(root_d, gparent);
        leftrotate(root_d, parent);
        //SWAP(int ,gparent->rb, current->rb);
        current->rb = BLACK;
        gparent ->rb = RED;

    }
    //RR case
    //1. swap parent and gparent color
    //2. left rotate gparent
    else if(parent == gparent->right && current == parent->right)
    {
        printf("\nCase is RR\n");
        //SWAP(int, parent->rb, gparent->rb);
        leftrotate(root_d, gparent);
        gparent ->rb = RED;
        parent ->rb = BLACK;
    }
    else {
        Q_LOG("parent : %d(%d)",parent->value , parent->rb);
        Q_LOG("gparent : %d(%d)",gparent->value , gparent->rb);
        Q_LOG("Something wrong ");
    }

}
void insert_node(struct tnode **root_d , int val)
{
    struct tnode *n;
    n = (struct tnode *) malloc(sizeof(struct tnode));
    n->value      = val;
    n-> rb        = RED;
    n->parent_ptr = NULL;
    n->left       = NULL;
    n->right      = NULL;

    if(*root_d == NULL) {
        Q_LOG("Initial case");
        *root_d = n;
        n->rb = BLACK;
        return;
    }
    
    struct tnode *temp;
    temp = *root_d;

    n->parent_ptr = temp;

    while(temp) {   
        if(temp->value < val) {
            if(temp -> right == NULL) {
                temp->right = n;
                n->parent_ptr = temp;
                break;
            }
            n->parent_ptr = temp;
            temp = temp->right;
        } else {
            if(temp->left == NULL) {
                temp-> left = n;
                n->parent_ptr = temp;
                break;
            }
            n->parent_ptr = temp;
            temp = temp->left;
        }
    }
    Q_LOG("Parent is %d (%d) ", n->parent_ptr ? n->parent_ptr->value : -1 ,COLOR(n->parent_ptr));
    insertFixup(root_d,n);

    (*root_d)->rb = BLACK;
}

void inorder_print(struct tnode *root)
{
    if(root)
    {
        inorder_print(root->left);
        printf(" %d (%d) --> ",root->value,root->rb);
        inorder_print(root->right);
    }
}

void main()
{
    struct tnode *root = NULL;
    insert_node(&root,50);
    Q_LOG("root is %d(%d)" , root->value ,COLOR(root));
    printf("INorder Print\n");
    inorder_print(root);
    printf("\n\n");
    printf("============================================================================\n");
    insert_node(&root,60);
    Q_LOG("root is %d(%d)" , root->value ,COLOR(root));
    printf("INorder Print\n");
    inorder_print(root);
    printf("\n\n");
    printf("============================================================================\n");
    insert_node(&root,70);
    Q_LOG("root is %d(%d)" , root->value ,COLOR(root));
    printf("INorder Print\n");
    inorder_print(root);
    printf("\n\n");
    printf("============================================================================\n");
    insert_node(&root,80);
    Q_LOG("root is %d(%d)" , root->value ,COLOR(root));
    printf("INorder Print\n");
    inorder_print(root);
    printf("\n\n");
    printf("============================================================================\n");
    insert_node(&root,90);
    Q_LOG("root is %d(%d)" , root->value ,COLOR(root));
    insert_node(&root,750);

    printf("INorder Print\n");
    inorder_print(root);
    printf("\n\n");
    printf("============================================================================\n");
    Q_LOG("root is %d(%d)" , root->value ,COLOR(root));
    printf("Insertion Done\n");
    printf("INorder Print\n");
    inorder_print(root);
    printf("\n");
}

