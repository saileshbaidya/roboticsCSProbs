class UniquePathsDPMemoization {
public:
    int **pathCount;
    
    int helperfuncDPMemoization(int m, int n) {
        if (m == 0 || n == 0)
            return 1;
        if (pathCount[m][n] != 0) //Use of memoization
            return pathCount[m][n];

        int paths = helperfunc(m - 1, n) + helperfunc(m, n - 1);
        pathCount[m][n] = paths;
        return paths;
    }
    
    int uniquePathsDPMemoization(int m, int n) {
        if (m == 0 && n == 0)
            return 0;    
        pathCount = new int*[m];
        for (int i = 0; i < m; i++)
        {
            pathCount[i] = new int[n];
            for(int j=0; j<n; j++)
            pathCount[i][j] = 0;
        }
        return helperfunc(m-1, n-1);
    }
};
