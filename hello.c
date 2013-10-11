#include <stdio.h>
#include <inttypes.h>
#include <fcntl.h>
#include <unistd.h>


//#define READ_COUNTER_ADDR 0x40050000
//int32_t *read_counter = (int32_t *) READ_COUNTER_ADDR;

int main(void)
{
	FILE* note;
    	char str[100];
	char buff[100];

    	note=fopen("file_save.txt","w");
    	if(note==NULL){
        	printf("read error!\n\r");
        	return 0;
    	}
	
	printf("type the string you want leave:\n\r");
	scanf("%s",str);
	printf("the string already write into the note\n\r");
    	fprintf(note,"%s",&str);
    	fclose(note);


    	note=fopen("file_save.txt", "r");
    	if(note==NULL){
        	printf("read error!\n\r");
        	return 0;
    	}

    	fread(buff,sizeof(buff),1,note);
	printf("\"%s\" is read from the note\n\r",buff);
    	fclose(note);

	return 0;
}
