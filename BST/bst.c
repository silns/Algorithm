#include <stdio.h>
#include <stdlib.h>

// 定义节点结构体
typedef struct Node
{
  int data;
  struct Node *lchild;
  struct Node *rchild;
  struct Node *parent;
} Node, *PNode;

// 插入
void insert(PNode *root, int data)
{
  // 分配节点空间并将data的值保存起来
  PNode p = (PNode)malloc(sizeof(Node));
  p->data=data;
  // 初始化各指针为NULL
  p->lchild = p->rchild = p->parent = NULL;
  // 判断是不是树的root节点，如果是，直接作为根节点
  if((*root) == NULL) {
    *root = p;
    return;
  }
  // 判断该节点是否有左孩子并且新节点的值是否小于该节点的值，如果是，则将新节点作为该节点的左孩子
  if((*root)->lchild == NULL && (*root)->data > data) {
    p->parent = (*root);
    (*root)->lchild = p;
    return;
  }
  // 判断该节点是否有右孩子并且新节点的值是否大于该节点的值，如果是，则将新节点作为该节点的右孩子
  if((*root)->rchild == NULL && (*root)->data < data) {
    p->parent = (*root);
    (*root)->rchild = p;
    return;
  }
  // 如果前面的情况都不满足，则表示新节点必须插入到给定节点的孩子节点中，使用递归来寻找插入的位置进行插入
  if((*root)->data > data)
    insert(&(*root)->lchild, data);
  else if((*root)->data < data)
    insert(&(*root)->rchild, data);
  else
    return;
}

// 建立
/*
 * datas用于初始化的数据
 * length是datas的长度
 */
void create(PNode *root, int *datas, int length)
{
  int i;
  // 建立其实就是插入新节点
  for(i=0; i<length; i++) {
    insert(root, datas[i]);
  }
}

// 使用中序遍历的方法来获取最小值
PNode searchMin(PNode root)
{
  // 判断根节点是否为NULL
  if(root == NULL)
    return NULL;
  // 判断根节点的左孩子是否为NULL，如果是返回本节点作为最小节点，否则对左节点进行同样的查询
  if(root->lchild == NULL)
    return root;
  else
    return searchMin(root->lchild);
}

// 使用中序遍历的方法来获取最大值
PNode searchMax(PNode root)
{
  if(root == NULL)
    return NULL;
  if(root->rchild == NULL)
    return root;
  else
    return searchMax(root->rchild);
}

// 使用树的data信息来获取到保存该信息的节点
PNode search(PNode root, int data)
{
  if(root == NULL)
    return NULL;
  if(data > root->data)
    return search(root->rchild, data);
  else if(data < root->data)
    return search(root->lchild, data);
  else
    return root;
}

// 查找前驱（先序遍历版本）
PNode dlrSearchPre(PNode p)
{
  // 检查是否有父节点或者为NULL，是则返回NULL
  if(p->parent == NULL)
    return NULL;
  if(p == NULL)
    return p;
  // 检查本节点是不是父节点的左孩子，如果是，则直接返回父节点
  if(p->parent->lchild == p)
    return p->parent;
  // 检查本节点是不是父节点的右孩子且父节点不存在左孩子，如果是，则返回有节点
  if(p->parent->rchild == p && p->parent->lchild == NULL)
    return p->parent;
  // 如果本节点是父节点的右孩子，且父节点存在左孩子，那么前驱是左子树最后访问的节点
  if(p->parent->rchild == p && p->parent->lchild) {
    PNode pre = p->parent->lchild;
    // while的条件表示该节点不是叶子节点
    while(!(!pre->lchild && !pre->rchild)) {
      if(pre->rchild)
	pre = pre->rchild;
      else
	return pre;
    }
    return pre;
  }
  return NULL;
}

