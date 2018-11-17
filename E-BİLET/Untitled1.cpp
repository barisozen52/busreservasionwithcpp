#include <stdio.h>
#include <conio.h>
//#include <stdlib.h>
#include <graphics.h>
//#include <string.h>

void grafik();
void doldur();
void getmouseclick();
void yazdirma(int[]);
void yazdir(int);


int son,ilk; //nerden nereye bilgisi alma*****
int yolcusayisi;
int tarih;//***********


int ucret=0;   //UCRET ÝÇÝN DEÐÝÞKENLER**********
int ucretkont=0;
int karsilastirma=0;//***************

struct guncelgecici //guncelleme için****
{
   int binis;
  int inis;
  int koltukno;
  char cinsiyet;    
         
}guncelgeciciler[5]; //****





struct gecici //seferler1.txt'deki bilgilerin hepsi karþýlaþtýmak için structa atýlýyo**** 
{
  int binis;
  int inis;
  int koltukNo;
  char cinsiyet;    
       
}geciciler[50];


struct koltuk
{
  int dizi[5][5];           
}koltuklar[14];


int renk[15];


  
    


int dolumu[14];//seferler dolumu boþmu kontrol için


 int toplamKayit;
 


int dizayn[15][4]=
{
 0,0,0,0,   
360,150,420,210, //1. koltuk
455,150,515,210, //2. koltuk
615,150,675,210, //3.koltuk
710,150,770,210, //4.koltuk
360,235,420,295, //5. koltuk  //TÜM KOLTUKLARIN KORDÝNATLARI  BÝR DÝZÝYE AKTARILIYO*********
455,235,515,295, //6.koltuk
615,235,675,295, //7.koltuk
710,235,770,295, //8.koltuk
360,320,420,380, //9.koltuk
455,320,515,380, //10. koltuk
360,405,420,465, 
455,405,515,465, 
615,405,675,465, 
710,405,770,465 
};




// önce ilk_bilgiler alýnacak
//daha sonra kontrolller..yani benim kodlar araya giricek
//daha sonra grafik fonksiyonu eklenecek...


