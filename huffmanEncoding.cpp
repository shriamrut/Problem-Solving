#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char val;
    int frequency;
    Node *left;
    Node *right;

    Node(char val, int frequency)
    {
        this->val = val;
        this->frequency = frequency;
        this->left = NULL;
        this->right = NULL;
    }

    void print() {
        cout << this->val << " - " << this->frequency << "\n";
    }
};


class Compare {
    public:
    bool operator()(const Node *a, const Node *b) {
        return a->frequency > b->frequency;
    }
};

Node* buildHuffmanTree(priority_queue<Node*, vector<Node*>, Compare> &pq)
{
    while (pq.size() != 1)
    {
        Node *firstMinimum = pq.top();
        pq.pop();
        Node *secondMinimum = pq.top();
        pq.pop();
        Node *newNode = new Node('$', firstMinimum->frequency + secondMinimum->frequency);
        newNode->left = firstMinimum;
        newNode->right = secondMinimum;
        pq.push(newNode);
    }
    return pq.top();
}

void obtainEncoding(Node *root, string encoding, unordered_map<char, string> &charToEncoding)
{
    if (root->left == NULL && root->right == NULL)
    {
        charToEncoding[root->val] = encoding;
        return;
    }
    encoding += '0';
    obtainEncoding(root->left, encoding, charToEncoding);
    encoding.pop_back();
    encoding += '1';
    obtainEncoding(root->right, encoding, charToEncoding);
    encoding.pop_back();
}

unordered_map<char, string> huffmanEncoding(string s)
{

    unordered_map<char, int> frequency;
    for (char c : s)
    {
        frequency[c]++;
    }
    vector<Node*> nodes;
    for (auto cfreq : frequency)
    {
        nodes.push_back(new Node(cfreq.first, cfreq.second));
    }
    priority_queue<Node*, vector<Node*>, Compare> pq(nodes.begin(), nodes.end());

    Node *root = buildHuffmanTree(pq);
    string encoding = "";
    unordered_map<char, string> charToEncoding;
    obtainEncoding(root, encoding, charToEncoding);
    return charToEncoding;
}

int main(int argc, char **argv)
{
    string s = argv[1];
    unordered_map<char, string> charToEncoding = huffmanEncoding(s);
    for (auto ce : charToEncoding)
    {
        cout << ce.first << " " << ce.second << "\n";
    }
    string encodedString = "";
    for(char &c: s) {
        encodedString += charToEncoding[c];
    }
    cout << "===================================\n";
    cout << "Encoded string: " << encodedString << "\n";
    int size = s.length() * 8;
    cout << "===================================\n";
    cout << "Current size: " << size << " bits\n";
    cout << "Compressed size: " << encodedString.length() << " bits\n"; // assume each character is one bit
    double ratio =  1.0 - ((double) encodedString.length() / size);
    cout << "===================================\n";
    cout << "Compression achieved: " << ratio * 100 << "%\n";
    return 0;
}
