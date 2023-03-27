#include <stdlib.h>
#include "structures.h"

node_t *new_node(unsigned short dstid, unsigned char hod)
{
	node_t *node = (node_t *)malloc(sizeof(node_t));
	if (node == NULL) {
		perror("CREATE_NODE: NULL POINTER NODE\n");
		exit(EXIT_FAILURE);
	}

	node->dstid = dstid;
	node->hod = hod;
	return node;
}

void free_list(node_t *head)
{
	while (head != NULL) {
		node_t *next_node = head->next;
		free(next_node);

		head = head->next;
	}
}

node_t *push(node_t *head, node_t *node)
{
	node_t *curr_node = head;
	while (curr_node->next != NULL) {
		curr_node = curr_node->next;
	}
	curr_node->next = node;
	return curr_node;
}

hash_t *new_hash()
{
	hash_t *ptr_hash = (hash_t *)malloc(sizeof(hash_t));
	if (ptr_hash == NULL) {
		perror("CREATE_HASH: NULL POINTER");
		exit(EXIT_FAILURE);
	}

	return ptr_hash;
}

int insert(hash_t *ptr_hash, int srcid, node_t *node)
{
	const int index = srcid - 1;
	node_t *head_list = ptr_hash->headers_list[index];
	push(head_list, node);

	return index;
}
