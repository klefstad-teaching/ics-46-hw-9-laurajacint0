#include "ladder.h"

int main() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");

    verify_word_ladder();

    string begin_word = "car";
    string end_word = "cheat";
    vector<string> ladder = generate_word_ladder(begin_word, end_word, word_list);

    print_word_ladder(ladder);
    return 0;
}
