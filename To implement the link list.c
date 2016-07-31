/*Program to implement linked list with the function to delete the
first node along with the logic to check the underflow condition. 
Name: Raju Shrestha (522)
Date: 31 July 2016
Reference: Data Structure Book Page 189 and 192
*/
 
 #include <stdio.h>
 #include <conio.h>
 #include <stdlib.h>
 
 struct node {
 	int info;
 	struct node *next;
 };
 
 typedef struct node *nodeptr;
 nodeptr getnode();
 void freenode(nodeptr);
 void insertatfirst(nodeptr *, int);
 int deletefromfirst(nodeptr *);
 void displaylist(nodeptr);
 int check_underflow(nodeptr *);
 
 int main () {
 	nodeptr list;
 	list = NULL;
 	insertatfirst(&list, 3);
 	insertatfirst(&list, 4);
 	insertatfirst(&list, 5);
 	insertatfirst(&list, 6);
 	insertatfirst(&list, 7);
 	
 	displaylist(list);
 	printf ("Deleted = %d \n", deletefromfirst(&list));
 	printf ("Deleted = %d \n", deletefromfirst(&list));
 	printf ("Deleted = %d \n", deletefromfirst(&list));
 	printf ("Deleted = %d \n", deletefromfirst(&list));
 	printf ("Deleted = %d \n", deletefromfirst(&list));
 	printf ("Deleted = %d \n", deletefromfirst(&list));

 	getch();
 	return 0;
 }
 
 nodeptr getnode() {
 	return (nodeptr)malloc(sizeof(struct node));
 }
 
 void freenode(nodeptr p) {
 	free (p);
 }
 
 void insertatfirst(nodeptr *p, int x) {
 	nodeptr q;
 	q = getnode();
 	q->info = x;
 	q->next = *p;
 	*p = q;
 }
 
 void displaylist(nodeptr p) {
 	nodeptr ptr = p;
 	while(ptr != NULL) {
		printf ("%d \n", ptr->info);
 ptr = ptr->next;
 	}
 }
int deletefromfirst (nodeptr *p) {
	if (check_underflow(p)) {
 		printf ("\n Linked List Underflow \n");
		getch();
 		exit(1);
	  } 
	else {
		int x;
		nodeptr q;
 		q = *p;
 		*p = q->next;
 		x = q->info;
 		return x;
 		freenode(q);
 	}
 }
 
 int check_underflow(nodeptr *p){
 	return (*p == NULL);
 }
