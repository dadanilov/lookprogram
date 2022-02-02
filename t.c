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
	fscanf(fin, "net %d.%d.%d.%d netmask %d.%d.%d.%d vlan %d\n", &s[i].net[0], &s[i].net[1],  &s[i].net[2], &s[i].net[3], &s[i].netmask[0], &s[i].netmask[1], &s[i].netmask[2], &s[i].netmask[3], &s[i].vlan);
}

int main()
{ 
    struct Rule *rule = &list; 
    char *iface_config = "data.conf";
    int n;
    read_config(rule, iface_config, n);
    for (int i = 0; i < count; i++)
 	printf("%d %d %d %d - %d %d %d %d - %d\n", rule[i].net[0], rule[i].net[1], rule[i].net[2], rule[i].net[3], rule[i].netmask[0], rule[i].netmask[1], rule[i].netmask[2], rule[i].netmask[3], rule[i].vlan);
}
