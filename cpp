/*
fflush(stdin);
getchar();*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include<string>
#include<utility>
#include<set>
#include<sstream>
#include<stack>
#include<queue>
using namespace std;
#define INF 2000
int n,m;
int len[1001][1001];
int dis[1001];
priority_queue<int >q;
int vis[1001];
int spfa(int a,int b)
{
	q.push(a);
	int t;
	vis[a]=1;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		vis[t]=0;
		for(int i=1;i<=n;i++)
		{
			if(len[t][i]>0&&dis[i]>dis[t]+len[t][i])
			{
				dis[i]=dis[t]+len[t][i];
				if(vis[i]==0)
				{
					q.push(i);
					vis[i]=1;
				}
			}
		}
	}
	return dis[b];
}
int main()
{
	
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n>>m;
	int a,b,l;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>l;
		len[a][b]=l;
	}
	cin>>a>>b;
	for(int i=1;i<=n;i++)
	{
		dis[i]=INF;
		
	}
	dis[a]=0;
	cout<<spfa(a,b);
	
	fflush(stdin);
	getchar();
	return 0;
}

