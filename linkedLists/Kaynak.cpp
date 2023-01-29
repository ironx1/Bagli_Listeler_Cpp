#include <iostream>

using namespace std;

class linkedList
{
protected:
    struct singly
    {
        int data;
        singly *next;
    };
    struct doubly
    {
        int data;
        doubly *next;
        doubly *prev;
    };
};

class tekYonlu : linkedList
{
private:
    singly *head;
    singly *createNode(int val)
    {
        singly *n = new singly;
        n->data = val;
        n->next = nullptr;
        return n;
    }
    void insertAtLastPrivate(int val)
    {
        if (head == nullptr)
        {
            head = createNode(val);
            return;
        }
        singly *iter = head;
        while (iter->next != nullptr)
        {
            iter = iter->next;
        }
        iter->next = createNode(val);
    }
    void insertAtBeginPrivate(int val)
    {
        if (head == nullptr)
        {
            head = createNode(val);
            return;
        }
        singly *temp = createNode(val);
        temp->next = head;
        head = temp;
    }
    void insertAtAnywherePrivate(int val)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        singly *temp = createNode(val);
        int x = 0, i = 0;
        singly *iter = head;
        while (iter != nullptr)
        {
            iter = iter->next;
            i++;
        }
        i--;
        i /= 2;
        singly *it = head;
        while (x < i)
        {
            it = it->next;
            x++;
        }
        temp->next = it->next;
        it->next = temp;
    }
    void deleteNodePrivate(int val)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head != nullptr && head->next == nullptr && head->data == val)
        {
            singly *t = head;
            head = nullptr;
            delete t;
            return;
        }
        if (head->data == val)
        {
            singly *t = head;
            head = head->next;
            delete t;
            return;
        }
        else
        {
            singly *iter = head;
            while (iter->next != nullptr)
            {
                if (iter->next->data == val)
                {
                    singly *t = iter->next;
                    iter->next = iter->next->next;
                    delete t;
                    return;
                }
                iter = iter->next;
            }
            singly *it = head;
            while (it->next->next != nullptr)
            {
                it = it->next;
            }
            if (it->next->data == val)
            {
                singly *t = it->next;
                it->next = nullptr;
                delete t;
                return;
            }
        }
    }

public:
    tekYonlu()
    {
        head = nullptr;
    }
    void insertAtLast(int val)
    {
        insertAtLastPrivate(val);
    }
    void insertAtBegin(int val)
    {
        insertAtBeginPrivate(val);
    }
    void insertAtAnywhere(int val)
    {
        insertAtAnywherePrivate(val);
    }
    void deleteNode(int val)
    {
        deleteNodePrivate(val);
    }
    void printNode()
    {
        if (head == nullptr)
        {
            return;
        }
        singly *iter = head;
        while (iter != nullptr)
        {
            cout << iter->data << " ";
            iter = iter->next;
        }
        cout << endl;
    }
};

class ciftYonlu : linkedList
{
private:
    doubly *root;
    doubly *createNode(int val)
    {
        doubly *n = new doubly;
        n->data = val;
        n->prev = nullptr;
        n->next = nullptr;
        return n;
    }
    void insertAtLastPrivate(int val)
    {
        if (root == nullptr)
        {
            root = createNode(val);
            return;
        }
        doubly *iter = root;
        while (iter->next != nullptr)
        {
            iter = iter->next;
        }
        iter->next = createNode(val);
        iter->next->prev = iter;
    }
    void insertAtBeginPrivate(int val)
    {
        if (root == NULL)
        {
            root = createNode(val);
            return;
        }
        doubly *temp = createNode(val);
        temp->next = root;
        root->prev = temp;
        root = temp;
    }
    void insertAtAnywherePrivate(int val)
    {
        if (root == nullptr || root->next == nullptr)
        {
            return;
        }
        int i = 0, x = 0;
        doubly *temp = createNode(val);
        doubly *iter = root;
        doubly *it = root;
        while (iter != nullptr)
        {
            iter = iter->next;
            i++;
        }
        i--;
        i /= 2;
        while (x < i)
        {
            it = it->next;
            x++;
        }
        temp->next = it->next;
        it->next->prev = temp;
        it->next = temp;
        temp->prev = it;
    }
    void deleteNodePrivate(int val)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->next == nullptr && root->data == val)
        {
            doubly *temp = root;
            root = nullptr;
            delete temp;
            return;
        }
        if (root->data == val)
        {
            doubly *temp = root;
            root = root->next;
            root->prev = nullptr;
            delete temp;
            return;
        }
        else
        {
            doubly *iter = root;
            while (iter != nullptr)
            {
                if (iter->data == val && iter->next != nullptr)
                {
                    doubly *temp = iter;
                    iter->prev->next = iter->next;
                    iter->next->prev = iter->prev;
                    delete temp;
                    return;
                }
                if (iter->next == nullptr && iter->data == val)
                {
                    doubly *temp = iter;
                    iter->prev->next = nullptr;
                    delete temp;
                    return;
                }
                iter = iter->next;
            }
        }
    }