// 查找后继（先序遍历版本）
PNode dlrSearchNext(PNode p)
{
  // 判断该节点是否为NULL
  if(p == NULL)
    return p;
  // 若本节点存在左孩子，则左孩子是它的后继节点
  if(p->lchild)
    return p->lchild;
  // 若本节点无左孩子，而有右孩子，则右孩子是它的后继节点
  if(!p->lchild && p->rchild)
    return p->rchild;
  // 如果该节点为叶子节点，则再讨论
  if(!p->lchild && !p->rchild) {
    // 若本节点是父母的左孩子，且父母有右孩子，则后继是父母的右孩子
    if(p->parent->lchild == p && p->parent->rchild)
      return p->parent->rchild;
    // 若是父母的左孩子，且父母无右孩子，或者是父母的右孩子，则后继是左子树前序遍历的最后一个节点，则必须找一个右孩子的“左祖先”，然后后继节点就是该祖先的右孩子
    if((p->parent->lchild == p && !p->parent->rchild) || p->parent->rchild == p) {
      while(p->parent && (!p->parent->rchild || p->parent->rchild == p)) {
	p = p->parent;
      }
      if(!p->parent)
	return NULL;
      else
	return p->parent->rchild;
    }
  }
  return NULL;
}


// 先序遍历
void dlr(PNode root)
{
  if(root == NULL)
    return;
  printf("%d\t", root->data);
  dlr(root->lchild);
  dlr(root->rchild);
}

// 中序遍历
void ldr(PNode root)
{
  if(root == NULL)
    return;
  ldr(root->lchild);
  printf("%d\t", root->data);
  ldr(root->rchild);
}

// 后续遍历
void lrd(PNode root)
{
  if(root == NULL)
    return;
  lrd(root->lchild);
  lrd(root->rchild);
  printf("%d\t", root->data);
}

int main(void)
{
  //int datas[] = {2, 1, 3, 9, 6, 10, 4};
  int datas[]={15, 9, 20, 13, 25, 11, 14, 22, 30, 10, 12, 21, 23, 28, 35, 27, 31, 37, 32};
  int i;
  for(i = 0; i < sizeof(datas)/sizeof(int); i++) {
    printf("%d\t", datas[i]);
  }
  printf("\n");
  PNode root = NULL;
  create(&root, datas, sizeof(datas)/sizeof(int));
  printf("dlr\n");
  dlr(root);
  printf("\n");
  printf("pre && next\n");
  printf("%d\n", dlrSearchPre(root->lchild)->data);
  printf("%d\n", dlrSearchPre(root->lchild->rchild)->data);
  printf("%d\n", dlrSearchPre(root->lchild->rchild->rchild)->data);
  printf("%d\n", dlrSearchNext(root)->data);
  printf("%d\n", dlrSearchNext(root->rchild)->data);
  printf("%d\n", dlrSearchNext(root->rchild->rchild->lchild->lchild)->data);
  printf("%d\n", dlrSearchNext(root->rchild->rchild->rchild->lchild->lchild)->data);
  printf("%d\n", dlrSearchNext(root->rchild->rchild->rchild->rchild->lchild->rchild)->data);
  printf("============================================\n");
  if(dlrSearchPre(root) == NULL)
    printf("root's pre is null\n");
  if(dlrSearchNext(root->rchild->rchild->rchild->rchild->rchild) == NULL)
    printf("last one has no next node\n");
  printf("===========================================\n");
  //printf("ldr\n");
  //ldr(root);
  //printf("\n");
  printf("lrd\n");
  lrd(root);
  printf("\n");
  PNode m = searchMin(root);
  printf("===========================================\n");
  printf("ldr\n");
  ldr(root);
  printf("\n");
  printf("MIN:%d\n", m->data);
  m = searchMax(root);
  printf("MAX:%d\n", m->data);
  PNode sc = search(root, 32);
  if(sc)
    printf("search get result. it's value is %d\n", sc->data);
  sc = search(root, 5);
  printf("search %d can not get result.\n", 5);

  return 0;
}
