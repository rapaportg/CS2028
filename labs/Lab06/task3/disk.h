#ifndef DISK_H
#define DISK_H

class Disk
{
    private:
        int size;
        int owner;

    public:
        Disk(int s, int own);
        int getSize();
        int getOwner();

};

#endif