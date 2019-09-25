//stack of arr
#include<bits/stdc++.h>

class box {
   public:
   int length, breadth, height;
};

bool compare(box b1, box b2) {
   return b1.height > b2.height;    //to sort the box as descending order of height
}

int maxHeight(box boxList[], int n) {
   box rotation[3*n];    //a box can be rotared as 3 type, so there is 3n number of rotations
   int index = 0;

   for (int i = 0; i < n; i++) {
      //store initial position of the box
      rotation[index].length = boxList[i].length;
      rotation[index].height = std::max(boxList[i].height, boxList[i].breadth);
      rotation[index].breadth = std::min(boxList[i].height, boxList[i].breadth);
      index++;

      //first rotation
      rotation[index].length = boxList[i].breadth;
      rotation[index].height = std::max(boxList[i].length, boxList[i].height);
      rotation[index].breadth = std::min(boxList[i].length, boxList[i].height);
      index++;        
   
      //second rotation
      rotation[index].length = boxList[i].height;
      rotation[index].height = std::max(boxList[i].length, boxList[i].breadth);
      rotation[index].breadth = std::min(boxList[i].length, boxList[i].breadth);
      index++;
   }

   n = 3*n;    //set n as 3n for 3 rotations of each boxes

   std::sort(rotation, rotation+n, compare);    //sort rotation array as descending order

   int maxHTemp[n];    //temporary max height if ith box is stacked

   for (int i = 0; i < n; i++ )
      maxHTemp[i] = rotation[i].length;
   
   for (int i = 1; i < n; i++ )    //find optimized stack height
      for (int j = 0; j < i; j++ )
         if ( rotation[i].breadth < rotation[j].breadth && rotation[i].height < rotation[j].height
            && maxHTemp[i] < maxHTemp[j] + rotation[i].length) {
            maxHTemp[i] = maxHTemp[j] + rotation[i].length;
         }
   int maxHeight = -1;
   for ( int i = 0; i < n; i++ )    //find the maximum height from all temporary heights
         
      if ( maxHeight < maxHTemp[i] )
         maxHeight = maxHTemp[i];
         
   return maxHeight;
}

int main() {
   box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
   int n = 4;
   std::cout<<"The maximum possible height of box stack is: " << maxHeight (arr, n) << '\n';
}