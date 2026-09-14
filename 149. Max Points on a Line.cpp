class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int numPoints = points.size();
        int maxPointsOnLine = 1;  // At least one point always exists
      
        // Try each point as the first point of a potential line
        for (int i = 0; i < numPoints; ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
          
            // Try each subsequent point as the second point to form a line
            for (int j = i + 1; j < numPoints; ++j) {
                int x2 = points[j][0];
                int y2 = points[j][1];
              
                // Start with 2 points (i and j) on the current line
                int pointsOnCurrentLine = 2;
              
                // Check all remaining points to see if they're collinear
                for (int k = j + 1; k < numPoints; ++k) {
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                  
                    // Check collinearity using cross product
                    // Points are collinear if (y2-y1)/(x2-x1) == (y3-y1)/(x3-x1)
                    // To avoid division, we cross-multiply:
                    // (y2-y1)*(x3-x1) == (y3-y1)*(x2-x1)
                    int crossProduct1 = (y2 - y1) * (x3 - x1);
                    int crossProduct2 = (y3 - y1) * (x2 - x1);
                  
                    // If cross products are equal, point k is on the same line
                    if (crossProduct1 == crossProduct2) {
                        pointsOnCurrentLine++;
                    }
                }
              
                // Update the maximum number of points found on any line
                maxPointsOnLine = max(maxPointsOnLine, pointsOnCurrentLine);
            }
        }
      
        return maxPointsOnLine;
    }
};
