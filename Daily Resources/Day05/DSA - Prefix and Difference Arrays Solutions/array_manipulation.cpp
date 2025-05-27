long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> diff(n + 2, 0);  // difference array (1-based indexing)

    for (auto &q : queries) {
        int a = q[0], b = q[1];
        long k = q[2];
        diff[a] += k;
        if (b + 1 <= n)
            diff[b + 1] -= k;
    }

    long max_value = 0;
    long current = 0;
    for (int i = 1; i <= n; i++) {
        current += diff[i];
        if (current > max_value)
            max_value = current;
    }

    return max_value;
}
