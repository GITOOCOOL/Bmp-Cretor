#include <stdio.h>
#include <string.h>
#include <io.h>



#define HEADERSIZE 2176

#define red 79
#define green 113
#define blue 232

#define MAX_FILENAME 100

FILE* outfile;
FILE* infile;

typedef struct point{
    int x,y;
}point;


void drawSquare(char* filename,int color,int x_coord,int y_coord,int length);


int main(int argc, char* argv[]){
    char filename[MAX_FILENAME];
    int ctr;
    int reader;

    strcpy(filename,argv[1]);

    infile=fopen("template256.bmp","r");

    if(argc<2){
    outfile=fopen("testnow.bmp","w");
    //fprintf(stderr,"ERROR! Must have an argument);
    //return -1;
    }
    else if(argc == 2){
        outfile = fopen(filename,"w");
    }
    else{
        fprintf(stderr,"ERROR! Too many arguments");
        return -1;
    }
    ctr =1;
    while((reader=fgetc(infile))!=EOF ){

        if(ctr>HEADERSIZE){
            /*switch(ctr%6){
                case 0: fputc(red,outfile);

                 case 1: fputc(red,outfile);

                  case 2: fputc(red,outfile);

                   case 3: fputc(red,outfile);

                case 4: fputc(green,outfile);

                case 5: fputc(blue,outfile);
            }*/
            fputc(green,outfile);


        }
        else {
            fputc(reader,outfile);
        }
     ctr++;
    }

    fclose(infile);
    fclose(outfile);
    drawSquare(filename,red,0,0,600);



    system(filename);
    return 0;
}

void drawSquare(char* filename,int color,int x,int y, int length){
    int start = ((y*16)+x)+HEADERSIZE;
    int readptr;
    int reader;
    //fclose(outfile);
    FILE* writefile;
    FILE* readfile;
    FILE* copyfile;
    {


    readfile = fopen(filename,"r");
    copyfile = fopen(strcat(filename,"~"),"w");

    while((reader=fgetc(infile))!=EOF){
        fputc(reader,copyfile);
    }
    fclose(readfile);
    fclose(copyfile);
    }

    copyfile = fopen(strcat(filename,"~"),"r");
    writefile = fopen(filename,"w");

    while((reader=fgetc(infile))!=EOF){
         readptr=1;
        fputc(reader,writefile);
    }
    {
                if((j%10)==0){
                    stop_painter = 1;
                }
                if(!stop_painter){
                    fputc(color,writefile);
                }
                j_INC;

        }*/
    //fclose(writefile);

}
