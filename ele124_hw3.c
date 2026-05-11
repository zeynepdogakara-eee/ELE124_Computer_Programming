#include <stdio.h>
#include <string.h>
//This function takes the full log string and splits it into 3 parts
void parseLog(char *log, char *id, char *status, char*message);

int main() 
{
// Open the text file in read mode
FILE *file=fopen("device_logs.txt.txt","r");
//check if the file exists
if(file==NULL) 
{
    printf("Error: Could not open file 'device_logs.txt'\n");
    return 1;
}
char line[100];//to store each line from the file
char id[100];//to store extracted ID
char status[100];//to store extracted status
char message[100];//to store extracted message 
printf("Failing Devices:\n");
//loop through the file line by line until the end(NULL)
while(fgets(line, sizeof(line), file)) 
{
//remove the newline character (\n) at the end of the line if it exists
//'\n' is enter 
int len = strlen(line);
if(len>0&&line[len-1]=='\n')line[len-1]='\0'; 
//call to function
parseLog(line,id,status,message);
//check if the status is exactly"FAIL"
//strcmp returns 0 if the two strings are identical
if(strcmp(status,"FAIL")==0)printf("%s:%s\n",id,message);
}
fclose(file);
return 0;
}

void parseLog(char *log, char *id, char *status, char*message)
{
char *token;//my parts
//STEP 1:get the device ID
//strtok finds the first : and cuts the string there
token=strtok(log,":");
if(token!=NULL)strcpy(id,token);//if it finds something,copies the ID part into our'id'variable
//STEP 2:get the status(OK or FAIL)
//I use NULL because strtok remembers where it left off
token=strtok(NULL,":");
if(token!=NULL)strcpy(status,token);//copy the status part into our status variable
//STEP 3:get the messagee(error description)
token=strtok(NULL,":");
if(token!=NULL)strcpy(message,token);//copy the message part into our 'message' variable
}









