#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(WordLadderTest, SimpleCases) {
    set<string> word_list = {"cat", "hat", "bad", "bat", "bag", "dog"};
    EXPECT_EQ(generate_word_ladder("cat", "dog", word_list), vector<string>({"cat", "bat", "bag", "dog"}));
    EXPECT_EQ(generate_word_ladder("cat", "bat", word_list), vector<string>({"cat", "bat"}));
}

TEST(WordLadderTest, NoPath) {
    set<string> word_list = {"cat", "hat", "bad", "bat", "bag", "fog"};
    EXPECT_TRUE(generate_word_ladder("cat", "fog", word_list).empty());
}

TEST(WordLadderTest, EdgeCases) {
    set<string> word_list = {"cat"};
    EXPECT_TRUE(generate_word_ladder("cat", "bat", word_list).empty());
    EXPECT_EQ(generate_word_ladder("cat", "cat", word_list), vector<string>({"cat"}));
}

    TEST(DijkstraTest, SimpleGraph) {
    Graph G(5);
    G.addEdge(0, 1, 2);
    G.addEdge(1, 2, 4);
    G.addEdge(2, 3, 1);
    G.addEdge(3, 4, 7);
    
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    
    EXPECT_EQ(distances[4], 14);
    vector<int> expected_path = {0, 1, 2, 3, 4};
    vector<int> path = extract_shortest_path(distances, previous, 4);
    EXPECT_EQ(path, expected_path);
}

TEST(DijkstraTest, NoPath) {
    Graph G(5);
    G.addEdge(0, 1, 2);
    G.addEdge(1, 2, 4);
    G.addEdge(2, 3, 1);
    
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    
    EXPECT_EQ(distances[4], INF);
    vector<int> path = extract_shortest_path(distances, previous, 4);
    EXPECT_TRUE(path.empty());
}

TEST(DijkstraTest, EdgeCases) {
    Graph G(1);
    
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    
    EXPECT_EQ(distances[0], 0);
    vector<int> expected_path = {0};
    vector<int> path = extract_shortest_path(distances, previous, 0);
    EXPECT_EQ(path, expected_path);
}