#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

template<typename T>
struct Node {
    T val;
    std::vector<Node<T>*> vec;
    Node(int num) : val(num) {};
}; 

template<typename T>
void isChristmastTree(Node<T>* root) {
    if (!root) {
        std::cout << "Not a Christmas Tree" << std::endl;
        return;
    }
    std::queue<Node<T>*> q;

    q.push(root);

    while (!q.empty()) {
        int leafCount = 0;
        auto* temp = q.front();
        q.pop();
        if (temp->vec.empty()) {
            std::cout << "Not a Christmas Tree" << std::endl;
            return;
        }
        for (auto& in : temp->vec) {
            if (in->vec.empty()) {
                ++leafCount;
            }
            else {
                q.push(in);
            }
        }
        if (leafCount < 3) {
            std::cout << "Not a Christmas Tree" << std::endl;
            return;
        }
        else {
            continue;
        }
    }
    std::cout << "Christmas Tree" << std::endl;

}

int main() {
    Node<int>* root = new Node<int>(1);
    Node<int>* child1 = new Node<int>(2);
    Node<int>* child2 = new Node<int>(3);
    Node<int>* child3 = new Node<int>(4);
    Node<int>* child4 = new Node<int>(5);
    Node<int>* child5 = new Node<int>(6);


    
    root->vec.push_back(child1);
    root->vec.push_back(child2);
    root->vec.push_back(child3);
    root->vec.push_back(child4);
    root->vec.push_back(child5);


    
    child1->vec.push_back(new Node<int>(4));
    child1->vec.push_back(new Node<int>(5));
    child1->vec.push_back(new Node<int>(6));
    child1->vec.push_back(new Node<int>(7));

    child2->vec.push_back(new Node<int>(4));
    child2->vec.push_back(new Node<int>(5));
    child2->vec.push_back(new Node<int>(6));
    child2->vec.push_back(new Node<int>(7));

    isChristmastTree(root);

    delete root;
    delete child1;
    delete child2;
    delete child3;
    delete child4;
    delete child5;

    return 0;
}