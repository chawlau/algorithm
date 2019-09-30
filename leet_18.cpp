#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <cassert>
#include <climits>
#include <unordered_set>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
  unordered_set<string> dict(wordList.begin(), wordList.end());
  queue<string> q;
  int ladder = 1;
  q.push(beginWord);
  while (!q.empty()) {
    int n = q.size();

    for (int i = 0; i < n; i++) {
      string word = q.front();
      q.pop();
      dict.erase(word);

      if (word == endWord)
        return ladder;

      for (int j = 0; j < word.size(); j++) {
        char c = word[j];

        for (int k = 0; k < 26; k++) {
          word[j] = 'a' + k;
          if (dict.count(word) > 0) {
            q.push(word);
          }
        }
        word[j] = c;
      }
    }
    ladder++;
  }

  return -1;
}

int main() {
  vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
  string beginWord = "hit";
  string endWord = "hit";
}
