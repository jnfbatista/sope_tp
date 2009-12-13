#include "freq_cmds.h"

void freq_count(char txt[], int letters[]) {
	int i = 0;
	int c;

	while(txt[i] != 0) {
		c = (int)txt[i];
		if (c > 64) {
			if(c < 91) {
				letters[c-65]++;
				//printf("%d - %c\n", c, txt[i]);
			} else if (c > 96) {
				if (c < 123) {
					letters[c-97]++;
					//printf("%d - %c\n", c, txt[i]);
				}

			}
		}
		i++;
	}
} 


void freq_display(int letters[]) {
	int fd, i =0, l_size = 26;
	int nchars;
	char buffer[5];
	char end[5] = "end\n";

	fd = open("/tmp/sosh.results", O_WRONLY);
	if (fd != -1) {
		while(i < l_size) {
			nchars = sprintf(buffer, "%c-%d\n", i+97, letters[i]);
			write(fd, buffer,nchars);
			i++;
		}
		write(fd, end,5);
	}
	close(fd);
}

void freq_sort(int letters[] ) {	

}

