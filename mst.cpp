// CSCI 3300
// Assignment: 4
// Author:     Joshua Bowen
// File:       mst.cpp
// Tab stops:  8

/**	This program takes an input graph of vertices and edges and computes
   	the minimal spanning tree of this graph and returns it. 	**/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "equiv.h"
using namespace std;

const int maxEdges = 100;

struct Edge
{
	int vertex1;
	int vertex2;
	int weight;
	Edge()
	{
		vertex1 = 0;
		vertex2 = 0;
		weight = 0;
	}
	Edge(int v1, int v2, int w)
	{
		vertex1 = v1;
		vertex2 = v2;
		weight = w;
	}
};
struct Graph
{
	int numVertices;
	int numEdges;
	Edge* edges;
	Graph(int nv)
	{
		numVertices = nv;
		numEdges = 0;
		edges = new Edge[maxEdges];
	}
};

void insertEdge(int, int, int, Graph);
Graph readAGraph();
void writeGraph(Graph);
int totalWeight(Graph);
typedef int (*QSORT_COMPARE_TYPE)(const void*, const void*);

// insertEdge(u, v, w, g) inserts an edge between vertices
// u and v, of weight w, into graph g.
//
// If there is not enough room in g to add the edge, then
// insertEdge does nothing.

void insertEdge(int u, int v, int w, Graph g)
{
	if (g.numEdges > maxEdges)
	{}
	else
	{
		g.edges[g.numEdges].vertex1 = u;
		g.edges[g.numEdges].vertex2 = v;
		g.edges[g.numEdges].weight = w;
	}
}

// readAGraph() reads a graph from the standard input and returns it.

Graph readAGraph()
{
	int a, b, c, d;
	scanf("%d", &d);
	Graph p(d);
	bool notZero = true;	
	while (notZero)
	{
		scanf("%d", &a);
		if (a == 0)
		{
			notZero = false;
		}
		else
		{
			scanf("%d%d", &b, &c);
			insertEdge(a, b, c, p);
			p.numEdges += 1;
		}
	}
	return p;
}

// writeGraph(g) writes a description of Graph g in the standard output.

void writeGraph(Graph g)
{
	printf("\nThere are %d vertices and %d edges\n\n", g.numVertices, g.numEdges);
	printf("vertices  weight\n");
	for (int i = 0; i < g.numEdges; i++)
	{
		printf("%d   %d	     %d\n", g.edges[i].vertex1, g.edges[i].vertex2, g.edges[i].weight);
	}
	printf("\n");
	printf("The total weight of the spanning tree is: %d\n\n", totalWeight(g));
}

// compareEdges(A, B) compares two values in a sorted array
// of type Edge* and returns a negative number if A* comes before
// B* in the array or a positive number if vice versa.
// Returns 0 if order does not matter.

int compareEdges(const Edge* A, const Edge* B)
{
    return A->weight - B->weight;
}
// sortEdges(g) sorts the array of edges in Graph g.

void sortEdges(Graph g)
{
	qsort((void*) g.edges, g.numEdges, sizeof(Edge), (QSORT_COMPARE_TYPE) compareEdges);
} 

// minimalSpanningTree(g) computes the minimal spanning tree of Graph g.
	
Graph minimalSpanningTree(Graph g)
{
	sortEdges(g);
	Graph K(g.numVertices);
	ER e1 = newER(g.numVertices);
	for (int i = 0; i < g.numVertices; i++)
	{
		if (together(e1, g.edges[i].vertex1, g.edges[i].vertex2))
		{
			
		}
		else
		{
			combine(e1, g.edges[i].vertex1, g.edges[i].vertex2);
			insertEdge(g.edges[i].vertex1, g.edges[i].vertex2, g.edges[i].weight, K);
			K.numEdges += 1;
		}
	}
	return K;
}

// totalWeight(g) returns the total weight of Graph g.
int totalWeight(Graph g)
{
	int total = 0;
	for (int i = 0; i < g.numEdges; i++)
	{
		total += g.edges[i].weight;
	}
	return total;
}
 
int main(int argc, char** argv)
{
	printf("\nMinimal Spanning Tree:\n");
	writeGraph(minimalSpanningTree(readAGraph()));
	return 0;
}

