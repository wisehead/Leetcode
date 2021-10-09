---
title: (1条消息) Dijkstra算法图文详解_black_hole6的博客-CSDN博客
category: default
tags: 
  - blog.csdn.net
created_at: 2020-09-29 17:04:39
original_url: https://blog.csdn.net/lbperfect123/article/details/84281300
---

# Dijkstra算法图文详解

![](assets/1601370279-426136e8363e68fc321f3d3551b0d579.png)

置顶 [lbperfect123](https://me.csdn.net/lbperfect123) 2018-11-20 09:19:59 ![](assets/1601370279-11d4e66b47a786d7307438a15382d44a.png) 106392 ![](assets/1601370279-50c7c045de1e4400c6f27a33ed55cf7c.png) 收藏  321 

分类专栏： [最短路](https://blog.csdn.net/lbperfect123/category_8378788.html)

版权

**Dijkstra算法**

Dijkstra算法算是**贪心思想**实现的，首先把起点到所有点的距离存下来找个最短的，然后松弛一次再找出最短的，所谓的松弛操作就是，遍历一遍看通过刚刚找到的距离最短的点作为中转站会不会更近，如果更近了就更新距离，这样把所有的点找遍之后就存下了起点到其他所有点的最短距离。

问题引入：

指定一个点（源点）到其余各个顶点的最短路径，也叫做“单源最短路径”。例如求下图中的1号顶点到2、3、4、5、6号顶点的最短路径。

![](assets/1601370279-1cfa61a7d9f38b5b58ced81d938aebab.png)

![](assets/1601370279-5303104304635a60e60f3a4ce10c6b23.png) ![](assets/1601370279-842c602e94aef0bc179c62b1edb333f3.png)

![](assets/1601370279-f4e51f0da093061d0e1644213b2f83bb.png) 

![](assets/1601370279-5e3505ebb6347c4a619fba9573f8ed04.png)![](assets/1601370279-0f669bcb3e666557bdbfac4515b9e8bb.png)

![](assets/1601370279-77703418053189ab1281a8787d3b660a.png) 

![](assets/1601370279-498cfa253c30305185989ab3497050be.png) 

 下面我们来模拟一下：

![](assets/1601370279-41e86c4699597d58154adbc38da35f7f.png)

![](assets/1601370279-4ad34e9af63132662d65dd72a1684253.png)

 这就是Dijkstra算法的基本思路：

接下来是代码：

已经把几个过程都封装成了基本模块：

```cpp
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define Inf 0x3f3f3f3f
 
using namespace std;
 
int map[1005][1005];
 
int vis[1005],dis[1005];
int n,m;//n个点，m条边
 
void Init ()
{
	memset(map,Inf,sizeof(map));
	for(int i=1;i<=n;i++)
	{
		map[i][i]=0;
	}
}
 
void Getmap()
{
	int u,v,w;
    for(int t=1;t<=m;t++)
	{
	  	scanf("%d%d%d",&u,&v,&w);
	  	if(map[u][v]>w)
		  {
		  map[u][v]=w;
		  map[v][u]=w;
	      }
	}	
	
}
 
void Dijkstra(int u)
{
	memset(vis,0,sizeof(vis));
	for(int t=1;t<=n;t++)
	{
		dis[t]=map[u][t];
	}
	vis[u]=1;
	for(int t=1;t<n;t++)
	{
		int minn=Inf,temp;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&dis[i]<minn)
			{
				minn=dis[i];
				temp=i;
			}
		}
		vis[temp]=1;
		for(int i=1;i<=n;i++)
		{
			if(map[temp][i]+dis[temp]<dis[i])
			{
				dis[i]=map[temp][i]+dis[temp];
			}
		}
	}
	
}
 
int main()
{
	
	scanf("%d%d",&m,&n);
	Init();
	Getmap();
	Dijkstra(n);
	printf("%d\n",dis[1]);
	
	
	return 0;
}
```

---------------------------------------------------


原网址: [访问](https://blog.csdn.net/lbperfect123/article/details/84281300)

创建于: 2020-09-29 17:04:39

目录: default

标签: `blog.csdn.net`

