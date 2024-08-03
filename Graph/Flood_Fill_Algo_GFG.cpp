// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
// plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. 
// Replace the color of all of the aforementioned pixels with the newColor.

// Examples:

// Input: image = {{1,1,1},{1,1,0},{1,0,1}},
// sr = 1, sc = 1, newColor = 2.
// Output: {{2,2,2},{2,2,0},{2,0,1}}
// Explanation: From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected by a path of the same color as the starting pixel are colored 
// with the new color.Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

// Link: https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?page=1&category=Graph&sortBy=submissions
// Approach : Simple DFS in Graph

void dfs(int row,int col,vector<vector<int>>& image,int initColor,int newColor){
        image[row][col] = newColor;
        vector<int> tRow = {-1 , 0, 1, 0};
        vector<int> tCol = { 0, 1, 0, -1};
        
        for(int i = 0 ; i < 4; i++){
            int actRow = row + tRow[i];
            int actCol = col + tCol[i];
            
            if(actRow >= 0 && actRow < image.size() && actCol >= 0 && actCol < image[0].size() && image[actRow][actCol] == initColor){
                
                dfs(actRow,actCol,image,initColor,newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        int rows = image.size();
        int cols = image[0].size();
        int initColor = image[sr][sc];
        
          if (initColor != newColor) {
            dfs(sr, sc, image, initColor, newColor);
        }
            
        
        return image;
    }
