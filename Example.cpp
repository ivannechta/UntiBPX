#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <sys/mman.h>
using namespace std;

typedef double (*PFcos)(double x);
typedef int (*Pfunc)(PFcos _cos);

__attribute__((noinline, section("func")) ) int func(PFcos _cos);
void load();
void save();
extern char __start_func[];
extern char __stop_func[];

char *buffer;
//------------------------
void save(){
int i=0;
char *p=(char*)&func;
while(i<4096){
    buffer[i]=*(p+i);
    i++;
}
}

__attribute__((noinline, section("func")) ) int func(PFcos _cos){
float s=0;
char WaterMark[]="Ivan V. Nechta";
for (int i=0;i<10;i++){
    s+=i;
}
return (int)(s-(_cos)(0));
}


int main(int argc,char**argv)
{

buffer=(char*)memalign(4096,4096);
mprotect(buffer,4096,PROT_WRITE|PROT_EXEC);
cout << "func() code size="<<(long)__stop_func-(long)__start_func<<"\n";


  // Here you can save code in file and then process it after or load in from anywhere (file, another secret buffer), you may also apply here cryptography
  save(); //Save func to buffer
//load();   //Load code to buffer
 
  
// Execute code in buffer
Pfunc* f=(Pfunc*)&buffer;

float Sum;
Sum=(*f)(&cos);

cout << Sum;
return 0;
}
