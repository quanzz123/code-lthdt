#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void Nhaphienchuoi(char s[100])
{
	cout << "Nhap chuoi : ";
	fflush(stdin);
	gets(s);
	cout <<endl<< "Chuoi vua nhap : "<<endl;
	puts(s);
}
void Nhapchuoimoi(char a[50])
{
    cout<<endl<<" Nhap chuoi moi :";
    fflush(stdin);
    gets(a);
}
bool So(char a)
{
	if(a>= '0' && a<= '9')
			return true;
	return false;
}
bool Chuhoa(char b)
{
	if(b>='Z' && b <='A')
		return true;
	return false;
}
bool Chuthuong(char c)
{
	if(c >= 'z' && c <= 'a')
		return true;
	return false;
}
void Tongso(char s[100])
{
	int n = strlen(s);
	int sum =0; // sum la tong
	for(int i=0;i<n;i++)
		if(So(s[i])==true)
			sum = sum + (s[i]-48);
    cout<<sum<<endl;
}
void Chuanhoathanhchuhoa(char s[100])
{
	for(int i=0;i<strlen(s);i++)
	{
		if(Chuhoa(s[i]))
			s[i]=tolower(s[i]);
			//s[i]= s[i] -65;
	}
   puts(s);
}
void Chuanthuongthanhchuhoa(char s[100])
{
	for(int i=0;i<strlen(s);i++)
	{
		if(Chuthuong(s[i]))
			s[i]=toupper(s[i]);
	}
   puts(s);
}
void Xoakytu(char s[100],int vt)
{
	int n= strlen(s);
	for(int i=vt;i<n;i++)
	{
         s[i]=s[i+1];
	}
	n--;
}
void Xoadaucachgiua(char s[100])
{
   for(int i=0;i<strlen(s);i++)
     if(s[i]==32 && s[i+1]==32)
        {
          Xoakytu(s,i);
        }
}
void Xoadaucachdau(char s[100])
{
	int n= strlen(s);
	int dem=0;
   for(int i=0;i<strlen(s);i++)
      {
      	if(s[i]==32)
      	 dem++;
        else if(s[i]!=32)
         break;
      }
   for(int i=0;i<n;i++)
	{
         s[i]=s[i+dem];
	}
	n--;
}
void Xoadaucachcuoi(char s[100])
{
   int n = strlen(s);
   int dem=0;
   for(int i=n;i>=0;i++)
     {
       if(s[i]==32)
      	 dem++;
       else if(s[i]!=32)
         break;
     }
    for(int i=0;i<n;i++)
	{
         s[i]=s[i+dem];
	}
	n--;
}
void Timchuoi(char s[100],char a[50])
{
    int dem=0;
    for( int i=0; i<strlen(s); i++)
      for(int j=0;j<strlen(a);j++)
          if(a[j]==s[i])
            {
               cout<<i;
               dem++;
            }
    cout<<dem;
}
void Chuanten(char s[100])
{
	s[0]=toupper(s[0]);
	for(int i=1;i<strlen(s);i++)
	{
		if(s[i-1]==32)
		  s[i]=toupper(s[i]);
		else
		   s[i]=tolower(s[i]);
	}
}
void SoOthanhkhong(char s[100])
{
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]==48)
			cout<<"Khong";
		else
			cout<<s[i];
	}
}
void Hiennguoc(char s[100])
{
	int n=strlen(s);
	for(int i=n-1;i>=0;i--)
		{
		 cout<<s[i];
		}
}
bool Xauchuan(char s[100])
{
	int n = strlen(s);
	if(s[0]==32 && s[n-1]==32)
		return false;
	else
	{
		for(int i=1;i<n-1;i++)
			if(s[i]==32 && s[i+1]==32)
				return false;
	}
	return true;
}
void Demkytuchuso(char s[100])
{
	int chuhoa=0;
	int chuso=0;
   for(int i=0;i<strlen(s);i++)
   {
   	 if(So(s[i]))
   	 	chuso++;
   	 else if(Chuhoa(s[i]))
   	 	chuhoa++;
   }
   cout<<chuhoa<<endl;
   cout<<chuso<<endl;
}
bool Xaudoixung(char s[100])
{
	int n = strlen(s);
	int i=0;
	int j=n-1;
	for(i=0,j=n-1;i<=j;i++,j--)
		if(s[i]!=s[j])
		{
			return false;
		}
   return true;
}
void Demtu(char s[100],char a[50])
{
	int k = strlen(a);
    int n = strlen(s)-k;
    int dem=0;
    for(int i=0; i<=n; i++)
    {
        int j =0;
        while (j<k&&s[i+j]==a[j])j++;
        if(j==k)
        {
            dem++;
            cout << "Vi tri "<<i+1<<endl;

        }
    }
    cout <<dem<<endl;
}
/*void Vitri(int p)
{
	cout << "Vi tri : ";cin>>p;
}*/
void Chenchuoi(char s[100],char a[50])
{
	/// chen o vi tri bat ki
	int p;
    cout << "\n Nhap vi tri can chen : ";cin>>p;
    int n=strlen(s);
    if(p>n) p=n;
    int m=strlen(a);
     for(int i=n;i>=p;i--)  /// Vi tri muon chen
        s[i+m]=s[i];
     for(int i=0;i<m;i++)  /// Chuoi can chen
        s[p+i]=a[i];
}
void Chendauxau(char s[100],char a[50]) 
{
    int m=strlen(s);
    int l=strlen(a);
     for(int i=m;i>=0;i--) /// Vi tri muon chen
        s[i+l]=s[i];
     for(int i=0;i<l;i++) /// Chuoi can chen
        s[i]=a[i];
}
void Chencuoixau(char s[100],char a[50])
{
    int m=strlen(s);
    int l=strlen(a);
     for(int i=m;i>=m;i--)  /// Vi tri muon chen
        s[i+l]=s[i];
     for(int i=0;i<l;i++)  /// Chuoi can chen
        s[m+i]=a[i];
}
void Hamxoa(char s[100],int p,int n )
{
    int m=strlen(s);
    if(p+n>m)s[p]='\0';
    else
    {
        for(int i=p+n;i<=m;i++)
            s[i-n]=s[i];
    }
}
void Xoachuoi(char s[100],char a[50])
{
    int k = strlen(a);
    int n = strlen(s)-k;
    int i =0;
    while(i<=n)
    {
        int j =0;
        while (j<k&&s[i+j]==a[j])
            j++;
        if(j==k)
        {
          Hamxoa(s,i,k);
          n-=k;
        }
        i++;
    }
}

