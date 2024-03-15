#ifndef TINYFS_H
#define TINYFS_H

#define BLOCKSIZE 256
#define DEFAULT_DISK_SIZE 10240
#define DEFAULT_DISK_NAME "tinyFSDisk"

/* BLOCK TYPE */
#define SUPERBLOCK 1
#define INODE 2
#define FILEEXTENT 3
#define FREEBLOCK 4

typedef int fileDescriptor;

void buffer_printer(unsigned char*buff, int size);
void init_block(int disk, int nBytes);
#endif
