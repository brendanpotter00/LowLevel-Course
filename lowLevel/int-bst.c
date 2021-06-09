//PLEDGE: brendan potter
//this code is entirely my own

#include "int-bst.h"


int_bst_node_t* newNode(int val){
	int_bst_node_t *temp= (int_bst_node_t *)malloc(sizeof(int_bst_node_t));
	temp->data = val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

bool int_bst_find(int_bst_node_t * t, int n){
	if(t== NULL) return false;
	if(t->data == n){
		return true;
	}
	if(t->data > n) return int_bst_find(t->left,n);
	else return int_bst_find(t->right,n);
	
}

bool int_bst_insert(int_bst_node_t ** t_p, int n){
	if(int_bst_find(*t_p,n))return true;
	if(*t_p == NULL){
		*t_p = newNode(n);
		return true;
	}
	else if((*t_p)->data > n) return int_bst_insert(&(*t_p)->left,n);
	else if((*t_p)->data < n) return int_bst_insert(&(*t_p)->right,n);
	else return false;
}

void int_bst_remove(int_bst_node_t ** t_p, int n){
	printf("this function is not complete   :   ");
}

void int_bst_remove_all(int_bst_node_t ** t_p){
	if((*t_p)->left!=NULL) (*t_p)->left=NULL;
	if((*t_p)->right!=NULL) (*t_p)->right=NULL;
	(*t_p)=NULL;
}

void int_bst_print_elements(int_bst_node_t * t, FILE * f, char * fmt){
	if(t!=NULL){
		if(t->left!=NULL){
			int_bst_print_elements(t->left,f,fmt);
		}
		fprintf(f, fmt, t->data);
		if(t->right!=NULL){
			int_bst_print_elements(t->right,f,fmt);
		}
	}
}

void print(int_bst_node_t * t,FILE * f, int level){
	for(int i = 0; i <= level; ++i){
		printf("  ");
	}
	printf("%d\n",t->data);
}
int tabs = 0;
void int_bst_print_as_tree(int_bst_node_t * t, FILE * f){
	int_bst_node_t * rov = t;
	if(rov!=NULL){
		print(rov,f,tabs);
		tabs = tabs+1;
		int_bst_print_as_tree(rov->left,f);
		tabs = tabs-1;
		int_bst_print_as_tree(rov->right,f);
	}
}
