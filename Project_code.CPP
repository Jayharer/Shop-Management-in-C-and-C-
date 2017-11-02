#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

class Store
{
 public:
 int item_code;
 char name[20];
 int qty;
 float s_rate;  //selling rate 
 float p_rate;  //purchase rate
 int s_qty;
 float amount;
 Store(){ s_qty=0; }

};

 struct Bill
{

 int item_code;
 int qty;
};

 
 class BILL
 {
  public:
  int item_code[10];
  char name[10][15];
  int qty[10];
  float rate[10];
  float amount[10];
  float total;
  int x;

  int day,month,year;
  BILL();


 };

 BILL::BILL()
 {
  for(int i=0;i<10;i++)
  for(int j=0;j<15;j++)
  name[i][j]='\0';
 }
  
 struct Date
{
  int day;
 int month;
 int year;
};

 
 class Customer
{
  public:

  int day;
   int month;
    int year;
  char name[10][20];
  char c_name[20];
  char mob[15];
  int item_code[10];
  int qty[10];
  float rate[10];
  float amount[10];
  float t_amount;
  int count;
  Customer(); 
};

 Customer::Customer()
{
 for(int i=0;i<10;i++)
  for(int j=0;j<20;j++)
   name[i][j]='\0';

  for(int n=0;n<20;n++)
   mob[n]=c_name[n]='\0';

   day=month=year=0;
}


  class Vendor
{
  public:
  int day,month,year;
  char name[10][20];
  char mob[10];
  char v_name[20];
  int item_code[10];
  int qty[10];
  float p_rate[10];
  float amount[10];
  float t_amount,vat,grand_total;
  int count;
  Vendor(); 
};

 Vendor::Vendor()
{
 for(int i=0;i<10;i++)
  for(int j=0;j<20;j++)
   name[i][j]='\0';

  for(int n=0;n<20;n++)
   v_name[n]='\0';
 
 count=0;
 t_amount=0; 
}


class Pcount{      // for counting profit of every item sell
public :
 int item_code;
 char name[15];
 float profit;
 int qty;
 Pcount(){
 profit=0;
 qty=0;

}
};
 

 class Cash{      // cash collected-daily,monthly,yearly
 public :

 int day,month,year;
 float dcash,mcash,ycash;

 Cash(){

 day=month=year=dcash=mcash=ycash=0;

}

};

class Dsell{

 public :
 int item_code;
 char name[20];
 int qty;
 int day;
Dsell();

};

 Dsell::Dsell(){

 item_code=day=qty=0;
 
 for(int n=0;n<20;n++)
   name[n]='\0';

}

class Msell{

 public :
 int item_code;
 char name[20];
 int qty;
 int month;
Msell();

};

 Msell::Msell(){

 item_code=month=qty=0;

for(int n=0;n<20;n++)
  name[n]='\0';

}
 