int main() //MAÝN FONKSÝYONU
{
  
  initwindow(1000,700);
  
  getmouseclick();
  
  for(int i=1;i<=yolcusayisi;i++) //GUNCELLEME NERDEN NEREYE BÝLGÝSÝ ÝÇÝN
  {
    guncelgeciciler[i].binis=ilk;
    guncelgeciciler[i].inis=son;      
          
  }
  
  for(int i=1;i<=yolcusayisi;i++) //GUNCELLEME koltukno ve cinsiyeti sýfýrlamak için
  {
    guncelgeciciler[i].koltukno=0;
    guncelgeciciler[i].cinsiyet='Q';      
          
  }
  
  
   int yankont[14]; //yan koltukuðun kontrolü
   int tikmi[14];  //koltuða tiklandimi onu kontrol ediyo
   
   for(int i=1;i<15;i++)
   {
      yankont[i]=1;     
      tikmi[i]=0;     
   }
   
     
   
   
  int xx[14]; //isim,soyisim,telefon alma kýsmýna hangi koltuða týklandýysa oraya koltuk numarasýný ve cinsiyeti tutuyo
  
  for(int i=0;i<14;i++)
{
  xx[i]=10;      
        
}
  
  
  FILE *dosya1;
   
  dosya1=fopen("seferler.txt","r");
  
  
  FILE *dosya2;
  
  dosya2=fopen("seferler1.txt","r");
  
  FILE *dosya3;
  
  dosya3=fopen("seferler2.txt","r");
  
  
 if(ilk<son)  
  {
     
      for(int i=1;;i++) //TXT DEN ÇEKÝLEN VERÝNÝN UZUNLUÐU BULUNUYO VE TOPLAMKAYÝT A ATNÝYO
   {
     fscanf(dosya2,"%d %d %d %c",&geciciler[i].binis,&geciciler[i].inis,&geciciler[i].koltukNo,&geciciler[i].cinsiyet);     
          
      if(feof(dosya2))    
       {
           toplamKayit=i;
           break;                
       }   
   } 
  
                
  
    
  doldur();  
  
  



for(int i=1;i<15;i++)
{
  renk[i]=2;   //tüm koltuklarýn rengini boþalttým   
}
     
    
    
  for(int i=1;i<15;i++)//KOLTJK SAYISI
   {
           
         for(int n=1;n<toplamKayit;n++)
         {
            if(geciciler[n].koltukNo==i)
            {
              if(geciciler[n].binis<=ilk && ilk<geciciler[n].inis) //BEN ARABADAYKEN BENDEN ÖNCE BÝNÝP,BENÝM BÝNDÝÐÝM YERDEN ÖNCE ÝNMEDÝYSE
              {
                if(geciciler[n].cinsiyet=='E')
                {
                renk[geciciler[n].koltukNo]=1; //RENK MAVÝYE ATANIR
                dolumu[i]=1;
                }
                if(geciciler[n].cinsiyet=='B')
                {
                renk[geciciler[n].koltukNo]=5;
                dolumu[i]=1;
                } 
                
                
                 break;                               
              }
               else
            {
                if(ilk<geciciler[n].binis && geciciler[n].binis<son)
              {
                if(geciciler[n].cinsiyet=='E')
                 {
                renk[geciciler[n].koltukNo]=1;
                dolumu[i]=1;
                 }
                if(geciciler[n].cinsiyet=='B')
                  {
                renk[geciciler[n].koltukNo]=5;
                dolumu[i]=1;
                   } 
                
                
                 break;                               
              }  
                  
                  
            }
              
                        
              renk[i]=2;
              dolumu[i]=0;
              yankont[i]=0; //ÇÝFT BÝLETDE BAY BAYAN YAN YANA ÝÇÝN
                                        
            } 
                       
         }           
   }  
    
  }//**************************** 
  
  

if(ilk>son)  //ÝZMÝRDEN KOCAELÝ YÖNÜ ÝÇÝN
  {
     
      for(int i=1;;i++) //TXT DEN ÇEKÝLEN VERÝNÝN UZUNLUÐU BULUNUYO VE TOPLAMKAYÝT A ATNÝYO
   {
     fscanf(dosya3,"%d %d %d %c",&geciciler[i].binis,&geciciler[i].inis,&geciciler[i].koltukNo,&geciciler[i].cinsiyet);     
          
      if(feof(dosya3))    
       {
           toplamKayit=i;
           break;                
       }   
   } 
  
                
  
    
  doldur();  
  
  



for(int i=1;i<15;i++)
{
  renk[i]=2;      
}
     
    
 
    
    
  for(int i=1;i<15;i++)
   {
           
         for(int n=1;n<toplamKayit;n++)
         {
            if(geciciler[n].koltukNo==i)
            {
              if(geciciler[n].binis>=ilk && ilk>geciciler[n].inis)
              {
                if(geciciler[n].cinsiyet=='E')
                {
                renk[geciciler[n].koltukNo]=1;
                dolumu[i]=1;
                
                }
                if(geciciler[n].cinsiyet=='B')
                {
                renk[geciciler[n].koltukNo]=5;
                dolumu[i]=1;
               
                } 
                
                
                 break;                               
              }
               else
            {
                if(ilk>geciciler[n].binis && geciciler[n].binis>son)
              {
                if(geciciler[n].cinsiyet=='E')
                 {
                renk[geciciler[n].koltukNo]=1;
                dolumu[i]=1;
               
                 }
                if(geciciler[n].cinsiyet=='B')
                  {
                renk[geciciler[n].koltukNo]=5;
                dolumu[i]=1;
               
                   } 
                
                
                 break;                               
              }  
                  
                  
            }
              
                        
              renk[i]=2;
              dolumu[i]=0;
              yankont[i]=0;
                                        
            } 
                       
         }           
   }  
    
  } //BURDANNNNNNNNNNNNNNNNNNNNNNNNNNNNNN



    
  struct sefer
   {
      char tarih[11];
      char nerden[12];
      char nereye[12];
      char saat[5];
      int boskoltuk;
      char seferkodu[20];      
   }seferler[2];
   
int boskoltuk=14;

for(int i=1;i<15;i++)
{
  if(renk[i]!=2)
  {
    boskoltuk=boskoltuk-1;            
  }      
        
}
   
   
   for(int i=0;i<2;i++)
   {
      fscanf(dosya1,"%s %s %s %s %d %s",&seferler[i].tarih,&seferler[i].nerden,&seferler[i].nereye,&seferler[i].saat,&seferler[i].boskoltuk,&seferler[i].seferkodu);     
                            
   }
   
    outtextxy(20,445,"Seçimleriniz doðurultusunda gelen seferler");
   
   if(tarih==0 && ilk<son && yolcusayisi<=boskoltuk )
   {
        bar(20,480,90,505);
        outtextxy(25,485,"SEFER I");
        outtextxy(20,515,seferler[0].tarih);
        outtextxy(20,550,seferler[0].nerden);
        outtextxy(20,585,seferler[0].nereye);
        outtextxy(20,620,seferler[0].seferkodu);
        outtextxy(20,655,"Koltuk seçimine geçmek için sefer adýna týklayýn.");      
               
   }
   
   
   if(tarih==1 && yolcusayisi<=boskoltuk && ilk>son)
   {
               
         bar(20,480,90,505);
        outtextxy(25,485,"SEFER 2");
        outtextxy(20,515,seferler[1].tarih);
        outtextxy(20,550,seferler[1].nerden);
        outtextxy(20,585,seferler[1].nereye);
        outtextxy(20,620,seferler[1].seferkodu);
        
        outtextxy(20,655,"Koltuk seçimine geçmek için sefer adýna týklayýn.");
               
   }
   
 
 int hangisefer=1;;
 
  int say=1;
  int x,y;
                     do
                     {
                                        getmouseclick(WM_LBUTTONDOWN,x,y);
                                        for(int i=20;i<=90;i++)
                                        {
                                                for(int j=480;j<=505;j++)
                                                {        
                                                        if(x==i && y==j)                                  
                                                        {
                                                                hangisefer=0;
                                                                say=0;
                                                                  
                                                        }
                                                } 
                                        }
                     }while(say!=0);              
                     clearmouseclick(WM_LBUTTONDOWN);
   
   if(hangisefer==0)
   {
                    
   grafik();              
   } 
    
    
    
    
   x,y;
   int a,b;
  
   
   
  for(int ss=yolcusayisi-1;0<=ss;)
  {
   
   // BAYANA TIKLARSA
    say=1;
    
  do
     {
                                        getmouseclick(WM_LBUTTONDOWN,x,y);
                                        
                                        for(int i=455;i<=515;i++)
                                        {
                                                for(int j=10;j<=35;j++)
                                                {        
                                                        if(x==i && y==j)                                  
                                                        {
                                                                
                                                            b=0;//BAYAN BUTONUNA TIKLADI
                                                            say=0; 
                                                            
                                                                
                                                        }
                                                } 
                                        }
                                        
                                        for(int i=535;i<=575;i++)
                                        {
                                                for(int j=10;j<=35;j++)
                                                {        
                                                        if(x==i && y==j)                                  
                                                        {
                                                                
                                                            b=1;   //BAY BUTONUNA TIKLADI
                                                            say=0;
                                                              
                                                        }
                                                } 
                                        }
                                        
                                   
                                   if(ss!=yolcusayisi-1)
                                   {
                                    for(int i=595;i<=670;i++)
                                        {
                                                for(int j=10;j<=35;j++)
                                                {        
                                                        if(x==i && y==j)                                  
                                                        { 
                                                               
                                                            b=3; //DUZELT BUTONUNA TIKLADI
                                                            say=0; 
                                                                 
                                                        }
                                                } 
                                        }
                                              
                                        
                                    }    
                                        
                                        
     }while(say!=0); 
     
    clearmouseclick(WM_LBUTTONDOWN);         
 
 
 
  
 
 
 
  
 
 say=1;
 a=1;

        int p;
        
        
         
         
         do
          {
          
           getmouseclick(WM_LBUTTONDOWN,x,y);
            
           
                      for(p=1;p<15;p++)
                    { 
          
                                       
                                        for(int q=dizayn[p][0];q<=dizayn[p][2];q++)
                                        {                                                       //0   1   2   3
                                                for(int w=dizayn[p][1];w<=dizayn[p][3];w++)    //360,150,420,210,
                                                {      
                                                
                                                      
                                                        if(x==q && y==w)                              
                                                        {
                                                                
                                                              tikmi[p]=1;
                                                                
                                                            a=0; //HERHANGÝ BÝR KOLTUÐA TIKLADIYSA
                                                            say=0;
                                                            break;   
                                                        } 
                                                      
                                                } 
                                                
                                               if(say==0)
                                               break;
                                        }
                                        if(say==0)
                                         break;
                                          
                      }  
                                     
     }while(say!=0); 
     
     clearmouseclick(WM_LBUTTONDOWN);
 
         int c; 
                     
            if(p%2==0)                    //YANDAKÝ KOLTUÐUN DURUMU ÝÇÝNNNN
           {
                 c=renk[p-1];    
                     
           }
           else
           c=renk[p+1];   // 1 mavi erkek
                          //5 pembe bayan   
             
             
        if(yolcusayisi%2==1)
 {  //TEK BÝLET ÝÇÝN                  
                           
         if(c!=1 && dolumu[p]==0 && b==0 && a==0) //bayana ve gerekli koltuða týklandýysa
    {      
       guncelgeciciler[ss+1].koltukno=p; //guncelleme
       guncelgeciciler[ss+1].cinsiyet='B';  //guncelleme
           
        renk[p]=5; 
        xx[p]=0;   
        ss--;   
        
       
                      
    }     
         //C HARFÝ YANDAKÝ KOLTUÐUN RENGÝNÝ
    
    if( c!=5 && dolumu[p]==0 && b==1 && a==0) //baya ve gerekli koltuða týklandýysa
    {
         renk[p]=1;
         
       guncelgeciciler[ss+1].koltukno=p; //guncelleme
       guncelgeciciler[ss+1].cinsiyet='E'; //guncelleme
        
       
       xx[p]=1;
       ss--;           
    }     
    
    grafik();
    
}//TEK BÝLET ÝÇÝN   
    //DÜZELT
             
   
   
 if(yolcusayisi%2==0)
 {//ÇÝFT BÝLET ÝÇÝN
                     
       if(p%2==1 && yankont[p]==0 && yankont[p+1]==0 && tikmi[p]==1)
       {//DÝZAYN ÝÇÝN
             
             if(dolumu[p]==0 && b==0 && a==0) //bayana ve gerekli koltuða týklandýysa
              {   
                 guncelgeciciler[ss+1].koltukno=p; //guncelleme
                 guncelgeciciler[ss+1].cinsiyet='B'; //guncelleme
                          
             renk[p]=5;
             xx[p]=0;
             ss--;              
              } 
              
              if( dolumu[p]==0 && b==1 && a==0) //baya ve gerekli koltuða týklandýysa
             { 
                  renk[p]=1;
                  
                  guncelgeciciler[ss+1].koltukno=p; 
                 guncelgeciciler[ss+1].cinsiyet='E';  
                      
            
             xx[p]=1; 
             ss--;           
             }         
             
                          
       }//DÝZAYN ÝÇÝN
       else
       {//ELSE
           
         
         if(c!=1 && dolumu[p]==0 && b==0 && a==0) //bayana ve gerekli koltuða týklandýysa
       {      
          guncelgeciciler[ss+1].koltukno=p; 
          guncelgeciciler[ss+1].cinsiyet='B';
           
           
        renk[p]=5;
        xx[p]=0;
        ss--;              
       }     
         //C HARFÝ YANDAKÝ KOLTUÐUN RENGÝNÝ
    
    if( c!=5 && dolumu[p]==0 && b==1 && a==0) //baya ve gerekli koltuða týklandýysa
      {
              renk[p]=1;
              
       guncelgeciciler[ss+1].koltukno=p; 
       guncelgeciciler[ss+1].cinsiyet='E';
       
      
       xx[p]=1; 
        ss--;            
      }     
           
           
       }//ELSE
       
       
                     
                     
                     
 }//ÇÝFT BÝLET ÝÇÝN  
         
    
    
    
    if(b==3 && a==0 && xx[p]==0 || b==3 && a==0 && xx[p]==1 )
    {
      guncelgeciciler[ss].koltukno=0; //duzelt olursa koltukno ve cinsiyet o koltuk numarasaý için sýfýrlanýyo*****************************************************
      guncelgeciciler[ss].cinsiyet='Q';
      
      renk[p]=2;   
      xx[p]=5;
      ss++;   
    }
    
    grafik();
    
    
 }//WHÝLE ÝÇÝN
    
     fclose(dosya2);
     fclose(dosya3);
     
     yazdirma(xx);
    
   //GÜNCELLEMEE****** 
   
   setfillstyle(1,WHITE);
   bar(820,675,890,700);
   outtextxy(825,680,"BITIR");
   
   say=1;
   int aab=0;
   do
     {
                                      
                                        getmouseclick(WM_LBUTTONDOWN,x,y);
                                        for(int i=820;i<=890;i++)
                                        {
                                                for(int j=675;j<=700;j++)
                                                {
                                                        
                                                        if(x==i && y==j)                                  
                                                        {
                                                                  
                                                           aab=1;       
                                                                  
                                                                  say=0;
                                                        }
                                                        
                                                } 
                                        }      
     }while(say!=0);
   
   if(aab==1)
   {//aab
       
       
       struct yolcubilgi
   {
      char isim[20];
      char soyisim[20];
      char telefon[20];
      char cinsiyet[2];
                  
   }yolcubilgiler[6];
    
   if(ilk<son)  //1. tarih ve 1.sefer için güncelleme
   {
     dosya2=fopen("seferler1.txt","a");
     
     //sefer bilgileri için
     for(int i=1;i<=yolcusayisi;i++)
     {
       fprintf(dosya2,"%d %d %d %c\n",guncelgeciciler[i].binis,guncelgeciciler[i].inis,guncelgeciciler[i].koltukno,guncelgeciciler[i].cinsiyet);      
           
     }
               
       fclose(dosya2);
       
      //yolcu bilgileri giriþ baþý********* 
      
      FILE *gecici;
      FILE *yolcu1;
      
      gecici=fopen("yolcugiris.txt","r");
      yolcu1=fopen("yolcular1.txt","a");
      
     for(int i=1;i<=yolcusayisi;i++)
     {
        fscanf(gecici,"%s %s %s %s",&yolcubilgiler[i].isim,&yolcubilgiler[i].soyisim,&yolcubilgiler[i].telefon,&yolcubilgiler[i].cinsiyet); 
        fprintf(yolcu1,"%s %s %s %s\n",yolcubilgiler[i].isim,yolcubilgiler[i].soyisim,yolcubilgiler[i].telefon,yolcubilgiler[i].cinsiyet);    
             
     } 
     fclose(gecici);
     fclose(yolcu1);
     
     gecici=fopen("yolcugiris.txt","w");//yolcugiris.txt dosyasýnýn içini boþaltmak için
     fclose(gecici);
      //yolcubilgileri giriþ sonu******** 
               
   }
   if(ilk>son)
   {
      dosya3=fopen("seferler2.txt","a");
     
     for(int i=1;i<=yolcusayisi;i++)
     {
       fprintf(dosya2,"%d %d %d %c\n",guncelgeciciler[i].binis,guncelgeciciler[i].inis,guncelgeciciler[i].koltukno,guncelgeciciler[i].cinsiyet);      
             
     }        
     
     fclose(dosya3);
     
     
     //yolcu bilgileri giriþ baþý********* 
      
      FILE *gecici;
      FILE *yolcu2;
      
      gecici=fopen("yolcugiris.txt","r");
      yolcu2=fopen("yolcular2.txt","a");
      
     for(int i=1;i<=yolcusayisi;i++)
     {
        fscanf(gecici,"%s %s %s %s",&yolcubilgiler[i].isim,&yolcubilgiler[i].soyisim,&yolcubilgiler[i].telefon,&yolcubilgiler[i].cinsiyet); 
        fprintf(yolcu2,"%s %s %s %s\n",yolcubilgiler[i].isim,yolcubilgiler[i].soyisim,yolcubilgiler[i].telefon,yolcubilgiler[i].cinsiyet);    
             
     } 
     fclose(gecici);
     fclose(yolcu2);
     
     gecici=fopen("yolcugiris.txt","w");//yolcugiris.txt dosyasýnýn içini boþaltmak için
     fclose(gecici);
      //yolcubilgileri giriþ sonu********
                
   }
      
      
      closegraph();        
             
             
   }//aab
   
   
    
   //GUNCELLEME SON***********
   
   getch();
   //closegraph();  
    
}
//MAÝN SONU************





