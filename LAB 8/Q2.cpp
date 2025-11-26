#include <iostream>
#include <string>
using namespace std;

int rand_seed = 7;
int myRand() {
    rand_seed = (rand_seed * 37 + 11) % 100;
    return rand_seed % 5;
}

class Combatant {
public:
    string name;
    int hp;
    int atk;
    int id;

    Combatant() {}
    Combatant(string n, int h, int a, int i) {
        name = n;
        hp = h;
        atk = a;
        id = i;
    }
};

class Node {
public:
    Combatant data;
    Node* left;
    Node* right;
    Node(Combatant x) {
        data = x;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = NULL;
    }

    Node* insertNode(Node* r, Combatant x) {
        if (!r) return new Node(x);
        if (x.id < r->data.id) r->left = insertNode(r->left, x);
        else r->right = insertNode(r->right, x);
        return r;
    }

    void insertCombatant(Combatant x) {
        root = insertNode(root, x);
    }

    Node* minNode(Node* r) {
        while (r && r->left) r = r->left;
        return r;
    }

    Node* deleteNode(Node* r, int id) {
        if (!r) return r;
        if (id < r->data.id) r->left = deleteNode(r->left, id);
        else if (id > r->data.id) r->right = deleteNode(r->right, id);
        else {
            if (!r->left) return r->right;
            else if (!r->right) return r->left;
            Node* t = minNode(r->right);
            r->data = t->data;
            r->right = deleteNode(r->right, t->data.id);
        }
        return r;
    }

    void deleteCombatant(int id) {
        root = deleteNode(root, id);
    }

    void inorder(Node* r) {
        if (!r) return;
        inorder(r->left);
        cout << r->data.name << "(" << r->data.hp << ")" << " ";
        inorder(r->right);
    }

    void printTree() {
        inorder(root);
        cout << endl;
    }

    bool empty() {
        return root == NULL;
    }

    Combatant getFront() {
        Node* t = minNode(root);
        return t->data;
    }
};

void attackTurn(Combatant &att, Combatant &def) {
    int dmg = att.atk + myRand();
    def.hp -= dmg;
    cout << att.name << " attacks " << def.name << " for " << dmg << " damage" << endl;
    cout << def.name << " HP now: " << def.hp << endl;
}

int main() {
    BST heroes, enemies;

    heroes.insertCombatant(Combatant("Aiden", 40, 9, 10));
    heroes.insertCombatant(Combatant("Bren", 43, 7, 20));
    heroes.insertCombatant(Combatant("Cyrus", 37, 10, 5));
    heroes.insertCombatant(Combatant("Drake", 50, 6, 15));
    heroes.insertCombatant(Combatant("Evan", 45, 8, 25));

    enemies.insertCombatant(Combatant("Goblin", 30, 6, 12));
    enemies.insertCombatant(Combatant("Orc", 42, 8, 22));
    enemies.insertCombatant(Combatant("Warg", 38, 7, 3));
    enemies.insertCombatant(Combatant("Troll", 55, 9, 17));
    enemies.insertCombatant(Combatant("Shade", 33, 10, 8));

    int round = 1;

    while (!heroes.empty() && !enemies.empty()) {
        cout << "====================" << endl;
        cout << "Round " << round << endl;
        cout << "Heroes: ";
        heroes.printTree();
        cout << "Enemies: ";
        enemies.printTree();
        cout << endl;

        Combatant h = heroes.getFront();
        Combatant e = enemies.getFront();

        cout << "Hero frontline: " << h.name << " (" << h.hp << ")" << endl;
        cout << "Enemy frontline: " << e.name << " (" << e.hp << ")" << endl << endl;

        attackTurn(h, e);

        if (e.hp <= 0) {
            cout << e.name << " is defeated!" << endl;
            enemies.deleteCombatant(e.id);
        } else {
            attackTurn(e, h);
            if (h.hp <= 0) {
                cout << h.name << " is defeated!" << endl;
                heroes.deleteCombatant(h.id);
            } else {
                heroes.deleteCombatant(h.id);
                heroes.insertCombatant(h);
            }
        }

        if (!enemies.empty()) {
            enemies.deleteCombatant(e.id);
            if (e.hp > 0) enemies.insertCombatant(e);
        }

        cout << endl;
        round++;
    }

    if (heroes.empty()) cout << "Enemies Win!" << endl;
    else cout << "Heroes Win!" << endl;

    return 0;
}