void main()
{ clrscr();

  printf("                       WELCOME TO MAMA SUPER MARKET\n");

   Store s;//store object
  Store S[100]; // array of object of store class
 
 BILL bill; // Bill class object
 Customer cust;

  int no;
 Dsell adsell[100];
 Msell amsell[100];
  


  
   char che; //do  while loop character
   FILE *fptr; // file pointer

do
{
 cout<<" 1:set today date             ";
 cout<<" 2:make store record\n";
 cout<<" 3:show store record          ";
 cout<<" 4:Delete store record\n";
 cout<<" 5:make a bill                ";
 cout<<" 6:show customer record\n";
 cout<<" 7:change rate                ";
 cout<<" 8:check less stock material\n";
 cout<<" 9:receive material update    ";
 cout<<"10:show purchase record\n";
 cout<<"11:count item profit          ";
 cout<<"12:cash collected\n";
 cout<<"13:today sell of items        ";
 cout<<"14:monthly sell of items\n";

 cout<<"\nenter your choice(1,2,3,4..........)\n";
 cin>>no;


 switch(no)
{
  case 1:{ 

 struct Date t_date;  Cash cash;

 Dsell dsell;Msell msell;
 
cout<<"\n enter day  ";
   cin>>t_date.day;
   cout<<"\n enter month  ";
   cin>>t_date.month;
  cout<<"\n enter year  ";
  cin>>t_date.year; 

 fptr=fopen("myfile4","rb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}
 fread(&cash,sizeof(cash),1,fptr);

 if(cash.day!=t_date.day){
 cash.day=t_date.day;
 cash.dcash=0;
 }

 if(cash.month!=t_date.month){
 cash.month=t_date.month;
 cash.mcash=0;
 }

 if(cash.year!=t_date.year){
 cash.year=t_date.year;
 cash.ycash=0;
 }

 fclose(fptr);

 fptr=fopen("myfile4","wb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}
 fwrite(&cash,sizeof(cash),1,fptr);

 fclose(fptr);



fptr=fopen("myfile5","rb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}
	
 int dcount; int dsize,msize;
 for(dcount=0;;dcount++){
  
  fread(&dsell,sizeof(dsell),1,fptr);
  if(feof(fptr)) break;

 adsell[dcount].item_code=dsell.item_code;

  int p;
  for( p=0;dsell.name[p]!='\0';p++)
 adsell[dcount].name[p]=dsell.name[p];
 adsell[dcount].name[p]='\0';

 adsell[dcount].qty=dsell.qty;
 adsell[dcount].day=dsell.day;

 
  
 dsize=dcount+1;


}
 fclose(fptr);          int i;

 for(i=0;i<dcount;i++)
 if(t_date.day != adsell[i].day){
    
 adsell[i].qty=0;
 adsell[i].day=t_date.day;

}

 fptr=fopen("myfile5","wb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}
  rewind(fptr);

 for(  i=0;i<dsize;i++)
 {

 fwrite(&adsell[i],sizeof(adsell[i]),1,fptr);

 }
 fclose(fptr);

 

 fptr=fopen("myfile6","rb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}
	     
int mcount;
 for(mcount=0;;mcount++){
  
  fread(&msell,sizeof(msell),1,fptr);
   if(feof(fptr)) break;

 amsell[mcount].item_code=msell.item_code;

  int p;
  for( p=0;msell.name[p]!='\0';p++)
 amsell[mcount].name[p]=msell.name[p];
 amsell[mcount].name[p]='\0';

 amsell[mcount].qty=msell.qty;
 amsell[mcount].month=msell.month;
  
 msize=mcount+1;

 



}
   fclose(fptr);;

 for(i=0;i<msize;i++)
 if(t_date.month != amsell[i].month){
    
 amsell[i].qty=0;
 amsell[i].month = t_date.month;

 
} 

 fptr=fopen("myfile6","wb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}

 rewind(fptr);     

 for(  i=0;i<msize;i++)
 {

 
 fwrite(&amsell[i],sizeof(amsell[i]),1,fptr);

 }
 fclose(fptr);

} break; //case 1 end




  case 2: {
  
 Pcount pc;
Dsell dsell;   Msell msell;
  cout<<"enter item no  ";
  cin>>s.item_code;

  dsell.item_code=msell.item_code=pc.item_code=s.item_code;

 cout<<"\nenter name  ";
 cin>>s.name;
 int p;
for( p=0;s.name[p]!='\0';p++)
  dsell.name[p]=msell.name[p]=pc.name[p]=s.name[p];
  dsell.name[p]=msell.name[p]=pc.name[p]='\0';

 cout<<"\nenter qty  ";
 cin>>s.qty;

 

 cout<<"\nenter purchase rate  ";
 cin>>s.p_rate;
 cout<<"\n enter selling rate  ";
 cin>>s.s_rate;
 cout<<"\n";
 fptr=fopen("myfile","ab");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}
 fwrite(&s,sizeof(s),1,fptr);

 fclose(fptr);

 fptr=fopen("myfile3","ab");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}
 fwrite(&pc,sizeof(pc),1,fptr);

 fclose(fptr);

fptr=fopen("myfile5","ab");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}
 fwrite(&dsell,sizeof(dsell),1,fptr);

 fclose(fptr);

 fptr=fopen("myfile6","ab");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}
 fwrite(&msell,sizeof(msell),1,fptr);

 fclose(fptr);

 } break; //case 2 end

 case 3: {
 cout.width(10);
 cout<<"\n item code";
 cout.width(15);
 cout<<"item name";
 cout.width(15);
 cout<<"item Pur_rate";
 cout.width(15);
 cout<<"item Sell_rate" ;
 cout.width(15);
 cout<<"item quantity";
  fptr=fopen("myfile","rb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}


for(;;)
{
  

 fread(&s,sizeof(s),1,fptr);
  if(feof(fptr))  break;
cout<<"\n";
cout.width(10);
 cout<<s.item_code;
 cout.width(15);
 cout<<s.name;
 cout.width(15);
 cout.precision(2);
 cout<<s.p_rate;
 cout.width(15);
 cout.precision(2);
 cout<<s.s_rate;

 cout.width(15);
 cout<<s.qty;
 cout<<"\n";

}
fclose(fptr);
   
 } break; // case 3 end

 case 4:{

 fptr=fopen("myfile","rb");
 if(fptr==NULL)
{
 cout<<"\nerror in opening file";
 exit(1);
}

int siz;

for(int v=0;;v++)
{
  
 fread(&s,sizeof(s),1,fptr);
 if(feof(fptr))  break;
 S[v].item_code=s.item_code;
  for(int p=0;s.name[p]!='\0';p++)
  S[v].name[p]=s.name[p];
  S[v].name[p]='\0';
  S[v].qty=s.qty;
  S[v].p_rate=s.p_rate;
  S[v].s_rate=s.s_rate;

 siz=v+1;
  
 

}
fclose(fptr);

 cout<<"\nsize of file "<<siz<<"\n";

 int itm;
cout<<"enter item code";
cin>>itm;

 for(int f=0;f<siz;f++){
 
 if(itm==S[f].item_code){
 
  for( ;f<siz-1;f++)
{
  S[f].item_code=S[f+1].item_code;
  for(int p=0;S[f+1].name[p]!='\0';p++)
  S[f].name[p]=S[f+1].name[p];
  S[f].name[p]='\0';
  S[f].qty=S[f+1].qty;
  S[f].p_rate=S[f+1].p_rate;
  S[f].s_rate=S[f+1].s_rate;

} 

 siz--;

cout<<"\n new size of file "<<siz<<"\n";
 break;
} // if end

} //outer for end


 for (int i=0;i<siz;i++){
 cout<<S[i].item_code<<" "<<S[i].name<<" "<<S[i].qty<<" "<<S[i].p_rate<<" "<<S[i].s_rate<<"\n";

}


 
fptr=fopen("myfile","wb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}

 rewind(fptr);

 for( i=0;i<siz;i++){
 
 fwrite(&S[i],sizeof(S[i]),1,fptr);

 

}

fclose(fptr);


} break; // case 4 end

case 5: {

  struct  Bill b[10];
  char ch;
float total_amount=0;

 int k=0,count=-1;
  do
 {
  cout<<"\nenter item code  ";
  cin>>b[k].item_code;

  bill.item_code[k]=b[k].item_code;

 cout<<"\nenter quantity  ";
 cin>>b[k].qty;
 bill.qty[k]=b[k].qty;


 cout<<"\nenter c to add item  ";
 cin>>ch;
 k++;
 }while(ch=='c'|| ch=='C');
 
  struct Date date;
 cout<<"\nenter day  ";
 cin>>date.day;

 bill.day=date.day;

 cout<<"\nenter month   ";
 cin>>date.month;

 bill.month=date.month;

 cout<<"\n enter year   ";
 cin>>date.year;

 bill.year=date.year;

 cout<<"\n                       WELCOME TO MAMA SUPER MARKET\n";
 cout<<"Date: "<<date.day<<"/"<<date.month<<"/"<<date.year<<"\n";
 
 
 cout.width(10);
 cout<<"\n item code";
 cout.width(20);
 cout<<"item name";
 cout.width(15);
 cout<<"item rate";
 cout.width(15);
 cout<<"item quantity";
 cout.width(15);
 cout<<"amount";
 cout<<"\n";

 fptr=fopen("myfile","rb");

 if(fptr==NULL){
 printf("error in opening file ");
 exit(0);

}

 int siz;

for(int v=0;;v++)
{
  
 fread(&s,sizeof(s),1,fptr);
 if(feof(fptr))  break;
 S[v].item_code=s.item_code;
  for(int p=0;s.name[p]!='\0';p++)
  S[v].name[p]=s.name[p];
  S[v].name[p]='\0';
  S[v].qty=s.qty;
  S[v].p_rate=s.p_rate;
  S[v].s_rate=s.s_rate;

 siz=v+1;
  
 

}
fclose(fptr);

Pcount pcf[100];

int siz1;
fptr=fopen("myfile3","rb");

 if(fptr==NULL){
 printf("error in opening file ");
 exit(0);

}
  Pcount pc;

for(int m=0;;m++)
{
  
 fread(&pc,sizeof(pc),1,fptr);
 if(feof(fptr))  break;
 pcf[m].item_code=pc.item_code;
 int p;
  for( p=0;pc.name[p]!='\0';p++)
  pcf[m].name[p]=pc.name[p];
  pcf[m].name[p]='\0';

  pcf[m].qty=pc.qty;
  pcf[m].profit=pc.profit;
  

 siz1=m+1;
  
 

}
fclose(fptr);

 

     Dsell dsell;Msell msell;  int dsize,msize;
 
 fptr=fopen("myfile5","rb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}
 int dcount;
 for(dcount=0;;dcount++){
  
  fread(&dsell,sizeof(dsell),1,fptr);
  if(feof(fptr)) break;

 adsell[dcount].item_code=dsell.item_code;

  int p;
  for( p=0;dsell.name[p]!='\0';p++)
 adsell[dcount].name[p]=dsell.name[p];
 adsell[dcount].name[p]='\0';

 adsell[dcount].qty=dsell.qty;
 adsell[dcount].day=dsell.day;
  
 dsize=dcount+1;


}

 fclose(fptr);

  fptr=fopen("myfile6","rb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}

 int mcount;
 for(mcount=0;;mcount++){
  
  fread(&msell,sizeof(msell),1,fptr);
  if(feof(fptr)) break;

 amsell[mcount].item_code=msell.item_code;

  int p;
  for( p=0;msell.name[p]!='\0';p++)
 amsell[mcount].name[p]=msell.name[p];
 amsell[mcount].name[p]='\0';

 amsell[mcount].qty=msell.qty;
 amsell[mcount].month=msell.month;
  
 msize=mcount+1;


}

 fclose(fptr);

 


 for(int l=0;l<k;l++){

 for(int v=0;v<siz;v++){


 if(b[l].item_code==S[v].item_code){



   int z;
    
 for( z=0;z<dsize;z++) {
 
  
  
 
if(adsell[z].item_code==S[v].item_code)
 {
  adsell[z].qty=adsell[z].qty+b[l].qty;

 adsell[z].day=date.day;
   
  
  }
 

}  //for end


 
 
     
 for(z=0;z<msize;z++){

 
 if(amsell[z].item_code==S[v].item_code)
 {
  amsell[z].qty=amsell[z].qty+b[l].qty;
  

 amsell[z].month=date.month;


  }

}



count++;
 
  cout.width(10);
  cout<<S[v].item_code;
 
   cout.width(20);
  cout<<S[v].name;
 
 for(int a=0;(S[v].name[a])!='\0';a++)
  bill.name[count][a]=S[v].name[a]; //class bill name update

  cout.width(15);
  cout.precision(2);
  cout<<S[v].s_rate;

  bill.rate[count]=S[v].s_rate; //class  bill rate update

  cout.width(15);
  cout<<b[l].qty;
  
  S[v].s_qty=S[v].s_qty+b[l].qty; // update selling quantity

  S[v].qty=S[v].qty-b[l].qty;

  S[v].amount=S[v].s_rate*b[l].qty;

  bill.amount[count]=S[v].amount;  //class bill amount

 for(int j=0;j<siz1;j++){
  if(pcf[j].item_code==S[v].item_code){

  pcf[j].qty=pcf[j].qty+b[l].qty;
  pcf[j].profit=pcf[j].profit+(b[l].qty*(S[v].s_rate-
                                              S[v].p_rate));

}

}
  

 cout.width(15);
 printf("%15.2f",S[v].amount);
  cout<<"\n";




} //if end


} //inner for end

} // outer for end

 
 bill.x=count; // no of items sell x


 cout<<"----------------------------------------------------------------------------\n";




 for(int n=0;n<=count;n++){

 
 total_amount=total_amount+S[n].amount;
  
}
 bill.total=total_amount; //class bill total

 
 cout<<"total amount:";

 printf("%62.2f",total_amount);

 fptr=fopen("myfile5","wb");

 if(fptr==NULL)
 {
 cout<<"\nerror in opening file";
 exit(1);
 }

 rewind(fptr);     int i;

 for(  i=0;i<dsize;i++)
 {
 
 fwrite(&adsell[i],sizeof(adsell[i]),1,fptr);

 }

fclose(fptr);

 fptr=fopen("myfile6","wb");

 if(fptr==NULL)
 {
 cout<<"\nerror in opening file";
 exit(1);
 }

 rewind(fptr);

 for(  i=0;i<msize;i++)
 {
 
 fwrite(&amsell[i],sizeof(amsell[i]),1,fptr);

 }

fclose(fptr);



 Cash cash;

 fptr=fopen("myfile4","rb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}
 fread(&cash,sizeof(cash),1,fptr);

 if(cash.day==date.day){
 
 cash.dcash=cash.dcash+total_amount;
 }

 if(cash.month==date.month){

 cash.mcash=cash.mcash+total_amount;
 }

 if(cash.year==date.year){

 cash.ycash=cash.ycash+total_amount;
 }

 fclose(fptr);

 fptr=fopen("myfile4","wb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}
 fwrite(&cash,sizeof(cash),1,fptr);

 fclose(fptr);



 fptr=fopen("myfile","wb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}

 rewind(fptr);

 for(  i=0;i<siz;i++){
 
 fwrite(&S[i],sizeof(S[i]),1,fptr);

 

}

fclose(fptr);

cout<<"\n";


 fptr=fopen("myfile3","wb");

 if(fptr==NULL)
 {
 cout<<"\nerror in opening file";
 exit(1);
 }

 rewind(fptr);

 for(  i=0;i<siz1;i++)
 {
 
 fwrite(&pcf[i],sizeof(pcf[i]),1,fptr);

 }

fclose(fptr);



 char chhh;
 cout<<"\ndo you want to save record in customer list";
 cout<<"\nenter N for no & Y for yes  ";
 cin>>chhh;
if(chhh=='y' || chhh=='Y')
{
   
 
  cout<<"\n enter customer name  ";
  cin>>cust.c_name;
  cout<<"\n enter customer mobile no  ";
  cin>>cust.mob;

  cust.day=bill.day;
 
  cust.month=bill.month;
  
  cust.year=bill.year;

  
  for(int u=0;u<=count;u++)
  {
    cust.item_code[u]=bill.item_code[u];

  
  for(int v=0;(bill.name[u][v])!='\0';v++)
  cust.name[u][v]=bill.name[u][v];

  cust.rate[u]=bill.rate[u];
 
  cust.qty[u]=bill.qty[u];

  cust.amount[u]=bill.amount[u];

 }

  cust.t_amount=bill.total;

 cust.count=count;

 fptr=fopen("myfile1","ab");
 if(fptr==NULL){
 cout<<"\n error in opening file";
 exit(0);
}
  
 fwrite(&cust,sizeof(cust),1,fptr);
 fclose(fptr);

} //if end 

 

 total_amount=0;

 } break;//case 5 end


case 6:{

 
       cout<<"\n";
  cout<<"1: show all record\n";
  cout<<"2: specific customer record\n";
  cout<<"enter your choice  ";
  cin>>no;

 switch(no)
{
 case 1:{

  fptr=fopen("myfile1","rb");

 if(fptr==NULL){
 cout<<"\n error in opening file";
 exit(0);
}


   for(;;)
   { 


  fread(&cust,sizeof(cust),1,fptr);

  if(feof(fptr)) break;

  cout<<"\nDate:"<<cust.day<<"/"<<cust.month<<"/"<<cust.year;
   
   cout.width(20);
   cout<<cust.c_name;

  cout.width(20);
   cout<<cust.mob;

  cout.width(10);
  cout<<"\n item code";
  cout.width(15);
  cout<<"item name";
  cout.width(15);
  cout<<"item Pur_rate";
  cout.width(15);
  cout<<"item P_qty" ;
  cout.width(15);
  cout<<"amount";

  for(int v=0;v<=cust.count;v++)
  {
   cout<<"\n";

   cout.width(10);
   cout<<cust.item_code[v];

   cout.width(15);
   cout<<cust.name[v];

   cout.width(15);
   cout<<cust.rate[v];

   cout.width(15);
   cout<<cust.qty[v];

   
   printf("%15.2f",cust.amount[v]);

   cout<<"\n";
  }// inner for loop end
 
cout<<"\n-----------------------------------------------------------------------------\n";
 cout<<"\ntotal amount: ";

 printf("%56.2f",cust.t_amount);

 cout<<"\n";

 } //outer for loop end


 fclose(fptr);

 } break; //case 1 end



 case 2: {
  char name1[20]; int flag=0;
 cout<<"\n enter customer name ";
 cin>>name1;
 
 fptr=fopen("myfile1","rb");

 if(fptr==NULL){
 cout<<"\n error in opening file";
 exit(0);
}

 for(;;)
   { 

 fread(&cust,sizeof(cust),1,fptr);
  if(feof(fptr))
  break;


  int x=strcmp(name1,cust.c_name);

  if(!x)
 {
   flag=1;

  cout<<"\nDate:"<<cust.day<<"/"<<cust.month<<"/"<<cust.year;
   
   cout.width(20);
   cout<<cust.c_name;

  cout.width(20);
   cout<<cust.mob;

  cout.width(10);
  cout<<"\n item code";
  cout.width(15);
  cout<<"item name";
  cout.width(15);
  cout<<"item Pur_rate";
  cout.width(15);
  cout<<"item P_qty" ;
  cout.width(15);
  cout<<"amount";

  for(int v=0;v<=cust.count;v++)
  {
   cout<<"\n";

   cout.width(10);
   cout<<cust.item_code[v];

   cout.width(15);
   cout<<cust.name[v];

   cout.width(15);
   cout<<cust.rate[v];

   cout.width(15);
   cout<<cust.qty[v];

   cout.width(15);
   cout.precision(2);
   printf("%15.2f",cust.amount[v]);

   cout<<"\n";
  }// inner for loop end
 
cout<<"\n-----------------------------------------------------------------------------\n";
 cout<<"\ntotal amount: ";
 cout.width(56);
 cout.precision(2);
 printf("%56.2f",cust.t_amount);

 } //if end
 
 cout<<"\n";
 } //outer for loop end

 fclose(fptr);

 if(flag==0)
 cout<<"\n no match record found\n";

} break; //case 2 break

} //switch block end


} break; //case 6 end

 
 case 7:{
  int item__code;
  cout<<"\n enter item code  ";
 cin>>item__code;

 fptr=fopen("myfile","rb");

 if(fptr==NULL){
 printf("error in opening file ");
 exit(0);

}

 int siz;

for(int v=0;;v++)
{
  
 fread(&s,sizeof(s),1,fptr);
 if(feof(fptr))  break;
 S[v].item_code=s.item_code;
  for(int p=0;s.name[p]!='\0';p++)
  S[v].name[p]=s.name[p];
  S[v].name[p]='\0';
  S[v].qty=s.qty;
  S[v].p_rate=s.p_rate;
  S[v].s_rate=s.s_rate;

 siz=v+1;
  
 

}
fclose(fptr);

 for(int p=0;p<siz;p++)
 {
   if(item__code==S[p].item_code)
 {
    float new_rate;
 cout<<"\nenter new rate of selling  ";
 cin>>new_rate;
 S[p].s_rate=new_rate;
 break;
 } // if end
} // for loop end

 fptr=fopen("myfile","wb");

 if(fptr==NULL){
 printf("error in opening file ");
 exit(0);

}
  rewind(fptr);
 for(int i=0;i<siz;i++){

  fwrite(&S[i],sizeof(S[i]),1,fptr);
}

 fclose(fptr);

 
} break;//case 7 end



 case 8: {  int limit;     //check less stock material
 cout<<"set limit    ";
 cin>>limit;
 cout.width(10);
 cout<<"\n item code";
 cout.width(20);
 cout<<"item name";
 cout.width(15);
 cout<<"item quantity"<<"\n";

 fptr=fopen("myfile","rb");

 if(fptr==NULL){
 printf("error in opening file ");
 exit(0);

}
 for(;;)
 {

 fread(&s,sizeof(s),1,fptr);
 if(feof(fptr))  break;

   if(s.qty<=limit)
  {
    cout.width(10);
 cout<<s.item_code;
 cout.width(20);
 cout<<s.name;
 cout.width(15);
 cout<<s.qty;
 cout<<"\n";
  }
  } // for loop end

  fclose(fptr);
 
} break;//case 8 end


case 9:{    //receive material update
 int id,qty;
 char ch;
 float rate;
 Vendor vendor;
 
 cout<<"\nenter day  ";
 cin>>vendor.day;
 cout<<"\nenter month  ";
 cin>>vendor.month;
 cout<<"\nenter year  ";
 cin>>vendor.year;

 cout<<"\nenter vendor name  ";
 cin>>vendor.v_name;

 cout<<"\nenter vendor mobile no  ";
 cin>>vendor.mob;


 cout<<"\nenter VAT  ";
 cin>>vendor.vat;

 fptr=fopen("myfile","rb");

 if(fptr==NULL){
 printf("error in opening file ");
 exit(0);

}

 int siz;

for(int v=0;;v++)
{
  
 fread(&s,sizeof(s),1,fptr);
 if(feof(fptr))  break;
 S[v].item_code=s.item_code;
  for(int p=0;s.name[p]!='\0';p++)
  S[v].name[p]=s.name[p];
  S[v].name[p]='\0';
  S[v].qty=s.qty;
  S[v].p_rate=s.p_rate;
  S[v].s_rate=s.s_rate;

 siz=v+1;
  
 

}
fclose(fptr);

 
 do
 {
   cout<<"\n enter item code  ";
   cin>>id;
 int status=0;

 for(int r=0;r<siz;r++)
 {
   if(id==S[r].item_code)
  {  
    vendor.item_code[vendor.count]=id;

    cout<<vendor.item_code[vendor.count];

    cout<<"\n enter quantity  ";
    cin>>qty;
  vendor.qty[vendor.count]=qty;

  S[r].qty=S[r].qty+qty;

 cout<<vendor.qty[vendor.count];

  cout<<"\n enter purchase rate  ";
   cin>>rate;
  vendor.p_rate[vendor.count]=rate;
  S[r].p_rate=rate;

 cout<< vendor.p_rate[vendor.count];
  
  vendor.amount[vendor.count]=rate*qty;

  for(int a=0;(S[r].name[a])!='\0';a++) 
 vendor.name[vendor.count][a]=S[r].name[a];
 
 cout<<vendor.name[vendor.count];
 
     status=1;
  cout<<vendor.count;
  vendor.count++;
   
 
   }
 }
 if(status==0)
 cout<<"\nitem code not match";
 cout<<"\n enter c to continue  ";
 cin>>ch;

} while(ch=='c'||ch=='C');

  for(int k=0;k<vendor.count;k++)
vendor.t_amount=vendor.t_amount+vendor.amount[k];

 cout<<"\ntotal amount: ";
 cout.width(56);
 cout.precision(2);
 cout<<vendor.t_amount;
 cout<<"\n         VAT: ";
 cout.precision(2);
 cout<<vendor.vat;

 float x=(vendor.t_amount*vendor.vat)/100.0;   
 

 vendor.grand_total=vendor.t_amount+x;

 cout<<"\n grand total: ";
 cout.precision(2);
 cout<<vendor.grand_total;
 
 fptr=fopen("myfile","wb");

 if(fptr==NULL){
 printf("error in opening file ");
 exit(0);

}

 rewind(fptr);
 for(int i=0;i<siz;i++){

  fwrite(&S[i],sizeof(S[i]),1,fptr);
}

 fclose(fptr);

 fptr=fopen("myfile2","ab");

 if(fptr==NULL){
 printf("error in opening file ");
 exit(0);

}

 fwrite(&vendor,sizeof(vendor),1,fptr);

 fclose(fptr);


} break; //case 9 end


 case 10:{    //show vendor record

 Vendor vendor;
       cout<<"\n";
  cout<<"1: show all record\n";
  cout<<"2: specific customer record\n";
  cout<<"enter your choice  ";
  cin>>no;

 switch(no)
{
 case 1:{

  fptr=fopen("myfile2","rb");

 if(fptr==NULL){
 cout<<"\n error in opening file";
 exit(0);
}

   for(;;)
   { 

  fread(&vendor,sizeof(vendor),1,fptr);
  if(feof(fptr))
  break;

  cout<<"\nDate:"<<vendor.day<<"/"<<vendor.month<<"/"<<vendor.year;
   
   cout.width(20);
   cout<<vendor.v_name;

  cout.width(20);
   cout<<vendor.mob<<"\n";

  cout.width(10);
  cout<<"\n item code";
  cout.width(15);
  cout<<"item name";
  cout.width(15);
  cout<<"item Pur_rate";
  cout.width(15);
  cout<<"item P_qty" ;
  cout.width(15);
  cout<<"amount";

  for(int v=0;v<vendor.count;v++)
  {
   cout<<"\n";

   cout.width(10);
   cout<<vendor.item_code[v];

   cout.width(15);
   cout<<vendor.name[v];

   cout.width(15);
   cout<<vendor.p_rate[v];

   cout.width(15);
   cout<<vendor.qty[v];

   cout.width(15);
   printf("%15.2f",vendor.amount[v]);

   cout<<"\n";
  }// inner for loop end
 
cout<<"\n-----------------------------------------------------------------------------\n";
 cout<<"\ntotal amount: ";

 cout.width(56);
 cout.precision(2);
 printf("%56.2f",vendor.t_amount);

 cout<<"\n VAT: ";
 cout.precision(2);
 cout<<vendor.vat;

 cout<<"\n grand total: ";
 cout.precision(2);
 cout<<vendor.grand_total;

 cout<<"\n";
 } //outer for loop end

 fclose(fptr);

 } break; //case 1 end

 case 2: {
  char name1[20]; int flag=0;
 cout<<"\n enter customer name ";
 cin>>name1;
 
 fptr=fopen("myfile2","rb");

 if(fptr==NULL){
 cout<<"\n error in opening file";
 exit(0);
}

 for(;;)
   { 

 fread(&vendor,sizeof(vendor),1,fptr);
  if(feof(fptr))
  break;


  int x=strcmp(name1,vendor.v_name);

  if(!x)
 {
   flag=1;

  cout<<"\nDate:"<<vendor.day<<"/"<<vendor.month<<"/"<<vendor.year;
   
   cout.width(20);
   cout<<vendor.v_name;

  cout.width(20);
   cout<<vendor.mob;

  cout.width(10);
  cout<<"\n item code";
  cout.width(15);
  cout<<"item name";
  cout.width(15);
  cout<<"item Pur_rate";
  cout.width(15);
  cout<<"item P_qty" ;
  cout.width(15);
  cout<<"amount";

  for(int v=0;v<vendor.count;v++)
  {
   cout<<"\n";

   cout.width(10);
   cout<<vendor.item_code[v];

   cout.width(15);
   cout<<vendor.name[v];

   cout.width(15);
   cout<<vendor.p_rate[v];

   cout.width(15);
   cout<<vendor.qty[v];

   cout.width(15);
   cout<<vendor.amount[v];

   cout<<"\n";
  }// inner for loop end
 
cout<<"\n-----------------------------------------------------------------------------\n";
 cout<<"\ntotal amount: ";
 cout.width(56);
 cout.precision(2);
 cout<<vendor.t_amount;

 cout<<"\n VAT: ";
 cout.precision(2);
 cout<<vendor.vat;

 cout<<"\n grand total: ";
 cout.precision(2);
 cout<<vendor.grand_total;

 } //if end
 
 cout<<"\n";
 } //outer for loop end

 fclose(fptr);

 if(flag==0)
 cout<<"\n no match record found\n";

} break; //case 2 break

} //switch block end


} break; //case 6 end


 case 11:{      //profit count of item

 Pcount pc;
   
fptr=fopen("myfile3","rb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}


cout.width(10);
 cout<<"\n item code";
 cout.width(15);
 cout<<"item name";
 cout.width(15);
 cout<<"item qty";
 cout.width(15);
 cout<<"item profit" ;

 cout<<"\n";

 for( ;;){
 
 fread(&pc,sizeof(pc),1,fptr);
 if(feof(fptr))
 break;

 cout.width(10);
 cout<<pc.item_code;

 cout.width(15);
 cout<<pc.name;

 cout.width(15);
 cout<<pc.qty;

 cout.width(15);
 cout.precision(2);
 cout<<pc.profit;

 cout<<"\n";

}

fclose(fptr);


} break; //case 11 end


case 12:{
  Cash cash;
 
 fptr=fopen("myfile4","rb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}

 fread(&cash,sizeof(cash),1,fptr);
 cout<<"\nDATE : "<<cash.day<<"/"<<cash.month<<"/"<<cash.year<<"\n";

cout.precision(3);
cout<<"today cash collected :"<<cash.dcash;

cout.precision(3);
cout<<"\nmonthly cash collected :"<<cash.mcash;

cout.precision(3);
cout<<"\nyearly cash collected :"<<cash.ycash;
 
fclose(fptr);
cout<<"\n";
} break;   // case 12 end


 case 13:{

 Dsell dsell;
   
fptr=fopen("myfile5","rb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}


cout.width(10);
 cout<<"\n item code";
 cout.width(15);
 cout<<"item name";
 cout.width(15);
 cout<<"item qty";
 cout.width(15);
 cout<<"present day";

 cout<<"\n";

 for( ;;){
 
 fread(&dsell,sizeof(dsell),1,fptr);
 if(feof(fptr))
 break;

 cout.width(10); 
 cout<<dsell.item_code;

 cout.width(15);
 cout<<dsell.name;

 cout.width(15);
 cout<<dsell.qty;

 cout.width(15);
cout<<dsell.day;

 cout<<"\n";

}

fclose(fptr);

} break; // case 13 end

 case 14:{
Msell msell;
   
fptr=fopen("myfile6","rb");
 if(fptr==NULL){
 cout<<"\nerror in opening file";
 exit(1);
}


cout.width(10);
 cout<<"\n item code";
 cout.width(15);
 cout<<"item name";
 cout.width(15);
 cout<<"item qty";
 cout.width(15);
 cout<<"present month";

 cout<<"\n";

 for( ;;){
 
 fread(&msell,sizeof(msell),1,fptr);
 if(feof(fptr))
 break;

 cout.width(10); 
 cout<<msell.item_code;

 cout.width(15);
 cout<<msell.name;

 cout.width(15);
 cout<<msell.qty;

 cout.width(15);
 cout<<msell.month;


 cout<<"\n";

}

fclose(fptr);

} break; //case 14 end

 

default: cout<<"\n please select proper option";

}// switch block end

  cout<<"\n out of menu enter c to continue  ";
  cin>>che;
}while(che=='c'|| che=='C');


cout<<"\nprogram exit";
}















 
  