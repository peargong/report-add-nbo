#include <iostream>
#include <netinet/in.h>
using namespace std;
int read_file(char *filename, uint32_t *buf, int size)
{
    FILE* fp;
    int read_len = 0;
    if((fp = fopen(filename, "rb"))==NULL){
        printf("file open error");
        return -1;
    }
    fread(buf, sizeof(uint32_t), size, fp);
    fclose(fp);
    return 0;
}
int main(int argc, char *args[])
{
    uint32_t buffer[2]={0x00000000,};
    uint32_t sum=0;
    if (argc < 2){
        printf("input style=~~");
        exit(-1);
    }
    for(int i=1;i<3;i++)
    {
        char  * filename=args[i];
        read_file(filename, &buffer[i-1], 1);
        buffer[i-1]=htonl(buffer[i-1]);
        sum=sum+buffer[i-1];
    }
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",  buffer[0], buffer[0], buffer[1], buffer[1], sum, sum);
    return 0;
}