void grafik() //GRAFÝK FONKSÝYONU***
{
     
    
    
    
    for(int i=1;i<16;i++)
    {
       int j=0;
       
       setfillstyle(1,renk[i]);
       bar(dizayn[i][j],dizayn[i][j+1],dizayn[i][j+2],dizayn[i][j+3]);    
         
    } 
     
     
     
     circle(385,50,25);
     outtextxy(420,105,"MASA");
     outtextxy(675,105,"MASA");
     outtextxy(705,340,"KAPI");
     outtextxy(565,105,"K");
     outtextxy(565,155,"O");
     outtextxy(565,205,"R");
     outtextxy(565,255,"I");
     outtextxy(565,305,"D");
     outtextxy(565,355,"O");
     outtextxy(565,405,"R");
     setcolor(WHITE);
     
     moveto(350,0);lineto(350,605); moveto(350,605);lineto(780,605); moveto(780,605);lineto(780,0); moveto(780,0);lineto(350,0);// beyaz köþeli ekran
     moveto(400,475);lineto(400,605); moveto(400,605);lineto(780,605); moveto(780,605);lineto(780,475); moveto(780,475);lineto(400,475);// bilgi köþesi
     setfillstyle(1,MAGENTA);
     bar(455,10,515,35);
     setfillstyle(1,BLUE);
     bar(535,10,575,35);
     setfillstyle(1,GREEN);
     bar(595,10,670,35);
     
     outtextxy(460,15,"BAYAN"); 
     outtextxy(540,15,"BAY"); 
     outtextxy(605,15,"DÜZELT");
     outtextxy(405,485,"Seçimleri yaparken önce cinsiyete sonra koltuða týklayýn.");
     outtextxy(405,505,"Yeþil koltuk boþ olan koltuðu gösterir.");
     outtextxy(405,525,"Pembe koltukta bayanýn oturduðunu gösterir.");
     outtextxy(405,545,"Mavi koltukta bayýn oturduðunu gösterir.");
     outtextxy(405,565,"Hatalý iþlem yapýldýðýnda düzeltmek için düzelte basýn.");  
       
     
     moveto(360,100);lineto(360,125);moveto(360,125);lineto(515,125); moveto(515,125);lineto(515,100); moveto(515,100);lineto(360,100); //masa sol
    
     
     
     moveto(360,150);lineto(360,210);moveto(360,210);lineto(420,210); moveto(420,210);lineto(420,150); moveto(420,150);lineto(360,150);   
     moveto(455,150);lineto(455,210);moveto(455,210);lineto(515,210); moveto(515,210);lineto(515,150); moveto(515,150);lineto(455,150);
     moveto(360,235);lineto(360,295);moveto(360,295);lineto(420,295); moveto(420,295);lineto(420,235); moveto(420,235);lineto(360,235);
     moveto(455,235);lineto(455,295);moveto(455,295);lineto(515,295); moveto(515,295);lineto(515,235); moveto(515,235);lineto(455,235);
     moveto(360,320);lineto(360,380);moveto(360,380);lineto(420,380); moveto(420,380);lineto(420,320); moveto(420,320);lineto(360,320);
     moveto(455,320);lineto(455,380);moveto(455,380);lineto(515,380); moveto(515,380);lineto(515,320); moveto(515,320);lineto(455,320);
     moveto(360,405);lineto(360,465);moveto(360,465);lineto(420,465); moveto(420,465);lineto(420,405); moveto(420,405);lineto(360,405);
     moveto(455,405);lineto(455,465);moveto(455,465);lineto(515,465); moveto(515,465);lineto(515,405); moveto(515,405);lineto(455,405);
     
     
     moveto(615,100);lineto(615,125);moveto(615,125);lineto(770,125); moveto(770,125);lineto(770,100); moveto(770,100);lineto(615,100);  //masa sað
     
     moveto(615,150);lineto(615,210);moveto(615,210);lineto(675,210); moveto(675,210);lineto(675,150); moveto(675,150);lineto(615,150);   
     moveto(710,150);lineto(710,210);moveto(710,210);lineto(770,210); moveto(770,210);lineto(770,150); moveto(770,150);lineto(710,150);
     moveto(615,235);lineto(615,295);moveto(615,295);lineto(675,295); moveto(675,295);lineto(675,235); moveto(675,235);lineto(615,235);
     moveto(710,235);lineto(710,295);moveto(710,295);lineto(770,295); moveto(770,295);lineto(770,235); moveto(770,235);lineto(710,235);
     
     moveto(675,320);lineto(675,380);moveto(675,380);lineto(770,380); moveto(770,380);lineto(770,320); moveto(770,320);lineto(675,320); //kapý 
     
     moveto(615,405);lineto(615,465);moveto(615,465);lineto(675,465); moveto(675,465);lineto(675,405); moveto(675,405);lineto(615,405);
     moveto(710,405);lineto(710,465);moveto(710,465);lineto(770,465); moveto(770,465);lineto(770,405); moveto(770,405);lineto(710,405);
     
     
     
} //GRAFÝK() SONU********


