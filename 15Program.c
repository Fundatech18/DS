#include<stdio.h>
#include<stdlib.h>

struct tree{
    struct tree *lptr;
    int data;
    struct tree *rptr;
};

void insert(struct tree **root,int element){
    struct tree *newNode = (struct tree *)malloc(sizeof(struct tree));
    newNode->data = element;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    struct tree *prev = NULL,*curr = *root;
    
    while(curr != NULL){
        prev = curr;
        if(curr->data >= element){
            curr = curr->lptr;
        }else{
            curr = curr->rptr;
        }
    }
    
    if(prev == NULL){
        *root = newNode;
    }else{
        if(prev->data > element){
            prev->lptr = newNode;
        }else{
            prev->rptr = newNode;
        }
    }
}

void InOrder(struct tree *head){
    struct tree *curr = head;
    
    
    struct tree* stack[100];  // Array used as a stack
    int top = -1;      // Initialize stack pointer

    struct tree* current = head;
    while (current != NULL || top != -1) {
        // Reach the leftmost node of the current node
        while (current != NULL) {
            stack[++top] = current; // Push current node onto the stack
            current = current->lptr;
        }

        // Pop from stack and process it
        current = stack[top--];
        printf("%d ", current->data);

        // Move to the right subtree
        current = current->rptr;
    }
}

void delete(struct tree **root,int element){
    struct tree *parent = NULL,*current = *root;
    
    while(current!=NULL && current->data != element){
        parent = current;
        if(current->data > element){
            current = current->lptr;
        }else{
            current = current->rptr;
        }
    }
    
    if(current == NULL){
        printf("Element not fount\n");
    }else{
        if(current->lptr == NULL && current->rptr == NULL){
            if(parent == NULL){
                *root = NULL;
            }else if(parent->lptr == current){
                parent->lptr = NULL;
            }else{
                parent->rptr = NULL;
            }
            free(current);
        }else if(current->lptr == NULL || current->rptr == NULL){
            struct tree *child = (current->lptr != NULL)?current->lptr : current->rptr;
            if(parent == NULL){
                *root = child;
            }else if(parent->lptr == current){
                parent->lptr = child;
            }else{
                parent->rptr = child;
            }
            free(current);
        }else{
            struct tree *parentSuccessor = current;
            struct tree *successor = current->rptr;
            
            while(successor->lptr != NULL){
                parentSuccessor = successor;
                successor = successor->lptr;
            }
            
            current->data = successor->data;
            
            if(parentSuccessor->lptr == successor){
                parentSuccessor->lptr = successor->rptr;
            }else{
                parentSuccessor->rptr = successor->rptr;
            }
        }
    }
}

void main(){
     struct tree *root=NULL;
    int choice, element;
    
    while(1){
        printf("\nEnter 1 for insert : \n" );
        printf("Enter 2 for Inorder Traverse : \n");
        
        printf("Enter 5 for Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter Element : ");
            scanf("%d",&element);
            insert(&root,element);
            break;
            
            case 2:
            printf("Enter Element : ");
            scanf("%d",&element);
            delete(&root,element);
            break;
            
            case 3:
            printf("Inorder Traverse : ");
            InOrder(root);
            break;
        }
    }
}
