#include<stdio.h>
void dm(int bn,int nl,int al,int bs);
void am(int bs,int al);
void sam(int bn,int al,int bs,int nl);
void main()
{
	int bn,nl,al,bs;
	printf("\nEnter block no. of memory:");
	scanf("%d",&bn);
	printf("\nEnter Total no. of lines in cache:");
	scanf("%d",&nl);
	printf("\nEnter address length:");
	scanf("%d",&al);
	printf("\nEnter block size:");
	scanf("%d",&bs);
	dm(bn,nl,al,bs);
	am(bs,al);
	sam(bn,al,bs,nl);
}
void dm(int bn,int nl,int al,int bs)
{
	int cbs=1,w=0,m=1,r=0,s,tag,i;
	i=bn%nl;
	while(cbs!=bs)
	{
		cbs=cbs*2;
		w++;
	}
	while(m!=nl)
	{
		m=m*2;
		r++;
	}
	s=al-w;
	tag=s-r;
	printf("\n--------Direct memory mapping--------");
	printf("\nprocess is allocated to line no.=%d of cache memory",i);
	printf("\nTag=%d",tag);
	printf("\nLine (r)=%d",r);
	printf("\nWord (w)=%d",w);
}
void am(int bs,int al)
{
	int cbs=1,w=0,m=1,r=0,s,tag;
	while(cbs!=bs)
	{
		cbs=cbs*2;
		w++;
	}
	s=al-w;
	printf("\n--------Associative memory mapping--------");
	printf("\ns=%d",s);
	printf("\nWord (w)=%d",w);
}
void sam(int bn,int al,int bs,int nl)
{
	int ns,cbs=1,w=0,v=1,d=0,s,tag,i,k,m;
	printf("\nEnter Total no. of set in cache:");
	scanf("%d",&ns);
	k=nl/ns;
	m=ns*k;
	i=bn%ns;
	while(cbs!=bs)
	{
		cbs=cbs*2;
		w++;
	}
	while(v!=ns)
	{
		v=v*2;
		d++;
	}
	s=al-w;
	tag=s-d;
	printf("\n--------Set associative memory mapping--------");
	printf("\nProcess is allocated to set no.=%d of cache memory",i);
	printf("\nNo. of line in cache memory(m)=%d",m);
	printf("\nTag=%d",tag);
	printf("\nset (d)=%d",d);
	printf("\nWord (w)=%d",w);
}
/*Output:
tejal@ubuntu:~/Desktop$ gcc dmm.c
tejal@ubuntu:~/Desktop$ ./a.out

Enter block no. of memory:13

Enter Total no. of lines in cache:256

Enter address length:20

Enter block size:32

--------Direct memory mapping--------
process is allocated to line no.=13 of cache memory
Tag=7
Line (r)=8
Word (w)=5
--------Associative memory mapping--------
s=15
Word (w)=5
Enter Total no. of set in cache:128 

--------Set associative memory mapping--------
Process is allocated to set no.=13 of cache memory
No. of line in cache memory(m)=256
Tag=8
set (d)=7
Word (w)=5
tejal@ubuntu:~/Desktop$ */