void doldur()
{
   for(int p=0;p<12;p++)//p koltuk sayisi
      {
        for(int a=0;a<5;a++)//a,biniþ için
        {
          for(int z=0;z<5;z++)//z iniþ için
          {
               koltuklar[p].dizi[a][z]=1;          
                  
          }      
                
        }      
     }              
     
}


void getmouseclick()
{
     int x=0,y=0;
     int say;
     char dizi[10];
    
     
     int binis[6][4]={
     0,0,0,0,
     20,75,80,100,
     20,110,70,135,
     20,145,90,170,
     20,180,80,205,
     20,215,65,240,
     };
     int inis[6][4]={
     0,0,0,0,
     100,75,160,100,
     100,110,150,135,
     100,145,170,170,
     100,180,160,205,
     100,215,145,240,
     };
     
     int yolcu[6][4]={
     0,0,0,0,
      20,410,40,435,
      50,410,70,435,
      80,410,100,435,
      110,410,130,435,
      140,410,160,435,
      
     };
     

     outtextxy(20,10,"Bilgilere ulasmak icin yazýlarýn üzerisine tiklayin");
     setfillstyle(1,WHITE);
     bar(20,30,70,55);
     outtextxy(25,35,"BÝNÝS");
     do
     {
                                        getmouseclick(WM_LBUTTONDOWN,x,y);
                                        for(int i=20;i<=70;i++)
                                        {
                                                for(int j=30;j<=55;j++)
                                                {        
                                                        if(x==i && y==j)                                  
                                                        {
                                                                  bar(20,75,80,100);
                                                                  outtextxy(25,80,"kocaeli");
                                                                  bar(20,110,70,135);
                                                                  outtextxy(25,115,"bursa");
                                                                  bar(20,145,90,170);
                                                                  outtextxy(25,150,"balikesir");
                                                                  bar(20,180,80,205);
                                                                  outtextxy(25,185,"manisa");
                                                                  bar(20,215,65,240);
                                                                  outtextxy(25,220,"izmir"); 
                                                                  say=0;
                                                                  
                                                        }
                                                } 
                                        }
     } 
     while(say!=0);
     clearmouseclick(WM_LBUTTONDOWN);  
     say=1;                                                     
     do{
                                      getmouseclick(WM_LBUTTONDOWN,x,y);
                                      for(int i=1;i<6;i++)
                                      {
                                              for(int j=binis[i][0];j<=binis[i][2];j++)
                                              {
                                                   for(int k=binis[i][1];k<=binis[i][3];k++)
                                                   {
                                                       if(x==j && y==k)    
                                                       {
                                                               ilk=i-1;
                                                               say=0;
                                                               break;
                                                       }
                                                   }
                                              }if(say==0)
                                              break;
                                      }if(say==0)
                                      break;                 
     }while(say!=0);  
     clearmouseclick(WM_LBUTTONDOWN);
     bar(100,30,140,55);
     outtextxy(105,35,"ÝNÝS");
     do
     {
                                        say=1;
                                        getmouseclick(WM_LBUTTONDOWN,x,y);
                                        for(int i=100;i<=140;i++)
                                        {
                                                for(int j=30;j<=55;j++)
                                                {
                                                        
                                                        if(x==i && y==j)                                  
                                                        {
                                                                  bar(100,75,160,100);
                                                                  outtextxy(105,80,"kocaeli");
                                                                  bar(100,110,150,135);
                                                                  outtextxy(105,115,"bursa");
                                                                  bar(100,145,170,170);
                                                                  outtextxy(105,150,"balikesir");
                                                                  bar(100,180,160,205);
                                                                  outtextxy(105,185,"manisa");
                                                                  bar(100,215,145,240);
                                                                  outtextxy(105,220,"izmir");
                                                                  say=0; 
                                                        }
                                                } 
                                        }      
     }
     while(say!=0);
     clearmouseclick(WM_LBUTTONDOWN);
     say=1;
     do{
                                     getmouseclick(WM_LBUTTONDOWN,x,y);
                                      for(int i=1;i<6;i++)
                                      {
                                              for(int j=inis[i][0];j<=inis[i][2];j++)
                                              {
                                                   for(int k=inis[i][1];k<=inis[i][3];k++)
                                                   {
                                                       if(x==j && y==k)    
                                                       {
                                                               son=i-1;
                                                               say=0;
                                                               break;
                                                       }
                                                   }
                                              }if(say==0)
                                              break;
                                      }if(say==0)
                                      break;       
     }while(say!=0);
     clearmouseclick(WM_LBUTTONDOWN);
     bar(20,260,195,285);
     outtextxy(25,265,"Bilet alýnabilecek tarihler");
     do
     {
                                        say=1;
                                        getmouseclick(WM_LBUTTONDOWN,x,y);
                                        for(int i=20;i<=180;i++)
                                        {
                                                for(int j=260;j<=285;j++)
                                                {
                                                        
                                                        if(x==i && y==j)                                  
                                                        {
                                                                  bar(20,300,100,325);
                                                                  outtextxy(25,305,"20.11.2013");
                                                                  bar(20,335,100,360);
                                                                  outtextxy(25,340,"21.11.2013");
                                                                  say=0;
                                                        }
                                                        
                                                } 
                                        }      
     }while(say!=0);
     do{             
                                        say=1;
                                        getmouseclick(WM_LBUTTONDOWN,x,y);
                                        for(int i=20;i<=100;i++)//-----ÝLK TARÝH KOORDÝNATLARI----//
                                        {
                                                for(int j=300;j<=325;j++)
                                                {
                                                        
                                                        if(x==i && y==j)                                  
                                                        {
                                                                tarih=0;
                                                                say=0;     
                                                        }
                                                } 
                                        }
                                        for(int i=20;i<=100;i++)//-----ÝKÝNCÝ TARÝH KOORDÝNATLARI----//
                                        {
                                                for(int j=335;j<=360;j++)
                                                {
                                                        
                                                        if(x==i && y==j)                                  
                                                        {
                                                                tarih=1; 
                                                                say=0;    
                                                        }
                                                } 
                                        }
     }while(say!=0);
     clearmouseclick(WM_LBUTTONDOWN);
     bar(20,375,165,400);
     outtextxy(25,380,"Alinacak bilet sayisi");
    do	
    {
                                say=1;
                                getmouseclick(WM_LBUTTONDOWN,x,y);
                                        for(int i=20;i<=165;i++)
                                        {
                                                for(int j=375;j<=400;j++)
                                                {
                                                        
                                                        if(x==i && y==j)                                  
                                                        {
                                                                bar(20,410,40,435);
                                                                outtextxy(25,415,"1");
                                                                bar(50,410,70,435);
                                                                outtextxy(55,415,"2");
                                                                bar(80,410,100,435);
                                                                outtextxy(85,415,"3");
                                                                bar(110,410,130,435);
                                                                outtextxy(115,415,"4");
                                                                bar(140,410,160,435);
                                                                outtextxy(145,415,"5");
                                                                say=0;
                                                        }
                                                } 
                                        }
    }while(say!=0);
    clearmouseclick(WM_LBUTTONDOWN);
    say=1;
     do{             
                                        
                                        getmouseclick(WM_LBUTTONDOWN,x,y);
                                      for(int i=1;i<6;i++)
                                      {
                                              for(int j=yolcu[i][0];j<=yolcu[i][2];j++)
                                              {
                                                   for(int k=yolcu[i][1];k<=yolcu[i][3];k++)
                                                   {
                                                       if(x==j && y==k)    
                                                       {
                                                               yolcusayisi=i;
                                                               say=0;
                                                               break;
                                                       }
                                                   }
                                              }if(say==0)
                                              break;
                                      }if(say==0)
                                      break;    
                                        
     }while(say!=0);
     
     
       
}   