public:
    ciftYonlu()
    {
        root == NULL;
    }
    void insertAtLast(int val)
    {
        insertAtLastPrivate(val);
    }
    void insertAtBegin(int val)
    {
        insertAtBeginPrivate(val);
    }
    void insertAtAnywhere(int val)
    {
        insertAtAnywherePrivate(val);
    }
    void deleteNode(int val)
    {
        deleteNodePrivate(val);
    }
    void printNode()
    {
        if (root == nullptr)
        {
            return;
        }
        doubly *iter = root;
        while (iter != nullptr)
        {
            cout << iter->data << " ";
            iter = iter->next;
        }
        cout << endl;
    }
};

class daireselTekYonlu : linkedList
{
private:
    singly *head;
    singly *tail;
    singly *createNode(int val)
    {
        singly *n = new singly;
        n->data = val;
        n->next = n;
        return n;
    }
    void insertAtLastPrivate(int val)
    {
        if (head == nullptr)
        {
            head = createNode(val);
            tail = head;
            return;
        }
        singly *iter = head;
        while (iter->next != head)
        {
            iter = iter->next;
        }
        iter->next = createNode(val);
        tail = iter->next;
        tail->next = head;
    }
    void insertAtBeginPrivate(int val)
    {
        if (head == nullptr)
        {
            head = createNode(val);
            tail = head;
            return;
        }
        singly *temp = createNode(val);
        temp->next = head;
        head = temp;
        tail->next = head;
    }
    void insertAtAnywherePrivate(int val)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        singly *temp = createNode(val);
        singly *iter = head;
        singly *it = head;
        int i = 1, x = 0;
        iter = iter->next;
        while (iter != head)
        {
            iter = iter->next;
            i++;
        }
        i--;
        i /= 2;
        while (x < i)
        {
            it = it->next;
            x++;
        }
        temp->next = it->next;
        it->next = temp;
    }
    void deleteNodePrivate(int val)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == tail && head->data == val)
        {
            singly *temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
            return;
        }
        if (head->data == val)
        {
            singly *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            return;
        }
        if (tail->data == val)
        {
            singly *iter = head;
            while (iter->next->next != head)
            {
                iter = iter->next;
            }
            singly *temp = tail;
            iter->next = head;
            tail = iter;
            delete temp;
            return;
        }
        else
        {
            singly *iter = head;
            while (iter->next != tail)
            {
                if (iter->next->data = val)
                {
                    singly *temp = iter->next;
                    iter->next = iter->next->next;
                    delete temp;
                    return;
                }
                iter = iter->next;
            }
        }
    }

public:
    daireselTekYonlu()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertAtLast(int val)
    {
        insertAtLastPrivate(val);
    }
    void insertAtBegin(int val)
    {
        insertAtBeginPrivate(val);
    }
    void insertAtAnywhere(int val)
    {
        insertAtAnywherePrivate(val);
    }
    void deleteNode(int val)
    {
        deleteNodePrivate(val);
    }
    void printNode()
    {
        if (head == nullptr)
        {
            return;
        }
        singly *iter = head;
        cout << iter->data << " ";
        iter = iter->next;
        while (iter != head)
        {
            cout << iter->data << " ";
            iter = iter->next;
        }
        cout << endl;
    }
};

