#include <iostream>
#include <string>
#include <windows.h> 
using namespace std;

bool print_translate = 1;

class Node {
public:
    string english;
    string russian;
    int accessCount;
    Node* left;
    Node* right;

    Node(string eng, string rus) {
        english = eng;
        russian = rus;
        accessCount = 0;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() { 
        root = nullptr; 
    }

    void addNode(string eng, string rus) {
        Node* newNode = new Node(eng, rus);

        if (root == nullptr) {
            root = newNode;
        }
        else {
            Node* focusNode = root;
            Node* parent;

            while (true) {
                parent = focusNode;

                if (eng < focusNode->english) {
                    focusNode = focusNode->left;
                    if (focusNode == nullptr) {
                        parent->left = newNode;
                        return;
                    }
                }
                else {
                    focusNode = focusNode->right;
                    if (focusNode == nullptr) {
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }

    void addNode(string eng, string rus, int access_count) {
		if (access_count >= 0) {// Check if access count is non-negative

            Node* newNode = new Node(eng, rus);
            newNode->accessCount= access_count;
            if (root == nullptr) {
                root = newNode;
            }
            else {
                Node* focusNode = root;
                Node* parent;

                while (true) {
                    parent = focusNode;

                    if (eng < focusNode->english) {
                        focusNode = focusNode->left;
                        if (focusNode == nullptr) {
                            parent->left = newNode;
                            return;
                        }
                    }
                    else {
                        focusNode = focusNode->right;
                        if (focusNode == nullptr) {
                            parent->right = newNode;
                            return;
                        }
                    }
                }
            }
        }

		else {
			cout << "Access count must be a non-negative integer." << endl;
		}
    }

    void addNode(string eng) {
        addNode(eng, "no data");
    }

    Node* searchNode(string eng) {
        Node* focusNode = root;

        while (focusNode != nullptr && focusNode->english != eng) {
            if (eng < focusNode->english) {
                focusNode = focusNode->left;
            }
            else {
                focusNode = focusNode->right;
            }
        }

        if (focusNode != nullptr) {
            focusNode->accessCount++;
            if (print_translate) {
                cout << "Word found: " << focusNode->english << " - " << focusNode->russian << endl;
            }
        }
		else {
            cout << "Word: <" << eng << "> not found." << endl;
		}

        return focusNode;
    }

	

	void replaceNode(string eng, string newRus) {// Replace, add the russian translation of a word
		print_translate = 0;
        Node* node = searchNode(eng);
        print_translate = 1;
        if (node != nullptr) {
            node->russian = newRus;
        }
    }

	void deleteNode_ru(string eng) {// Delete a word
        print_translate = 0;
        Node* node = searchNode(eng);
        print_translate = 1;
        if (node != nullptr) {
            node->russian = "no data";
        }
	}

    void deleteNode(string eng) {
        root = deleteNodeRec(root, eng);
    }

    Node* deleteNodeRec(Node* root, string eng) {
        if (root == nullptr) return root;

        if (eng < root->english) {
            root->left = deleteNodeRec(root->left, eng);
        }
        else if (eng > root->english) {
            root->right = deleteNodeRec(root->right, eng);
        }
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->english = temp->english;
            root->russian = temp->russian;
            root->accessCount = temp->accessCount;
            root->right = deleteNodeRec(root->right, temp->english);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    void displayTopWords(bool mostPopular) {
        Node* nodes[100]; // Assuming a maximum of 100 nodes for simplicity
        int count = 0;
        inOrderTraversal(root, nodes, count);

        if (mostPopular) {
            for (int i = 0; i < count - 1; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    if (nodes[j]->accessCount < nodes[j + 1]->accessCount) {
                        Node* temp = nodes[j];
                        nodes[j] = nodes[j + 1];
                        nodes[j + 1] = temp;
                    }
                }
            }
        }
        else {
            for (int i = 0; i < count - 1; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    if (nodes[j]->accessCount > nodes[j + 1]->accessCount) {
                        Node* temp = nodes[j];
                        nodes[j] = nodes[j + 1];
                        nodes[j + 1] = temp;
                    }
                }
            }
        }

        for (int i = 0; i < 3 && i < count; i++) {
            cout << nodes[i]->english << " (" << nodes[i]->russian << ") - Accessed: " << nodes[i]->accessCount << " times" << endl;
        }
        cout << endl;
    }

    void inOrderTraversal(Node* focusNode, Node* nodes[], int& count) {
        if (focusNode != nullptr) {
            inOrderTraversal(focusNode->left, nodes, count);
            nodes[count++] = focusNode;
            inOrderTraversal(focusNode->right, nodes, count);
        }
    }
};

int print_menu() {
    cout << "1. Add a word" << endl;
    cout << "2. Search for a word" << endl;
    cout << "3. Replace the russian translation of a word" << endl;
    cout << "4. Delete a word" << endl;
    cout << "5. Delete a word translation" << endl;
    cout << "6. Display top 3 most popular words" << endl;
    cout << "7. Display top 3 least popular words" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    return choice;
} 

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    BinaryTree tree;

    tree.addNode("apple", "яблоко");
    tree.addNode("banana", "банан", 3);
    tree.addNode("cherry", "вишня");
    tree.addNode("date", "финик");
    tree.addNode("elderberry", "бузина");
    tree.addNode("fig", "инжир");
    tree.addNode("grape", "виноград");

    tree.searchNode("apple");
    tree.searchNode("banana");
    tree.searchNode("cherry");
    tree.searchNode("pineapple");

    cout << "Top 3 most popular words:" << endl;
    tree.displayTopWords(true);

    cout << "Top 3 least popular words:" << endl;
    tree.displayTopWords(false);


	tree.replaceNode("apple", "яблуко");
	tree.searchNode("apple");

	tree.deleteNode_ru("apple");
	tree.searchNode("apple");

    tree.replaceNode("apple", "яблуко");
    tree.searchNode("apple");


	while (true) {
        system("pause");
        system("cls");
		int choice = print_menu();
		string eng, rus;
		switch (choice) {
		case 1:
			cout << "Enter the word in English: ";
			cin >> eng;
			cout << "Enter the word in Russian: ";
			cin >> rus;
			tree.addNode(eng, rus);
			break;
		case 2:
			cout << "Enter the word in English: ";
			cin >> eng;
			tree.searchNode(eng);
			break;
		case 3:
			cout << "Enter the word in English: ";
			cin >> eng;
			cout << "Enter the new Russian translation: ";
			cin >> rus;
			tree.replaceNode(eng, rus);
			break;
		case 4:
			cout << "Enter the word in English: ";
			cin >> eng;
			tree.deleteNode(eng);
			break;
		case 5:
			cout << "Enter the word in English: ";
			cin >> eng;
			tree.deleteNode_ru(eng);
			break;
		case 6:
			cout << "Top 3 most popular words:" << endl;
			tree.displayTopWords(true);
			break;
		case 7:
			cout << "Top 3 least popular words:" << endl;
			tree.displayTopWords(false);
			break;
		case 8:
			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}

    return 0;
}
