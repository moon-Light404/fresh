/********************************************/
/*         邻接矩阵类型定义的头文件		 	*/
/*               文件名：ljjz.h	   			*/
/********************************************/

#include <stdio.h>
#define FINITY 5000   			/*此处用5000代表无穷大*/
#define M 20          				/*最大顶点数*/
typedef char vertextype;  		/*顶点值类型*/
typedef int edgetype;     		/*权值类型*/
typedef struct {
	vertextype vexs[M];    		/*顶点信息域*/
	edgetype edges[M][M]; 	/*邻接矩阵*/
	int n, e;  							/*图中顶点总数与边数*/
} Mgraph;   							/*邻接矩阵表示的图类型*/

/*   函数功能：建立图的邻接矩阵存储结构
     函数参数：邻接矩阵的指针变量g；存放图信息的文件名s；图的类型c，c=0表示建立无向图，否则表示建立有向图
   函数返回值：无
*/
void creat(Mgraph *g, char *s, int c) {
	int i, j, k, w;        /*建立网络的邻接矩阵存储结构*/
	FILE *rf ;
	rf = fopen(s, "r") ;   /*从文件中读取图的边信息*/
	if (rf) {
		fscanf(rf, "%d%d", &g->n, &g->e); /*读入图的顶点数与边数*/
		for (i = 0; i < g->n; i++) /*读入图中的顶点值*/
			fscanf(rf, "%1s", &g->vexs[i]);

		for (i = 0; i < g->n; i++) /*初始化邻接矩阵*/
			for (j = 0; j < g->n; j++)
				if (i == j)
					g->edges[i][j] = 0;
				else
					g->edges[i][j] = FINITY;

		for (k = 0; k < g->e; k++) { /*读入网络中的边*/
			fscanf(rf, "%d%d%d", &i, &j, &w);
			g->edges[i][j] = w;
			if (c == 0)
				g->edges[j][i] = w; /*如果C==0则建立无向图邻接矩阵，否则建立有向图邻矩阵*/
		}
		fclose(rf);
	} else
		g->n = 0;
}


//void  print(Mgraph g)
//{/*辅助函数，输出邻接矩阵表示的图g*/
//  int i,j;
//
//  for (i=0;i<g.n;i++)
//   { printf("%c ",g.vexs[i]);
//    }
//    printf("\n");
//  for (i=0;i<g.n;i++)
//    {    for (j=0;j<g.n;j++)
//         {printf("%6d",g.edges[i][j]);
//        }
//          printf("\n");
//       }
//  }

void print(Mgraph g) {
	for (int i = 0; i < g.n; i++)
		for (int j = i + 1; j < g.n; j++) {
			if (g.edges[i][j] != FINITY) {
				printf("%c---->%c : %d\n", g.vexs[i], g.vexs[j], g.edges[i][j]);
			}
		}
}