class daireselCiftYonlu : linkedList
{
private:
    doubly *head;
    doubly *tail;
    doubly *createNode(int val)
    {
        doubly *n = new doubly;
        n->data = val;
        n->next = n;
        n->prev = n;
        return n;
    }
    void insertAtLastPrivate(int val)
    {
        if (head == nullptr)
        {
            head = createNode(val);
            tail = head;
            return;
        }
        doubly *iter = head;
        while (iter->next != head)
        {
            iter = iter->next;
        }
        iter->next = createNode(val);
        tail = iter->next;
        tail->prev = iter;
        tail->next = head;
        head->prev = tail;
    }
    void insertAtBeginPrivate(int val)
    {
        if (head == nullptr)
        {
            head = createNode(val);
            tail = head;
            return;
        }
        doubly *temp = createNode(val);
        temp->next = head;
        head = temp;
        head->next->prev = head;
        head->prev = tail;
        tail->next = head;
    }
    void insertAtAnywherePrivate(int val)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        int i = 0, x = 0;
        doubly *iter = head;
        doubly *it = head;
        doubly *temp = createNode(val);
        while (iter != tail)
        {
            iter = iter->next;
            i++;
        }
        i /= 2;
        while (x < i)
        {
            it = it->next;
            x++;
        }
        temp->next = it->next;
        temp->prev = it;
        it->next = temp;
        temp->next->prev = temp;
    }
    void deleteNodePrivate(int key)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head == tail && head->data == key) // 30
        {
            delete head;
            head = nullptr;
            tail = head;
            return;
        }
        if (head->data == key)
        {
            doubly *temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
            return;
        }
        if (tail->data == key)
        {
            doubly *temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            temp->next = nullptr;
            temp->prev = nullptr;
            delete temp;
            return;
        }
        else
        {
            doubly *iter = head;
            while (iter != tail)
            {
                if (iter->data == key)
                {
                    doubly *temp = iter;
                    iter->prev->next = iter->next;
                    iter->next->prev = iter->prev;
                    delete temp;
                    return;
                }
                iter = iter->next;
            }
        }
    }

public:
    daireselCiftYonlu()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertAtLast(int val)
    {
        insertAtLastPrivate(val);
    }
    void insertAtBegin(int val)
    {
        insertAtBeginPrivate(val);
    }
    void insertAtAnywhere(int val)
    {
        insertAtAnywherePrivate(val);
    }
    void deleteNode(int key)
    {
        deleteNodePrivate(key);
    }
    void printNode()
    {
        if (head == nullptr)
        {
            return;
        }
        doubly *iter = head;
        while (iter != tail)
        {
            cout << iter->data << " ";
            iter = iter->next;
        }
        cout << iter->data << endl;
    }
};

int main(int argc, char const *argv[])
{
    tekYonlu singlyList;
    ciftYonlu doublyList;
    daireselTekYonlu dtList;
    daireselCiftYonlu dcList;
    singlyList.insertAtBegin(10);
    singlyList.insertAtLast(20);
    singlyList.insertAtAnywhere(15);
    singlyList.deleteNode(10);
    singlyList.printNode();
    doublyList.insertAtBegin(10);
    doublyList.insertAtLast(20);
    doublyList.insertAtAnywhere(15);
    doublyList.deleteNode(10);
    doublyList.printNode();
    dtList.insertAtBegin(10);
    dtList.insertAtLast(20);
    dtList.insertAtAnywhere(15);
    dtList.deleteNode(10);
    dtList.printNode();
    dcList.insertAtBegin(10);
    dcList.insertAtLast(20);
    dcList.insertAtAnywhere(15);
    dcList.deleteNode(10);
    dcList.printNode();
    return 0;
}
