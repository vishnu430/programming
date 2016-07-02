#include <stdio.h>
#include <stdlib.h>
struct list {
	int num;
	struct list *next;
};
// Preparing list ascending order
add_node(struct list **head, int data)
{
	struct list *node = NULL;
	struct list *tmpnode = *head, *tmpprev;
	node = (struct list *)calloc(sizeof(struct list), 1);
	node->num = data;
	if(*head == NULL) {				// First node
		*head = node;
	} else if(data <= (*head)->num){ 		// Node num <= head num
		node->next = *head;
		*head = node;
	}else {						// Adding proper position
		tmpprev = tmpnode;
		tmpnode = (*head)->next;
		while(tmpnode)
		{
			if(data < tmpnode->num)
				break;
			tmpprev = tmpnode;
			tmpnode = tmpnode->next;
		}
		node->next = tmpnode;
		tmpprev->next = node;
	}

}

// Deleting a first occurence of node from list
int del_node(struct list **head, int data)
{
	struct list *prev, *curr, *next;
	if(*head == NULL) {
		printf("No list present\n");
		return;
	}

	curr = *head;
	if(data == (*head)->num) {			// deleting if it is head
		(*head) = (*head)->next;
		free(curr);
	}else{
		while(curr && (data != curr->num))	// Searching for node to be deleted
		{
			prev = curr;
			curr = curr->next;
		}
		if(curr) {				// removing node from list and deallocating memory
			prev->next = curr->next;
			free(curr);
		} else {
			printf("No data found\n");	// not present in the list
			return;
		}
	}

}
// printing list
print_list(struct list *node)
{
	while(node)
	{
		printf("%d ", node->num);
		node = node->next;
	}
	printf("\n");

}
int main()
{
	struct list *head = NULL;
	add_node(&head, 5);
	add_node(&head, 4);
	add_node(&head, 3);
	add_node(&head, 2);
	add_node(&head, 8);
	add_node(&head, 7);
	add_node(&head, 6);
	add_node(&head, 6);
	add_node(&head, 6);
	print_list(head);

	printf("Deleting 2\n");
	del_node(&head, 2);
	print_list(head);

	printf("Deleting 2\n");
	del_node(&head, 2);
	print_list(head);

	printf("Deleting 10\n");
	del_node(&head, 10);
	print_list(head);

	printf("Deleting 6\n");
	del_node(&head, 6);
	print_list(head);

	printf("Deleting 8\n");
	del_node(&head, 8);
	print_list(head);

}
