#include "pmount.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* readPartitionTable()
{
    size_t blength;
    FILE* fp = fopen("A:/System/MountPartitions.cfg", "r");
    fseek(fp, 0, SEEK_END);
    blength = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* reaf = malloc(blength);
    fread(reaf, blength, sizeof(char), fp);
    fclose(fp);

    return reaf;
}

static void parsePartitionTable(char* buffer)
{
    asm volatile("xchg %bx, %bx");
    char* x = strtok(buffer, " \n");
}

void ptMountPartitions()
{
    char* ptf = readPartitionTable();
    parsePartitionTable(ptf);

    free(ptf);
}
