#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>
typedef int value_t;
#include "sorted_list.h"



/* Main function of the program*/
int main( int argc, char *argv[] )  
{  
    /* initilizing head and head_sort for the linked list */
    Sorted_list * list_detail=(Sorted_list *)malloc(sizeof(Sorted_list));
    list_detail->head=NULL;
    list_detail->head_sort=NULL;
    list_detail->tails=NULL;
    list_detail->tails_sort=NULL;
    int i = 0;    
    char chunk[50];
    char commands[50][50];
    size_t malloc_size = 100;
    value_t value;
    key_t key;
    int j = 0;
    int k = 0;
    char *a;

    if(argc == 1){
    	printf("input commands. press ctrl+D to stop entering inputs\n");
	char *input_string;
                size_t input_string_length = 50;
                input_string = (char *) malloc(input_string_length);

                while(getline(&input_string, &input_string_length, stdin) != -1)
                {
                        input_string[strcspn(input_string, "\n")] = 0;
			strcpy(commands[i], input_string);
			i++;
		}
    }

    else if(argc > 2){
    	printf("Too many arguments supplied");
    }
    else{
        FILE *fp;
	fp = fopen(argv[1],"r");

	while(fgets(commands[i],50, fp) != NULL) {
	        commands[i][strlen(commands[i]) -1] = '\0';
		i++;
	}
    }

    while(j<i){
	a = commands[j];
		if(strcmp(a,"rem_first")==0){
			remove_first(list_detail, &value, &key);
			printf("rem_first:  %d %d \n", key, value);
		}
		else if(strcmp(a,"rem_last")==0){
			remove_last(list_detail, &value, &key);
			printf("rem_last:   %d %d \n", key, value);

		}
		else if(strcmp(a,"rem_small")==0){
			remove_smallest_key(list_detail,&value,&key);
			printf("rem_small:  %d %d\n", key, value);
		}
		else if(strcmp(a,"rem_large")==0){
			remove_largest_key(list_detail,&value,&key);
			printf("rem_large:  %d %d\n", key, value);
		}
		else if(strcmp(a,"print_all")==0){
			printList(list_detail);
		}
		else if(strcmp(a,"print_sort")==0){
			printList_sort(list_detail);
		}
	
		else if((a[0] == 'p')){
			int tempk, tempv;
			char *s;
			s = a;
			char *p = strtok(a," ");
			p = strtok(NULL, " ");
			sscanf(p, "%d", &tempk);
			p = strtok(NULL, " ");
			sscanf(p, "%d", &tempv);
			printf("p:          %d  %d\n",tempk, tempv);
			push(list_detail, tempv, tempk);
		}

		else if((a[0] == 'a')){
			int tempk, tempv;
			char *s;
			s = a;
			char *p = strtok(s," ");
			p = strtok(NULL, " ");
			sscanf(p, "%d", &tempk);
			p = strtok(NULL, " ");
			sscanf(p, "%d", &tempv);
			printf("a:          %d  %d\n",tempk, tempv);
			append(list_detail, tempv, tempk);
		}

		else if(strcmp(a, "size")==0){
			int sz = size(list_detail);
			printf("size:       List size = %d\n", list_detail->size);
		}

		else if(strcmp(a, "empty")==0){
			empty_list(list_detail);
			printf("empty:      size = %d\n", list_detail->size);

		}
	j++;
    }
	
    destroy_list(list_detail);

    destroy_list(list_detail);

    getchar();  
    return 0;  
}  
