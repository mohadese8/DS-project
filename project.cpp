#include<iostream>

#include <vector>

#include <queue>

#include <climits>

#include<algorithm>

#include <stdexcept>

using namespace std;

//Define structure for nodes
struct Node
{
    int id;

    vector<pair<int, int>> neighbors; //List of neighbors and weight
};


//Correct values
void valu(int a , int b , int n)
{
    if((a > n) || ( a < 0) || (b > n) || ( b < 0))
    {
        throw "Invalid values";
    }
}


//Print values
void print(vector<int> path)
{
    cout << "Best Path: ";

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if (i != path.size() - 1)
        {
            cout << " -> ";
        }
    }

    cout << endl;
}


//Dijkstra's algorithm to find the best path
vector<int> Dijkstra(vector<Node>& graph, int source, int destination) 
{
    int n = graph.size();

    vector<int> distance(n, INT_MAX); //Vector for distance

    vector<int> previous(n, -1); //vector for the path

    vector<bool> visited(n, false); // Vector for visit


    distance[source] = 0; // The initial value of the source

    //Build a priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


    pq.push({0, source}); 


    while (!pq.empty()) {

        int u = pq.top().second; // The current node

        pq.pop();

        visited[u] = true; 


        // Update distance and previous nodes
        for (auto neighbor : graph[u].neighbors) 
        {
            int v = neighbor.first; // The current neighbor of Ger

            int weight = neighbor.second; // The weight of the neighboring mane

            if ((visited[v] == false) && ((distance[u] + weight )< distance[v]))
            {
                distance[v] = distance[u] + weight;

                previous[v] = u;

                pq.push({distance[v], v});

            }

        }
    }
    cout << "Cost and time : "<< pq.top().first << endl;


    // Create a path from the destination to the recursive origin
    vector<int> path;

    int current = destination;

    while (current != -1)
    {
        path.push_back(current);

        current = previous[current];
    }


    reverse(path.begin(), path.end());


    return path;
}

//main
int main() 
{
    bool  choice;

    int source = 0;

    int destination = 5;
    

    cout << "Do you want to use the default graph or do you want to create a graph?" << endl

            << "0 : Use the existing graph." << endl

            << "1 : Creating a new graph." <<endl;

    cin >> choice ;

    
    if(choice==0)
    {
        vector<Node> graph(6); 

        graph[0].neighbors.push_back({1, 4});

        graph[0].neighbors.push_back({2, 2});

        graph[1].neighbors.push_back({2, 1});

        graph[1].neighbors.push_back({3, 5});

        graph[2].neighbors.push_back({3, 8});

        graph[2].neighbors.push_back({4, 10});

        graph[3].neighbors.push_back({4, 2});

        graph[3].neighbors.push_back({5, 6});

        graph[4].neighbors.push_back({5, 3});


        cout << "Please enter source and destination between 0 and 5 ." << endl

        << "source : ";

        cin >> source;

        cout << "destination : ";

        cin >> destination;


        try
        {
            valu(source , destination , graph.size());
        }
        catch (const char* msg)
        {
            cerr << msg << endl;
        }
        vector<int> path = Dijkstra(graph, source, destination);
        print(path);
    }
    

    else if(choice==1)
    {
        short int size , n , s;


        cout << "Enter the size of the graph : ";

        cin >> size; 

        vector<Node> graph(size);

        for(int i=0 ; i<size ; i++)
        {
            int neighbor_size;

            cout << endl << "enter number neighbor_size for graph[" << i << "] : ";

            cin >> neighbor_size;


            for(int j=0 ; j<neighbor_size ; j++)
            {
                cout << "Enter the neighborhood number : ";

                cin >> n;

                cout << "Enter the neighbor " << n <<" fee : ";

                cin >> s;

                graph[i].neighbors.push_back({n, s});

                cout << endl;
            }
        }
        cout << "Please enter source and destination smaller than size ." << endl

        << "source : ";

        cin >> source;

        cout << "destination : ";

        cin >> destination;


        try
        {
            valu(source , destination , size);
        }
        catch (const char* msg)
        {
            cerr << msg << endl;
        }
        vector<int> path = Dijkstra(graph, source, destination);
        print(path);
    }

    return 0;
}