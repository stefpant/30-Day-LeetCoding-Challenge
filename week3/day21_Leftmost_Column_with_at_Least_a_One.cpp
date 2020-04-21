/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        //rows are sorted, so starting from right up point...
        //while there can be found 1 go one step to left
        //else go down until reach the last row or first column
        //in the end return the smaller column found with a 1
        vector<int> dims = binaryMatrix.dimensions();
        int curI=0;
        int foundJ = -1;
        for(int j=dims[1]-1; curI<dims[0] && j>=0;){
            if( binaryMatrix.get(curI, j) == 1){
                foundJ = j;
                j--;
            }
            else curI++;
        }
        return foundJ;
    }
};
