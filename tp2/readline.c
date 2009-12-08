/**
 * readline.c
 */
ssize_t readline(int fd,void * vptr, size_t maxlen){
	ssize_tn,rc;
	char c, *ptr;
	ptr = vptr;
	for(n=1; n<maxlen; n++){
		if((rc=read(fd,&c,1))==1){
			*ptr++= c;
			if(c=='\n')
				break;
		} else if(rc==0){
			if(n==1)
				return(0);
			/*EOF,nodataread*/
			else
				break;
			/*EOF,somedatawasread*/
		} else
			return(-1); /*error*/
	}
	*ptr=0;
	return(n);
}

void example(){
	int fp;
	int l;
	char buf[255];
	fp=open(”pipe”,ORDONLY);
	l=readline(fp,buf,244);
	printf(”read\n\t%s\n”,buf);
	close(fp);
}
