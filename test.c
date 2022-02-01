#include <stdio.h>


int main()
{     int a[10];
      int b[10];
      int c[10];
      int d[10];
      
      int aa[10];
      int bb[10];
      int cc[10];
      int dd[10];
      
      int vl[10];
      int i, n;  

     FILE *fin;

      fin = fopen("data1.txt", "r");
	fscanf(fin,"%d\n",&n);
     for (i=0;i<n;i++)
     {

         fscanf(fin,"net %d.%d.%d.%d netmask %d.%d.%d.%d vlan %d\n",&a[i],&b[i],&c[i],&d[i],&aa[i],&bb[i],&cc[i],&dd[i],&vl[i]);        
     }

 	for (i=0;i<n;i++)
         printf("%d %d %d %d - %d %d %d %d - %d\n",a[i],b[i],c[i],d[i],aa[i],bb[i],cc[i],dd[i],vl[i]); 
         printf("\n");      

     fclose(fin);
}
