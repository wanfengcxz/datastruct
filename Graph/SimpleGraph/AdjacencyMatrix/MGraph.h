//
// Created by 晚风吹行舟 on 2021/6/13.
//

#ifndef DATASTRUCTURE_MGRAPH_H
#define DATASTRUCTURE_MGRAPH_H

#include <vector>
#include <queue>
#include <map>
#include <iostream>

using EdgeType = int;
using VertexType = char;
using std::vector;
using std::queue;
using std::multimap;
using std::cout;
using std::cin;
using std::endl;

class MGraph {

private:
    // 权值矩阵
    EdgeType **edge;
    // 顶点数 边数
    int vex_num, arc_num;
    VertexType *vex;

private:

    void BFS_(int vex_index, bool *visited, vector<VertexType> &res);

    void DFS_(int vex_index, bool *visited, vector<VertexType> &res);

public:

    /**
     * 等价于C语言中的initialMGraph()
     */
    MGraph():edge(nullptr), vex_num(0),arc_num(0),vex(nullptr){}

//    ~MGraph(){
//        delete [] vex;
//        for (int i = 0;i<vex_num;i++)
//            delete [] edge[vex_num];
//        delete [] edge;
//    }

    /**
     * for debug
     * @return vex pointer
     */
    VertexType * vexPointer(){
        return vex;
    }

    /**
     * 顶点数目
     * @return 顶点数目
     */
    int vexNum(){
        return vex_num;
    }

    /**
     * 边数
     * @return 边数
     */
    int edgeNum(){
        return arc_num;
    }

    /**
     * 创建一个空图
     * @param vex_num 顶点数量
     * @param vex 顶点信息 可为空 默认为 1 2 3.....
     */
    void createEmptyGraph(int vex_num_, VertexType vex_[] = nullptr);

    void addEdges(multimap<int,int> &edges_);

    /**
     * 获取一个图的样例
     * @样例1
     *  1 —— 2    3 —— 4
     *  |    | /  | /  |
     *  5    6 —— 7 —— 8
     *
     * @param number 样例编号
     */
    void getInstance(int number);

    /**
     * 获取当前节点在节点列表中的下标
     * @param vex
     * @return 下标 如果不存在返回-1
     */
    int index(VertexType vex);

    /**
     * 获得与当前节点邻接的所有节点
     * @param vex
     * @return 邻接点下标组成的向量组
     */
    vector<int> neighbor(int vex_index);

    /**
     * 广度优先遍历
     * @算法要点：
     * 1，需要一个辅助队列
     * 2. 如何从一个节点找到与之邻接的其他节点
     * 3. visited数组防止重复访问
     * 4. 如何处理非连通图
     * @空间复杂度 O(V) 辅助队列
     * @时间复杂度 O(V^2)
     * @广度优先生成树
     * 由广度优先遍历确定的树，生成树唯一（邻接矩阵存储）
     * 遍历非连通图可以获得广度优先生成森林
     * @邻接表的情况
     * 存储结构不同只是对应的neighbor函数的实现不同，
     * 其他的实现细则都是一样的
     * @其他
     * 1. 调用BFS_()的次数=连通分量数
     * 2. 同一图的邻接矩阵表示方式唯一，因此深度/广度优先遍历序列唯一
     * 而邻接表表示方式不唯一，因此深度/广度优先遍历序列不唯一
     * @param vex_ 起始顶点
     * @return 遍历序列
     */
    vector<VertexType> BFS(VertexType vex_);

    /**
     * 深度优先遍历
     * @算法要点
     * 1，递归地深入探索未被访问过的邻接点（使用递归来进行回溯）
     * 2. 如何从一个节点找到与之邻接的其他节点
     * 3. visited数组防止重复访问
     * 4. 如何处理非连通图
     * @空间复杂度 O(V)
     * @时间复杂度 O(V^2)
     * @深度优先生成树
     * 由深度优先遍历确定的树，生成树唯一（邻接矩阵存储）
     * 遍历非连通图可以获得深度优先生成森林
    * @邻接表的情况
     * 存储结构不同只是对应的neighbor函数的实现不同，
     * 其他的实现细则都是一样的
     * @其他
     * 同一图的邻接矩阵表示方式唯一，因此深度/广度优先遍历序列唯一
     * 而邻接表表示方式不唯一，因此深度/广度优先遍历序列不唯一
     * @param vex_
     * @return
     */
    vector<VertexType> DFS(VertexType vex_);



};


#endif //DATASTRUCTURE_MGRAPH_H