int main ()
{
   char s[100];
   char a[50];
 //  int p;
   Nhaphienchuoi(s);
   Nhapchuoimoi(a);
 //  Vitri(p);
  // Tongso(s);

  ///Bộ chuẩn hóa chuỗi
  /// {
        //Chuanhoathanhchuhoa(s);
        //Chuanthuongthanhchuhoa(s);
        // Xoadaucachgiua(s);
        // Xoadaucachdau(s);
        //Xoadaucachcuoi(s);
        //Chuanten(s);
   /// }

   //Timchuoi(s,a);
   //SoOthanhkhong(s);
   //Hiennguoc(s);

  /// Kiem tra Xau chuan :
   ///{
       //if(Xauchuan(s))
       	//cout<<"Xuau Chuan"<<endl;
       //else
       	//cout <<"Khong Phai Xau Chuan"<<endl;
   ///}
  //Demkytuchuso(s);

   /// Kiem tra Xau doi xung :
   ///{
       //if(Xaudoixung(s))
       	//cout<<"Xuau Doi Xung"<<endl;
       //else
       //	cout <<"Khong Phai Xau Doi Xung"<<endl;
   ///}
   //Demtu(s,a);
    
    ///Cac the loai chen chuoi
    //Chenchuoi(s,a); /// (chen o vi tri bat ki)
    //Chendauxau(s,a);
    //Chencuoixau(s,a);

    
    //Xoachuoi(s,a); // (xoa o vi tri bat ki)
     

    puts(s);
	return 0;
}
