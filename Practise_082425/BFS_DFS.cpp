void DFS_preorder(vector<vector<int>> &graph, int startNode) {
    stack<int> s;
    vector<bool> visited(graph.size(), false);

    s.push(startNode);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";  // print when discovered

            // push neighbors in reverse order
            for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }
    }
    cout << endl;
}
