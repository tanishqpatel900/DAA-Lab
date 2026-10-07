// Tanishq patel PRN 26070521506
// Huffman Coding using Greedy method (min-heap)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

Node *heap[100];
int size = 0;

Node *newNode(char ch, int freq, Node *l, Node *r) {
    Node *t = malloc(sizeof(Node));
    t->ch = ch; t->freq = freq; t->left = l; t->right = r;
    return t;
}

void push(Node *x) {
    int i = size++;
    heap[i] = x;
    while (i > 0 && heap[(i - 1) / 2]->freq > heap[i]->freq) {
        Node *t = heap[i]; heap[i] = heap[(i - 1) / 2]; heap[(i - 1) / 2] = t;
        i = (i - 1) / 2;
    }
}

Node *pop() {
    Node *top = heap[0];
    heap[0] = heap[--size];
    int i = 0;
    while (1) {
        int s = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < size && heap[l]->freq < heap[s]->freq) s = l;
        if (r < size && heap[r]->freq < heap[s]->freq) s = r;
        if (s == i) break;
        Node *t = heap[i]; heap[i] = heap[s]; heap[s] = t;
        i = s;
    }
    return top;
}

void printCodes(Node *root, char code[], int top) {
    if (root->left) { code[top] = '0'; printCodes(root->left, code, top + 1); }
    if (root->right) { code[top] = '1'; printCodes(root->right, code, top + 1); }
    if (!root->left && !root->right) {
        code[top] = '\0';
        printf("%c : %s\n", root->ch, top ? code : "0");
    }
}

int main() {
    int n, f;
    char c;
    printf("Enter number of characters: ");
    scanf("%d", &n);
    printf("Enter character and its frequency:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &c, &f);
        push(newNode(c, f, NULL, NULL));
    }
    while (size > 1) {
        Node *l = pop(), *r = pop();
        push(newNode('$', l->freq + r->freq, l, r));
    }
    char code[100];
    printf("Huffman codes:\n");
    printCodes(pop(), code, 0);
    return 0;
}
