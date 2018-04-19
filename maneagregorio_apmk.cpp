#include<fstream>
#include<iostream>
using namespace std;

int G[100][3];
int n;
int L[100];

int m;

int read_data()
{fstream f;
f.open("ApmKruskalInputData.txt",ios::in);
f>>n;
m=0;
while (!f.eof()) {
                         m++;
                        f>>G[m][1];
                        f>>G[m][2];
                        f>>G[m][3];
                        }m--;}

int sort_data()
{
int sorted=0;
int last=m-1;
while (!sorted)
    {
        sorted=1;
        for(int i=1;i<=last;i++)
            {
                int minim3=G[i][3];
                int minim2=G[i][2];
                int minim1=G[i][1];
                int loc=i;
                int k;
                for(k=i+1;k<=last+1;k++)
                    {
                        if(G[k][3]<minim3)
                        {
                            minim3=G[k][3];
                            minim2=G[k][2];
                            minim1=G[k][1];
                            loc=k;
                        }
                    }
                int aux=G[i][3];
                G[i][3]=minim3;
                G[loc][3]=aux;
                aux=G[i][2];
                G[i][2]=minim2;
                G[loc][2]=aux;
                aux=G[i][1];
                G[i][1]=minim1;
                G[loc][1]=aux;
            }
    }
}

int init_data()
{for(int i=1;i<=n;i++)  L[i]=i;}

int compute_APM()
{
sort_data();
cout<<" Nodes : "<<n<<" Edges  : "<<m;
for(int i=1;i<=m;i++) cout<<endl<<G[i][1]<<"-"<<G[i][2]<<"="<<G[i][3];
init_data();
int unify=0;
cout<<endl<<"APM";
unify++;
int name;
int left=G[1][1];
int right=G[1][2];
L[right]=L[left] ;
name=left;
cout<<endl<<left<<"  "<<right;

while (unify<(n-1))
   {    int first=1;
        int last=m;
        while (first<=last)
        {  left=G[first][1];
            right=G[first][2];
if ((L[left]!=L[right])&&((left==name)||(right==name)))
                    {  unify++;
                       cout<<endl<<left<<"  "<<right;
                       L[right]=name;}
            first++; }
    }
}

int main()
{read_data();
compute_APM();

}
