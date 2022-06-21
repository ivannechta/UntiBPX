//idag -A -Sanalysis.idc file

#include <idc.idc>
static CalcCallsCount(){
auto a;
auto i;
auto cnt;
auto f;     
a=0;        
f=fopen(GetInputFile()+".fcnt","wt");
while((a=NextFunction(a))!=-1)
{
    i=a; cnt=0;
    while (i<FindFuncEnd(a)){
        if (GetMnem(i)=="call"){                        
            cnt=cnt+1;
        }
    i=NextHead(i,BADADDR);
    }
    fprintf(f,"%d\n",cnt);
}
fclose(f);
}
//----------
static CalcFuncLen(){
auto a;
auto f;
a=0;
f=fopen(GetInputFile()+".flen","wt");
while((a=NextFunction(a))!=-1)
{
fprintf(f,"%d\n",FindFuncEnd(a)-a);
}
fclose(f);
}         
//----------
static main(){
Wait();
CalcCallsCount();
CalcFuncLen();
Exit(0);
}