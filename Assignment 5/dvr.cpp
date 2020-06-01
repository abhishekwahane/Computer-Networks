//Devesh Bhogre
//TY-BTECH-CSE-Panel-2-PB43
#include<iostream>

using namespace std;
 
int main()
{
    int graph[50][50];
    int i,j,k,t;
    int m;
 
    cout<<"\nEnter Number of Nodes (MAX 7): ";
    cin>>m;
 
   
    for (i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            graph[i][j]=-1;
        }
    }
 
   
    char ch[7]={'A','B','C','D','E','F','G'};
 
   
    for (i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(i==j)
            {
                graph[i][j]=0;
            }
            if(graph[i][j]==-1)
            {
                cout<<"\nEnter Distance between "<<ch[i]<<" - "<<ch[j]<<" : ";
                cin>>t;
                graph[i][j]=graph[j][i]=t;
            }
        }
    }
 
    
    int via[50][50];
    for (i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            via[i][j]=-1;
        }
    }
 
    cout<<"\nInitially:";
    
    for (i=0;i<m;i++)
    {
        cout<<"\n"<<ch[i]<<" Table";
        cout<<"\nNode\tDist\tVia";
        for(j=0;j<m;j++)
        {
            cout<<"\n"<<ch[j]<<"\t"<<graph[i][j]<<"\t"<<via[i][j];
        }
    }
 
   
    int sh[50][50][50];
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            for (k=0;k<m;k++)
            {
                
                if((graph[i][j]>-1)&&(graph[j][k]>-1))
                {
                    sh[i][j][k]=graph[j][k]+graph[i][j];
                }
                else
                {
                    sh[i][j][k]=-1;
                }
            }
        }
    }
 
    
    for(i=0;i<m;i++)
    {
        cout<<"\n\n For "<<ch[i];
        for (j=0;j<m;j++)
        {
            cout<<" From "<<ch[j];
            for(k=0;k<m;k++)
            {
                cout<<"\n to "<<ch[k]<<" : "<<sh[i][j][k];
            }
        		cout<<endl;
        }
        cout<<endl;
        
    }
     
   
    int final[50][50];
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
           
            final[i][j]=graph[i][j];
            via[i][j]=i;
             
           
            for(k=0;k<m;k++)
            {
                 
                if((final[i][j]>sh[i][k][j]) || (final[i][j] == -1))
                {
                    if(sh[i][k][j]>-1)
                    {
                        final[i][j]=sh[i][k][j];
                        via[i][j]=k;
                    }
                }
            }
          
 
            if(final[i][j]==-1)
            {
                for(k=0;k<m;k++)
                {
 
                    if((final[i][k]!=-1)&&(final[k][j]!=-1))
                    {
                        if((final[i][j]==-1) || ((final[i][j]!=-1) &&(final[i][j]>final[i][k]+final[k][j]))) 
                        {
                            if(final[i][k]+final[k][j]>-1)
                            {
                                final[i][j]=final[i][k]+final[k][j];
                                via[i][j]=k;
                            }
                        }
                    }
                     
                }
            }
        }
    }
 
    cout<<"\n After Update :";
    /* Display table Updation */
    for (i=0;i<m;i++)
    {
        cout<<"\n\n\n"<<ch[i]<<" Table";
        cout<<"\nNode\tDist\tVia";
        for(j=0;j<m;j++)
        {
            cout<<"\n"<<ch[j]<<"\t"<<final[i][j]<<"\t";
            if(i==via[i][j])
                cout<<ch[j];//cout<<"-";
            else
                cout<<ch[via[i][j]];
        }
    }
    cout<<endl;
       
    return 0;
}
