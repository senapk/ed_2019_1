#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
    int value;
    struct _Node * next;
} Node;

void criar_novo(int ** p){ //&p 300
                          //p  700
    **p = 3;
    *p = (int *) malloc(sizeof(int)); //600

}

void fn(){
    int a = 9; //700
    int * p = &a; //500
    print(p) //700
    print(&p) //500
    print(*p) //9
    criar_novo(&p);

}




bool equals(Node * head1, Node * head2){
    while(true){
        if((head1 == NULL) && (head2 == NULL)){
            return true;
        }
        if((head1 != NULL && head2 == NULL) || (head1 == NULL && head2 != NULL) ){
            return false;
        }

        if(head1->value != head2->value){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return false;
}

Node * node_create(int value){
    Node * node =  (Node *) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void node_destroy(Node * node){
    free(node);
}

typedef struct _List{
    Node * head;
} List;

/* 
List * list_clone(List * list){

}
*/
/* 
List * list_sorted_add(List * list, int value){

}

*/
List * list_create(){
    List * list = (List *) malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void list_destroy(List * list){
    Node * node = list->head;
    while(node != NULL){
        Node * aux = node->next;
        free(node);
        node = aux;
    }
    free(list);
}

void list_push_front(List * list, int value){
    if(list->head == NULL){
        list->head = node_create(value);
        return;
    }
    Node * node = node_create(value);
    node->next = list->head;
    list->head = node;
}

void list_pop_front(List * list){
    if(list->head == NULL)
        return;
    if(list->head->next == NULL){
        node_destroy(list->head);
        list->head = NULL;
        return;
    }
    Node * aux = list->head;
    list->head = list->head->next;
    node_destroy(aux);
}

//return : quem ficou no seu lugar
Node * node_pop_back_r(Node * node){
    if(node == NULL)
        return NULL;
    if(node->next == NULL){
        node_destroy(node);
        return NULL;
    }
    node->next = node_pop_back_r(node->next);
    return node;
}

void list_pop_back_r(List * list){
    list->head = node_pop_back_r(list->head);
}

void list_pop_back(List * list){
    if(list->head == NULL){
        return;
    }
    if (list->head->next == NULL){
        node_destroy(list->head);
        list->head = NULL;
        return;
    }
    Node * node = list->head;
    while(node->next->next != NULL){
        node = node->next;
    }
    node_destroy(node->next);
    node->next = NULL;
}


Node * node_remove_r(Node * node, int value){
    if(node == NULL)
        return NULL;
    if(node->value == value){
        Node * aux = node->next;
        node_destroy(node);
        return aux;
    }
    node->next = node_remove_r(node->next, value);
    return node;
}


Node * node_remove_r(Node ** elo, int value){
    if(*elo == NULL)
        return NULL;
    if((*elo)->value == value){
        Node * aux = (*elo)->next;
        node_destroy(*elo);
    }
    node_remove_r(&(node->next), value);
}

bool list_remove_r(List * list, int value){
    list->head = node_remove_r(list->head, value);
}




bool list_remove_r(List * list, int value){
    list->head = node_remove_r(list->head, value);
}

bool list_remove(List * list, int value){
    if(list->head == NULL){
        return;
    }
    if(list->head->value == value){
        Node * aux = list->head;
        list->head = list->head->next;    
        node_destroy(aux);
        return;
    }
    Node * node = list->head;
    while(node->next != NULL && node->next->value != value){
        node = node->next;
    }
    if(node->next != NULL){
        Node * aux = node->next;
        node->next = node->next->next;
        node_destroy(aux);
    }
}

void list_push_back(List * list, int value){
    if(list->head == NULL){
        list->head = node_create(value);
        return;
    }
    Node * node = list->head;
    while(node->next != NULL){
        node = node->next;
    }
    node->next = node_create(value);
}

void list_show(List * list){
    Node * node = list->head;
    printf("[ ");
    while(node != NULL){
        printf("%d ", node->value);
        node = node->next;
    }
    printf("]\n");
}

void _list_rshow(Node * node){
    if(node == NULL)
        return;
    _list_rshow(node->next);
    printf("%d ", node->value);
}

void list_rshow(List * list){
    printf("[ ");
    _list_rshow(list->head);
    printf("]\n");
}

int main(){
    int values[] = {1, 3, 2, 5, 4, 7, 6, 9, 8};
    int size = sizeof(values) / sizeof(int);
    List * list = list_create();
    for(int i = 0; i < size; i++)
        list_push_back(list, values[i]);
    list_show(list);
    list_rshow(list);
}