#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, head, total_seek = 0;
    
	printf("Enter number of disk requests: ");
	scanf("%d", &n);

	int requests[n];
	printf("Enter the sequence: ");
	for (i = 0; i < n; ++i) {
    	scanf("%d", &requests[i]);
	}

	printf("Enter initial head position: ");
	scanf("%d", &head);

	printf("Seek Sequence: %d", head);

	for (i = 0; i < n; ++i) {
    	total_seek += abs(head - requests[i]);
    	printf(" -> %d", requests[i]);
    	head = requests[i];
	}

	printf("\nTotal number of seeks: %d\n", total_seek);
	return 0;
}
