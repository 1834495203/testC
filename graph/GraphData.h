//
// Created by asus on 2023/9/18.
//

#ifndef TESTC_GRAPHDATA_H
#define TESTC_GRAPHDATA_H

#define MAX_VERTEX_NUM (1 << 7) //aka 128 边的最大数量

typedef int VertexType; // 顶点的数据类型

typedef int EdgeType; // 带权图中的权值的数据类型

//邻接矩阵数据结构
typedef struct {
    VertexType Vex[MAX_VERTEX_NUM];
    EdgeType Edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexNum, arcNum;
} MGraph;


/**
 * 以下是邻接表的存储结构
 */
//边表节点
typedef struct ArcNode {
    int adjVex;
    struct ArcNode *next;
}ArcNode;

//顶点表节点
typedef struct VNode {
    VertexType data;
    ArcNode *first;
} VNode, AdjList[MAX_VERTEX_NUM];

//邻接表
typedef struct {
    AdjList vertices;
    int vexNum, arcNum;
} ALGraph;


#endif //TESTC_GRAPHDATA_H