void yazdir(int sayar)
{  
     
   FILE *fp;
   fp=fopen("yolcugiris.txt","a");
  char pr[400];
  char b[100]={},*ptr;  
  char dizi[100],*pon;
  int yazibar[16][4]={
      0,0,0,0,
      850,0,960,25,
      880,30,980,55,
      890,60,990,85, 
      //2.YOLCU
      850,120,960,145,
      880,150,980,175,
      890,180,990,205,   
      //3.YOLCU
      850,240,960,265,
      880,270,980,295,
      890,300,990,325,   
      //4.YOLCU
      850,360,960,385,
      880,390,980,415,
      890,420,990,445,   
      //5.YOLCU
      850,480,960,505,
      880,510,980,535,
      890,540,990,565,  
                        
  };
  int k=0;
  int w=1;
  int t=2,u=3;
  int say=1,sayac=0;
  ptr=b;
  pon=dizi;
  if(sayar==6 || sayar==7 || sayar==8)
  {
              w=4; t=5; u=6;
  }
  if(sayar==11 || sayar==12 || sayar==13)
  {
              w=7; t=8; u=9;
  }
  if(sayar==16 || sayar==17 || sayar==18)
  {
              w=10; t=11; u=12;
  }
  if(sayar==21 || sayar==22 || sayar==23)
  {
              w=13; t=14; u=15;
  }
  
           while(say!=0)
          {
                       ptr=ptr+k;              
                       b[k]=getch();
                      if(sayar==1 || sayar==6 || sayar==11 || sayar==16 || sayar==21)
                      {
                                  outtextxy(yazibar[w][0]+5,yazibar[w][1]+5,b);
                      }
                      if(sayar==2 || sayar==7 || sayar==12 || sayar==17 || sayar==22)
                      {
                                  outtextxy(yazibar[t][0]+5,yazibar[t][1]+5,b);
                      }
                      if(sayar==3 || sayar==8 || sayar==13 || sayar==18 || sayar==23)
                      {
                                  outtextxy(yazibar[u][0]+5,yazibar[u][1]+5,b);
                      }
                       
                       if(b[k]==13)
                       {
                                   say=0;
                       }    
                       else if(b[k]!=13)
                       {
                            sayac++;
                       }    
                      k=k+1;
          } 
          for(int i=0;i<=sayac;i++)
          {
                  strcpy(dizi,b);
                  fprintf(fp,"%c",dizi[i]); 
          }
          fprintf(fp," ");
          if(sayar==3 || sayar==8 || sayar==13 || sayar==18 || sayar==23)
          {
                      fprintf(fp,"\n");
          }
  fclose(fp);
}

