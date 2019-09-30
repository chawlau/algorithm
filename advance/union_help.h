#ifndef INC_03_QUICK_FIND_UNIONFINDTESTHELPER_H
#define INC_03_QUICK_FIND_UNIONFINDTESTHELPER_H

#include <iostream>
#include <ctime>
#include "union_1.h"
#include "union_2.h"
#include "union_3.h"
#include "union_4.h"

using namespace std;

namespace UnionFindTestHelper{

    void testUF1( int n ){

        srand( time(NULL) );
        UF1::UnionFind uf = UF1::UnionFind(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();

        cout<<"UF1, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }

    void testUF2( int n ){
      srand( time(NULL) );
      UF2::UnionFind uf = UF2::UnionFind(n);

      time_t startTime = clock();

      for( int i = 0 ; i < n ; i ++ ){
        int a = rand()%n;
        int b = rand()%n;
        uf.unionElements(a,b);
      }
      for(int i = 0 ; i < n ; i ++ ){
        int a = rand()%n;
        int b = rand()%n;
        uf.isConnected(a,b);
      }
      time_t endTime = clock();

      cout<<"UF2, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }

    void testUF3(int n) {
      srand(time(NULL));

      UF3::UnionFind uf = UF3::UnionFind(n);
      time_t startTime = clock();
      for (int i = 0; i < n; i++) {
        int a = rand()%n;
        int b = rand()%n;
        uf.unionElements(a, b);
      }

      for(int i = 0 ; i < n ; i ++ ){
        int a = rand()%n;
        int b = rand()%n;
        uf.isConnected(a,b);
      }
      time_t endTime = clock();
      cout<<"UF3, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }

    void testUF4(int n) {
      srand(time(NULL));

      UF4::UnionFind uf = UF4::UnionFind(n);
      time_t startTime = clock();
      for (int i = 0; i < n; i++) {
        int a = rand()%n;
        int b = rand()%n;
        uf.unionElements(a, b);
      }

      for(int i = 0 ; i < n ; i ++ ){
        int a = rand()%n;
        int b = rand()%n;
        uf.isConnected(a,b);
      }
      time_t endTime = clock();
      cout<<"UF4, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }

}
#endif //INC_02_QUICK_FIND_UNIONFINDTESTHELPER_H
