#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void optimalPage(int pg[], int n, int size)
{
	int fr[size];
	memset(fr, -1, sizeof(fr));
	int hit = 0;
	for (int i = 0; i < n; i++){
    	bool found = false;
    	for (int j = 0; j < size; j++){
        	if (fr[j] == pg[i]){
            	hit++;
            	found = true;
            	break;
        	}
    	}
    	if (found)
        		continue;
    	bool emptyFrame = false;
    	for (int j = 0; j < size; j++){
        	if (fr[j] == -1){
            	fr[j] = pg[i];
            	emptyFrame = true;
            	break;
        	}
    	}
    	if (emptyFrame)
        		continue;
    	int farthest = -1, replaceIndex = -1;
    	for (int j = 0; j < size; j++){
        	int k;
        	for (k = i + 1; k < n; k++){
            	if (fr[j] == pg[k]){
                	if (k > farthest){
                    	farthest = k;
                    	replaceIndex = j;
                	}
                	break;
            	}
        	}
        	if (k == n){
            	replaceIndex = j;
            	break;
        	}
    	}
    	fr[replaceIndex] = pg[i];
	}
	printf("No. of hits = %d\n", hit);
	printf("No. of misses = %d\n", n - hit);
}
int main(){
	int n, size;
	printf("Enter the number of pages: ");
	scanf("%d", &n);
	int pg[n];
	printf("Enter the page numbers: ");
	for (int i = 0; i < n; i++){
    		scanf("%d", &pg[i]);
	}
	printf("Enter the size: ");
	scanf("%d", &size);
	optimalPage(pg, n, size);
	return 0;
}
