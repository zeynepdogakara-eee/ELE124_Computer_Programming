#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 300
#include <string.h>

void savePGM(char *filename, int pixels[SIZE][SIZE]);
void readPGM(char *filename, int pixels[SIZE][SIZE]);

int main()
{
    int pixels[SIZE][SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            pixels[i][j] = rand() % 256;
        }
    }
    //------------------------------------Secret Message-----------------------------------------------------------
    char secretmessage[]="I want to and try to survive this major.I am going to be an engineer.GO WOMEN IN STEM!";
    int length=strlen(secretmessage);
    for(size_t i=0;i<length;i++)
    {
    	pixels[0][i]=secretmessage[i];
	}
	//---------------------------------------------------------------------------------------------------------
    savePGM("my_secret_image.pgm", pixels);
    printf("Image created successfully.\n");
    //----------------------------------Decoding the Messaga------------------------------------------------------
    int decodedmessage[SIZE][SIZE];
    readPGM("my_secret_image.pgm",decodedmessage);
    for(size_t i=0;i<length;i++)
    {
    	printf(" %c",decodedmessage[0][i]);	
	}
    //------------------------------------------------------------------------------------------------------------
    return 0;
}
void savePGM(char *filename, int pixels[SIZE][SIZE])
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("File could not be created.\n");
        return;
    }
    fprintf(fp, "P2\n");
    fprintf(fp, "%d %d\n", SIZE, SIZE);
    fprintf(fp, "255\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            fprintf(fp, "%d ", pixels[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}
void readPGM(char *filename, int pixels[SIZE][SIZE])
{
	FILE *fp=fopen("my_secret_image.pgm","r");
	if (fp == NULL)
    {
        printf("File could not opened.\n");
        return;
    }
    char format[3];
    int width, height, max_val;
    fscanf(fp, "%s", format);
    fscanf(fp, "%d %d", &width, &height);
    fscanf(fp,"%d", &max_val);
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            fscanf(fp, "%d", &pixels[i][j]);
        }
    }
    fclose(fp);
}

