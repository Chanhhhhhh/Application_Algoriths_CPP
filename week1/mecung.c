#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct{
    int row,col; //chỉ số hàng và cột của trạng thái hiện tại
    int step; //số bước di chuyển để đi từ trạng thái xuất phát đến trạng thái hiện tại
    struct Node *next; //con trỏ đến phần tử tiếp theo trong hàng đợi
    struct Node *parent; //con trỏ trỏ đến trạng thái sinh ra trạng thái hiện tại
}Node;

Node *head, *tail;
Node* listNode[MAX*MAX];
int szList = 0;
int A[MAX][MAX];
int n,m;
int r0,c0;
int visit[MAX][MAX];
Node* finalNode;

const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};

Node* makeNode(int row, int col, int step, Node* parent){
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row; 
    node->col = col; 
    node->next = NULL;
    node->parent = parent; 
    node->step = step;
    return node;
}

void initQueue(){
    head = NULL;
    tail = NULL;
}

int queueEmpty(){
    return head == NULL && tail == NULL;
}

void pushQueue(Node * node){
    if (queueEmpty()){
        head = node;
        tail = node;
    }else{
        tail->next = node;
        tail = node;
    }
}

Node *popQueue(){
    if(queueEmpty()) return NULL;
    Node* node = head; head = node->next;
    if(head == NULL) tail = NULL;
    return node;
}

void input(){
    printf("Enter maze: ");
    char filename[20];
    scanf("%s",filename);
    FILE *f = fopen(filename,"r");
    fscanf(f,"%d%d%d%d",&n,&m,&r0,&c0);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            fscanf(f,"%d",&A[i][j]);
        }
    }
    fclose(f);
}

int legal(int r,int c){
    return A[r][c]==0 && visit[r][c]==0;
}

int target(int r,int c){
    return r>n || r<1 || c>m || c<1;
}

void finalize(){
    for(int i = 0; i < szList; i++){
    free(listNode[i]);
    }
}

void addList(Node* node){// them phan tu vao listNode de thuc hien giai phong bo nho
    listNode[szList] = node;
    szList++;
}
int main(){
    initQueue();
    input();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            visit[i][j]==0;
        }
    }
    Node *startNode = makeNode(r0,c0,0,NULL);
    addList(startNode);
    pushQueue(startNode);
    if(legal(r0, c0)){
    visit[r0][c0]=1;
    while(!queueEmpty()){
        Node *node = popQueue();
        printf("POP (%d,%d)\n",node->row,node->col);
        for (int k=0;k<4;k++){
            int nr = node->row+dr[k];
            int nc = node->col+dc[k];
            if (legal(nr,nc)){
                visit[nr][nc]=1;
                Node *newNode = makeNode(nr,nc,node->step+1,node);
                addList(newNode);
                if (target(nr,nc)){
                    finalNode = newNode;
                    break;    
                }else{
                    pushQueue(newNode);
                }
            }
    if (finalNode != NULL) break;
    }
    }
    }
    else printf("Error");
Node* s = finalNode;
while(s != NULL){
printf("(%d,%d) ",s->row,s->col);
s = s->parent;
}
finalize();
}
