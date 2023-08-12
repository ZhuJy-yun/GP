#include <iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<deque>
#include<string>
using namespace std;

/*
 *
 * 分配器：又叫空间配置器，负责空间的配置与管理，是一个实现了动态空间分配与释放的类模板
 * 统一对容器中需要的内存空间进行管理(申请，释放)
 *
 * 用内存池可以节省申请和释放内存的时间，也可以减少内存碎片
 *
 *
 * system call
 *
 * malloc / free
 *
 * new / delete
 *
 *
 *
 * */


int main(){

    vector<int>v1{1,2,3};

    vector<int,allocator<int>>v2{1,2,3};

    allocator<int>al1;
    int *p = al1.allocate(4);//表示分配了4个int 大小的空间

    *p = 1;
    p++;
    *p=2;

    p++;
    *p=3;

    p++;
    *p=4;

    al1.deallocate(p,4);


    return 0;
}