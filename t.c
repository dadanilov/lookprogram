#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int count;
struct Rule
{
    int net[4];
    int netmask[4];
    int vlan;
} list;

void read_config(struct Rule *s, char *filename, int n)
{
    FILE *fin;
    fin = fopen(filename, "r");
    fscanf(fin,"%d\n",&n);
    count = n;
    for (int i = 0; i < n; i++)
	fscanf(fin, "%d\n", &s[i].vlan);
}

int main()
{ 
    struct Rule *rule = &list; 
    char *iface_config = "data.conf";
    int n;
    read_config(rule, iface_config, n);
    for (int i = 0; i < count; i++)
 	printf("%d\n", rule[i].vlan);
}
