#define NPROC        64  // maximum number of processes
#define KSTACKSIZE 4096  // size of per-process kernel stack
#define NCPU          8  // maximum number of CPUs
#define NOFILE       16  // open files per process
#define NFILE       100  // open files per system
#define NINODE       50  // maximum number of active i-nodes
#define NDEV         10  // maximum major device number
#define ROOTDEV       1  // device number of file system root disk
#define MAXARG       32  // max exec arguments
#define MAXOPBLOCKS  10  // max # of blocks any FS op writes
#define LOGSIZE      (MAXOPBLOCKS*3)  // max data blocks in on-disk log
#define NBUF         (MAXOPBLOCKS*3)  // size of disk block cache
// by seokgukim begin
// #define FSSIZE       1000  // size of file system in blocks
#define FSSIZE       21113  // size of file system in blocks
#define BGFULLSIZE   (FSSIZE/32)  // full size of block group in blocks
#define LOGMISC      (FSSIZE-BGFULLSIZE)  // misc blocks to be added to the log area
#define BGMISC       (BGFULLSIZE%4)  // misc blocks to be added to the data area of each block group
#define BGSIZE       (BGFULLSIZE-BGMISC) // size of block group in blocks
// by seokgukim end
