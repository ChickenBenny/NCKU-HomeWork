#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

struct node{
    int chap;
    int val;
    struct node* next;
    struct node* prev;
};

struct node *head = NULL;
struct node *tail = NULL;

map<int, node*> location;
map<int, node*> ::iterator iter;
int count = 0;

void get(int chap);
void set(int chap, int val, int limit);

int main(){
    int limit, operate, chap, val;
    string action;
    cin >> limit >> operate ;
    for(int i = 0;i < operate;i ++){
        cin >> action;
        if(action == "get"){
            cin >> chap ;
            get(chap);
        }
        else{
            cin >> chap >> val ;
            set(chap, val, limit);
        }
    }
}

void get(int chap){
    iter = location.find(chap);
    if(iter != location.end()) {
        cout << iter->second->val << endl;

        struct node *tmp;
        tmp = iter->second;
        if (tmp->prev == NULL && tmp->next == NULL)
            return;
        else if (tmp->prev == NULL && tmp->next != NULL) {
            head = tmp->next;
            head->prev = NULL;
            tmp->next = NULL;
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        } else if (tmp->prev != NULL && tmp->next == NULL)
            return;
        else {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            tmp->next = NULL;
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
    }
    else
        cout << "-1\n";
}

void set(int chap, int val, int limit){
    iter = location.find(chap);
    if(iter == location.end()){
        struct node* tmp = (struct node*) malloc(sizeof(struct node));
        tmp->chap = chap;
        tmp->val = val;
        tmp->next = NULL;
        count += 1;
        if(count > limit){
            location.erase(location.find(head->chap));
            struct node* del = head;
            head = head->next;
            head->prev = NULL;
            free(del);
        }
        if(head == NULL){
            head = tmp;
            tmp->prev = NULL;
        }
        else{
            tail->next = tmp;
            tmp->prev = tail;
        }
        tail = tmp;
        location.insert(pair<int, node*>(chap, tmp));
    }
    else{
        struct node* tmp;
        tmp = iter->second;
        tmp->val = val;
        if(tmp->prev == NULL && tmp->next == NULL)
            return;
        else if(tmp->prev == NULL && tmp->next != NULL){
            head = tmp->next;
            head->prev = NULL;
            tmp->next = NULL;
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
        else if(tmp->prev != NULL && tmp->next == NULL)
            return;
        else{
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            tmp->next = NULL;
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
    }
}