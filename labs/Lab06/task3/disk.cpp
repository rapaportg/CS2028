#include "disk.h"

Disk::Disk(int s, int own)
{
    size = s;
    owner = own;
}

int Disk::getSize()
{
    return size;
}

int Disk::getOwner()
{
    return owner;
}