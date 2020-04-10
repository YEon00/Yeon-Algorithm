#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int n; cin >> n;
   vector <int> v;
   for (int i = 0; i < n; i++) {
      int a; cin >> a;
      v.push_back(a);
   }
   sort(v.begin(), v.end());
   int res = -1;
   int cnt = 1;
   for (int i = 1; i < v.size(); i++) {
      if (v[i-1] == v[i]) {
         cnt++;
         if (i== v.size()-1) {
            if (v[i-1] == cnt)
            {
               if (res < cnt)
                  res = cnt;
            }
         }
      }
      else {
         if (v[i-1] == cnt)
         {
            if (res < cnt) 
               res = cnt;
         }
         cnt = 1;
      }
   }
   if (res == -1) {
      res = 0;
   }

   cout << res;


}

//
//// you can also use imports, for example:
//import java.util.*;
//
//// you can write to stdout for debugging purposes, e.g.
//// System.out.println("this is a debug message");
//
//class Solution {
//	public int solution(int[] A) {
//		// write your code in Java SE 8
//		int Max = -1; int Ch = 1;
//		Arrays.sort(A);
//		for (int i = 1; i <= A.length ; i++) {
//			if (A[i-1] == A[i]) {
//				Ch += 1;
//				if (i  == A.length ) {
//					if (A[i] == cnt)
//					{
//						if (res < cnt)
//							res = cnt;
//					}
//				}
//			}
//			else {
//				if (A[i] == cnt)
//				{
//					if (res < cnt)
//						res = cnt;
//				}
//				cnt = 1;
//			}
//		}
//		if (res == -1) {
//			res = 0;
//		}
//		return res;
//	}
//}
