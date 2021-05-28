/********************************************/
/*         �ڽӾ������Ͷ����ͷ�ļ�		 	*/
/*               �ļ�����ljjz.h	   			*/
/********************************************/

#include <stdio.h>
#define FINITY 5000   			/*�˴���5000���������*/
#define M 20          				/*��󶥵���*/
typedef char vertextype;  		/*����ֵ����*/
typedef int edgetype;     		/*Ȩֵ����*/
typedef struct {
	vertextype vexs[M];    		/*������Ϣ��*/
	edgetype edges[M][M]; 	/*�ڽӾ���*/
	int n, e;  							/*ͼ�ж������������*/
} Mgraph;   							/*�ڽӾ����ʾ��ͼ����*/

/*   �������ܣ�����ͼ���ڽӾ���洢�ṹ
     �����������ڽӾ����ָ�����g�����ͼ��Ϣ���ļ���s��ͼ������c��c=0��ʾ��������ͼ�������ʾ��������ͼ
   ��������ֵ����
*/
void creat(Mgraph *g, char *s, int c) {
	int i, j, k, w;        /*����������ڽӾ���洢�ṹ*/
	FILE *rf ;
	rf = fopen(s, "r") ;   /*���ļ��ж�ȡͼ�ı���Ϣ*/
	if (rf) {
		fscanf(rf, "%d%d", &g->n, &g->e); /*����ͼ�Ķ����������*/
		for (i = 0; i < g->n; i++) /*����ͼ�еĶ���ֵ*/
			fscanf(rf, "%1s", &g->vexs[i]);

		for (i = 0; i < g->n; i++) /*��ʼ���ڽӾ���*/
			for (j = 0; j < g->n; j++)
				if (i == j)
					g->edges[i][j] = 0;
				else
					g->edges[i][j] = FINITY;

		for (k = 0; k < g->e; k++) { /*���������еı�*/
			fscanf(rf, "%d%d%d", &i, &j, &w);
			g->edges[i][j] = w;
			if (c == 0)
				g->edges[j][i] = w; /*���C==0��������ͼ�ڽӾ��󣬷���������ͼ�ھ���*/
		}
		fclose(rf);
	} else
		g->n = 0;
}


//void  print(Mgraph g)
//{/*��������������ڽӾ����ʾ��ͼg*/
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
