#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int fd, off_t p1, off_t p2) {
    int int1, int2;

    lseek(fd, p1, SEEK_SET);
    read(fd, &int1, sizeof(int));
    lseek(fd, p2, SEEK_SET);
    read(fd, &int2, sizeof(int));

    lseek(fd, p1, SEEK_SET);
    write(fd, &int2, sizeof(int));
    lseek(fd, p2, SEEK_SET);
    write(fd, &int1, sizeof(int));
}





int main(int argc, char **argv) {

    if (argc != 3) {
        perror("INPUT ERROR:");

    }
    int finp = open(argv[1], O_RDWR);
    int fout = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if (finp == -1 || fout == -1) {
        perror("FILE ERROR:");
        return 1;
    }

    off_t file_size = lseek(finp,0, SEEK_END);
    if (file_size % sizeof(int) != 0){
	    fprintf(stderr, "WRONG INPUT FILE");
	   return 1;
    }

    int kol = file_size / sizeof(int), tmp1, tmp2;

    for (int i = 0; i < kol - 1; i++){
	for (int j = 0; j < kol - i - 1; j++){
	    off_t p1 = j * sizeof(int);
	    off_t p2 = (j + 1) * sizeof(int);
	    lseek(finp, p1, SEEK_SET);
            read(finp, &tmp1, sizeof(int));
            lseek(finp, p2, SEEK_SET);
            read(finp, &tmp2, sizeof(int));

	    if (tmp1<tmp2){
		    swap(finp, p1, p2);
		}
	}
    }
	


    int tmp3;
    lseek(finp, 0, SEEK_SET);
    lseek(fout, 0, SEEK_SET);


    for (int i = 0; i < kol; i++){
	    read(finp, &tmp3, sizeof(int));
	    write(fout, &tmp3, sizeof(int));
	   }

    close(finp);
    close(fout);
   
   
return 0;
}