void yazdirma( int cinskoltuk[14])
{
     int textbar[31][2]={
     0,0,
     795,5,
     795,35,
     795,65,
     795,95,
     890,95,
     955,95,
     //2.YOLCU
     795,125,
     795,155,
     795,185,
     795,215,
     890,215,
     955,215,
     //3.YOLCU
     795,245,
     795,275,
     795,305,
     795,335,
     890,335,
     955,335,
     //4.YOLCU
     795,365,
     795,395,
     795,425,
     795,455,
     890,455,
     955,455,
     //5.YOLCU
     795,485,
     795,515,
     795,545,
     795,575,
     890,575,
     955,575,
     };
     int sayac=1;
     int say=0;
     int yolcusayaci=1;
     int x,y;
     int cinsiyet[4];
     int yolcubar[26][4]={
      0,0,0,0,
      850,0,960,25,
      880,30,980,55,
      890,60,990,85,   
      885,90,940,115,   
      950,90,990,115, 
      //2.YOLCU
      850,120,960,145,
      880,150,980,175,
      890,180,990,205,   
      885,210,940,235,   
      950,210,990,235, 
      //3.YOLCU
      850,240,960,265,
      880,270,980,295,
      890,300,990,325,   
      885,330,940,355,   
      950,330,990,355,
      //4.YOLCU
      850,360,960,385,
      880,390,980,415,
      890,420,990,445,   
      885,450,940,475,   
      950,450,990,475,
      //5.YOLCU
      850,480,960,505,
      880,510,980,535,
      890,540,990,565,   
      885,570,940,595,   
      950,570,990,595,   
  };
  
     int say1=0,say2=0;
     int say1kont=0,say2kont=0;
     for(int r=1;r<=14;r++)
     {
             printf("\ncinskoltuk[%d]=%d",r,cinskoltuk[r]);
             if(cinskoltuk[r]==1)
             {
                                 say1++;
             }
             if(cinskoltuk[r]==0)
             {
                                 say2++;
             }
     }
     FILE *fp;
     fp=fopen("yolcugiris.txt","a");
     int j=1;
     int i=1;
   for(yolcusayaci=1;yolcusayaci<=yolcusayisi;yolcusayaci++)  
   {                 
                     sayac=1;
                                                             
                                 if(yolcusayaci==2)
                                 { j=6;i=7;
                                 }
                                 if(yolcusayaci==3)
                                 { j=11;i=13;
                                 }  
                                 if(yolcusayaci==4)
                                 { j=16;i=19;
                                 }  
                                 if(yolcusayaci==5)
                                 { j=21;i=25;
                                 }    
                               
                                setfillstyle(1,WHITE);
                                setbkcolor(BLACK);
                                 outtextxy(textbar[i][0],textbar[i][1],"Adýnýz:");
                                 
                                 bar(yolcubar[j][0],yolcubar[j][1],yolcubar[j][2],yolcubar[j][3]);
                                 say=j;
                                 yazdir(say); 
                                 outtextxy(textbar[i+1][0],textbar[i+1][1],"Soyadiniz:");
                                 
                                 bar(yolcubar[j+1][0],yolcubar[j+1][1],yolcubar[j+1][2],yolcubar[j+1][3]);
                                 say=j+1;
                                 yazdir(say);
                                 outtextxy(textbar[i+2][0],textbar[i+2][1],"Telefonunuz:");
                                 
                                 bar(yolcubar[j+2][0],yolcubar[j+2][1],yolcubar[j+2][2],yolcubar[j+2][3]);
                                 say=j+2;
                                 yazdir(say);
                                 
                                 outtextxy(textbar[i+3][0],textbar[i+3][1],"Cinsiyetiniz:");
                                 
                                 bar(yolcubar[j+3][0],yolcubar[j+3][1],yolcubar[j+3][2],yolcubar[j+3][3]);
                                 
                                 bar(yolcubar[j+4][0],yolcubar[j+4][1],yolcubar[j+4][2],yolcubar[j+4][3]); 
                                 
                                 outtextxy(textbar[i+4][0],textbar[i+4][1],"BAYAN");
                                 outtextxy(textbar[i+5][0],textbar[i+5][1],"BAY");
                                 
                                 do
                                 {
                                                                                 
                                                         getmouseclick(WM_LBUTTONDOWN,x,y);
                                                        if(say2!=say2kont) 
                                                         {
                                                                           for(int k=yolcubar[j+3][0];k<=yolcubar[j+3][2];k++)
                                                                           {
                                                                                   for(int w=yolcubar[j+3][1];w<=yolcubar[j+3][3];w++)
                                                                                   {
                                                                                           if(x==k && y==w)                                  
                                                                                           {
                                                                                                   cinsiyet[yolcusayaci]=0;
                                                                                                   sayac=0; 
                                                                                                   say2kont++;
                                                                                           }
                                                                                   } 
                                                                           }
                                                         }
                                                        if(say1!=say1kont) 
                                                         {                   
                                                                           for(int w=yolcubar[j+4][0];w<=yolcubar[j+4][2];w++)
                                                                           {
                                                                                   for(int k=yolcubar[j+4][1];k<=yolcubar[j+4][3];k++)
                                                                                   {        
                                                                                            if(x==w && y==k)                                  
                                                                                            {
                                                                                                    cinsiyet[yolcusayaci]=1;
                                                                                                    sayac=0;
                                                                                                    say1kont++;
                                                                                            }
                                                                                   } 
                                                                           }
                                                         }
                                 } 
                                 while(sayac!=0);
                                
                                karsilastirma=ilk-son;
                     if(karsilastirma==1 || karsilastirma==-1)
                     {
                                         ucretkont=10;
                                         ucret=ucretkont*yolcusayisi;
                     }
                     if(karsilastirma==2 || karsilastirma==-2)
                     {
                                         ucretkont=30;
                                         ucret=ucretkont*yolcusayisi;
                     }
                     if(karsilastirma==3 || karsilastirma==-3)
                     {
                                         ucretkont=50;
                                         ucret=ucretkont*yolcusayisi;
                     }
                     if(karsilastirma==4 || karsilastirma==-4)
                     {
                                         ucretkont=80;
                                         ucret=ucretkont*yolcusayisi;
                     } 
                                 
                                 if(yolcusayisi==yolcusayaci)
           {
                                 outtextxy(795,625,"iþlemi bitirmek için");
                                 outtextxy(795,650,"bitir butonuna basýnýz");
           
                                 
                                 
                                       if(ucret==10)
                                       outtextxy(795,605,"ÜCRET:10.00TL");
                                       else if(ucret==20)
                                       outtextxy(795,605,"ÜCRET:20.00TL");
                                       else if(ucret==30)
                                       outtextxy(795,605,"ÜCRET:30.00TL");
                                       else if(ucret==40)
                                       outtextxy(795,605,"ÜCRET:40.00TL");
                                       else if(ucret==50)
                                       outtextxy(795,605,"ÜCRET:50.00TL");
                                       
                                       else if(ucret==30)
                                       outtextxy(795,605,"ÜCRET:30.00TL");
                                       else if(ucret==60)
                                       outtextxy(795,605,"ÜCRET:60.00TL");
                                       else if(ucret==90)
                                       outtextxy(795,605,"ÜCRET:90.00TL");
                                       else if(ucret==120)
                                       outtextxy(795,605,"ÜCRET:120.00TL");
                                       else if(ucret==150)
                                       outtextxy(795,605,"ÜCRET:150.00TL");
                                       
                                       
                                       else if(ucret==50)
                                       outtextxy(795,605,"ÜCRET:50.00TL");
                                       else if(ucret==100)
                                       outtextxy(795,605,"ÜCRET:100.00TL");
                                       else if(ucret==150)
                                       outtextxy(795,605,"ÜCRET:150.00TL");
                                       else if(ucret==200)
                                       outtextxy(795,605,"ÜCRET:200.00TL");
                                       else if(ucret==250)
                                       outtextxy(795,605,"ÜCRET:250.00TL");
                                       
                                       else if(ucret==80)
                                       outtextxy(795,605,"ÜCRET:80.00TL");
                                       else if(ucret==160)
                                       outtextxy(795,605,"ÜCRET:160.00TL");
                                       else if(ucret==240)
                                       outtextxy(795,605,"ÜCRET:240.00TL");
                                       else if(ucret==320)
                                       outtextxy(795,605,"ÜCRET:320.00TL");
                                       else if(ucret==400)
                                       outtextxy(795,605,"ÜCRET:400.00TL");
                        
         }               

                                 
   }  
             
          
     fclose(fp);
}



