#include <stdio.h>
#include <stdbool.h>
#define MAX 6

int adj[MAX][MAX] = {
    {0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0}
};

int visited[MAX] = {0};

int stack[MAX];
int top = -1;

void push(int item) {
   stack[++top] = item;
}

int pop() {
   return stack[top--];
}

bool isEmpty() {
   return top == -1;
}


void DFS(int vertex) {
    visited[vertex] = 1;
    for (int v = 0; v < MAX; v++) {
        if (adj[vertex][v] && !visited[v]) {
            DFS(v);
        }
    }
    push(vertex);
}

void topological_sort() {
    // 그래프가 비연결일 수 있으므로 반복문 수행
    for (int v = 0; v < MAX; v++) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

void print_topological_order() {
    printf("Topological Order: ");
    
   while(!isEmpty()) {
      printf("%d ", pop());
   }

    printf("\n");
}

int main() {
    topological_sort();
    print_topological_order();

    return 0;
}