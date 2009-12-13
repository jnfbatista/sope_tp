#include <stdio.h>

void freq_count(char txt[], int letters[]) {
	int i = 0;
	int c;

	while(txt[i] != 0) {
		c = (int)txt[i];
		if (c > 64) {
			if(c < 91) {
				letters[c-65]++;
				printf("%d - %c\n", c, txt[i]);
			} else if (c > 96) {
				if (c < 123) {
					letters[c-97]++;
					printf("%d - %c\n", c, txt[i]);
				}

			}
		}
		i++;
	}
} 


void freq_diplay(int letters[]) {
	int i =0, l_size = 24;
	while(i < l_size) {
		printf("%c\t%d\n", i+97, letters[i]);
		i++;
	}
}

void freq_sort(int letters[] ) {	

}

