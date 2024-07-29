#include <iostream>
#include <cstring>

#define SIZE 100

using namespace std;

// A Huffman Tree Node
struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right) {
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

// Utility function to swap two nodes
void swap(Node*& a, Node*& b) {
    Node* temp = a;
    a = b;
    b = temp;
}

// Function to heapify a subtree
void heapify(Node* arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left]->freq < arr[smallest]->freq)
        smallest = left;

    if (right < n && arr[right]->freq < arr[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Function to build a min-heap
void buildMinHeap(Node* arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Function to extract the minimum node from the heap
Node* extractMin(Node* arr[], int& n) {
    Node* temp = arr[0];
    arr[0] = arr[n - 1];
    n--;
    heapify(arr, n, 0);
    return temp;
}

// Function to insert a node into the heap
void insertHeap(Node* arr[], Node* node, int& n) {
    n++;
    int i = n - 1;
    arr[i] = node;

    while (i && arr[i]->freq < arr[(i - 1) / 2]->freq) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Traverse the Huffman Tree and store Huffman Codes in an array
void encode(Node* root, string str, char huffmanCode[][SIZE], int &index) {
    if (root == nullptr)
        return;

    // Found a leaf node
    if (!root->left && !root->right) {
        strcpy(huffmanCode[index], str.c_str());
        index++;
    }

    encode(root->left, str + "0", huffmanCode, index);
    encode(root->right, str + "1", huffmanCode, index);
}

// Function to calculate the total size of the original string in bits
int calculateTotalSize(const string &text) {
    return text.size() * 8; // Each character is 8 bits
}

// Function to calculate the compressed size in bits
int calculateCompressedSize(const string &encodedString) {
    return encodedString.size();
}

// Build Huffman Tree and encode the input data
void buildHuffmanTree(string text) {
    // Count frequency of appearance of each character and store it in arrays
    char uniqueChars[SIZE];
    int freq[SIZE];
    int uniqueCount = 0;

    for (char ch : text) {
        bool found = false;
        for (int i = 0; i < uniqueCount; i++) {
            if (uniqueChars[i] == ch) {
                freq[i]++;
                found = true;
                break;
            }
        }
        if (!found) {
            uniqueChars[uniqueCount] = ch;
            freq[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Create an array of nodes
    Node* nodes[SIZE];
    for (int i = 0; i < uniqueCount; i++) {
        nodes[i] = getNode(uniqueChars[i], freq[i], nullptr, nullptr);
    }

    // Build the Huffman Tree
    int n = uniqueCount;
    buildMinHeap(nodes, n);

    while (n != 1) {
        Node* left = extractMin(nodes, n);
        Node* right = extractMin(nodes, n);

        int sum = left->freq + right->freq;
        Node* node = getNode('\0', sum, left, right);

        insertHeap(nodes, node, n);
    }

    Node* root = extractMin(nodes, n);

    // Traverse the Huffman Tree and store Huffman Codes in an array
    char huffmanCode[SIZE][SIZE];
    int index = 0;
    encode(root, "", huffmanCode, index);

    // Print the Huffman Codes
    cout << "Huffman Codes:\n";
    for (int i = 0; i < uniqueCount; i++) {
        cout << uniqueChars[i] << ": " << huffmanCode[i] << '\n';
    }

    // Print the encoded string
    cout << "\nEncoded string:\n";
    string encodedString = "";
    for (char ch : text) {
        for (int i = 0; i < uniqueCount; i++) {
            if (uniqueChars[i] == ch) {
                encodedString += huffmanCode[i];
                break;
            }
        }
    }
    cout << encodedString << '\n';

    // Calculate sizes
    int totalSize = calculateTotalSize(text);
    int compressedSize = calculateCompressedSize(encodedString);

    // Display sizes
    cout << "\nOriginal size: " << totalSize << " bits\n";
    cout << "Compressed size: " << compressedSize << " bits\n";
}

int main() {
    string text = "AAABBABBACCDDDEDACBEE";
    buildHuffmanTree(text);
    return 0;
}
