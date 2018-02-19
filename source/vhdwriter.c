#include<vhdwriter.h>
#include<sys/stat.h>
int main(int argc,char **argv)
{

	if (argc != 4)
	{
		perror("arguments wrong!");
		exit(1);
	}

	FILE *fp1 = fopen(argv[1],"rb");
	FILE *fp2 = fopen(argv[2],"wb");
	if(fp1 == NULL || fp2 == NULL)
	{
		perror("no file!");
		exit(2);
	}

	struct stat fstat;
	stat(argv[1],&fstat);
	int size = fstat.st_size;

	char *sourceFile = (char *)malloc(size);
	fread(sourceFile,size,1,fp1);
	fclose(fp1);

	fseek(fp2,atoi(argv[3]) * BUFFER,SEEK_SET);
	fwrite(sourceFile,size,1,fp2);
	fclose(fp2);

	return 0;
}

