#include<stdio.h>

int main(){
    FILE *filein = fopen("input.prog","r");
    FILE *fileout = fopen("output.prog","w");
    
    int howmany_nums = 0;
    int howmany_chars = 0;
    int howmany_lines = 0;
    int howmany_Aletters = 0;
    int howmany_Pletters = 0;
    char buffer;
    while(!feof(filein)){
        buffer = fgetc(filein);
        if(buffer>0x20){
            howmany_chars++;
            if(buffer>0x40){
                if(buffer != 'o' && buffer != 'u'&& buffer != 'e' && buffer != 'a' && buffer !='y'){
                    howmany_Pletters++;
                }else{
                    howmany_Aletters++;
                }
            }
            if(buffer>0x2f && buffer<0x3a){
                howmany_nums++;
            }
            
        }
        if(buffer == '\n'){
            howmany_lines++;
        }
    }
    fprintf(fileout," lines: %d\n nums: %d\n chars: %d\n Pletters: %d\n Aletters: %d\n",howmany_lines+1,howmany_nums,howmany_chars,howmany_Pletters,howmany_Aletters);
    fclose(filein);
    fclose(fileout);
}