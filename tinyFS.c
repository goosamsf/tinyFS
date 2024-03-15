#include "tinyFS.h"
int main(void){
	int test1;
	/* test1 : see if it can open disk 
	 *				 see if it all value set to 0x00
	 *
	 */
	printf("hello world\n")	;
	tfs_mkfs("hello.txt", DEFAULT_DISK_SIZE);

}



int tfs_mkfs(char * filename, int nBytes){
/* Make one
 *  - Use libDisk's open 
 *  - if success, format the file to be mountable disk.
 *			- memset all data 0x00
 *			- setting magic number
 *			- Initialize and write the super block and inodes
 *			- return what open reuturn
 *  - else 
 *			- return what open reuturn/
 */
	unsigned char temp_buffer[nBytes];
	int disk_id;
	if((disk_id = openDisk(filename, nBytes)) < 0){
		perror("openDisk");
		return disk_id;
	}
	
	//upon successful
	//memset(temp_buffer, 0x00, nBytes);
	init_block(disk_id, nBytes);
	//buffer_printer(temp_buffer, nBytes);
	

		return 0;
}

void init_block(int disk, int nBytes){
	/*	Initialize block:
	 * - memset data 0x00
	 * - Set magic number */
	int i;
	unsigned char temp_buffer[nBytes];
	memset(temp_buffer, 0x00, nBytes);
	for (i = 1; i < nBytes; i+=BLOCKSIZE){
		temp_buffer[i] = 0x44;
	}
	buffer_printer(temp_buffer, nBytes);
}

void buffer_printer(unsigned char *buff, int size){
	int i;
	int j = 0;
	for(i =0; i< size; i++){
		if(i % 256 == 0){
			printf("\nBLOCK %d\n", j++);
		}
		printf("%02x ", buff[i]);
		if(i != 0 && i % 32 == 0 && i % 256 != 0){
			printf("\n");
		}
	}
}


