#include <unordered_map>
#include <iostream>
#include <functional>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void printLinkedList(Node* head){
    while(head != nullptr){
		  //cout<<"val: " << head->val << " nodeAddress: "<< head << " node->next Address: " << head->next << " node->randomAddress:"<< head->random;
			cout << " " << head->val << " " << head << " " << head->next << " " << head->random;
			head = head->next;
			if(head)
				cout<<" -> ";
		}
    cout<<endl;
}

void printUnorderedMap(unordered_map<Node*, Node*> inputMap){
    
		for(auto mapPair : inputMap){
			cout<<mapPair.first << " " << mapPair.second<<endl;
		}
    cout<<endl;
}

void validateMapping(unordered_map<Node*, Node*> inputMap){
		for(auto mapPair : inputMap){
			cout<< mapPair.first->val <<" "<< mapPair.second->val <<endl;		
		}
}

Node* copyRandomList(Node* head) {
    //First pass - copy nodes/values of original list
    Node* firstPassHead = head, *tempReturnList = nullptr, *returnListHead = nullptr;
		//Map intial node addresses to new node addresses to update the new random pointers
    std::unordered_map<Node*, Node*> nodeMap;

		Node* dummyNode = new Node(-1);
		tempReturnList = dummyNode;

		while(firstPassHead != nullptr){
			Node* tempNode =  new Node(firstPassHead->val);
			tempReturnList->next = tempNode;
			nodeMap[firstPassHead] = tempReturnList->next;

			tempReturnList = tempReturnList->next;
			firstPassHead = firstPassHead->next;
		}
		returnListHead = dummyNode->next;
		delete(dummyNode);	
		dummyNode = nullptr;

		firstPassHead = head;
		tempReturnList = returnListHead;
		while(firstPassHead != nullptr){
			tempReturnList->random = nodeMap[firstPassHead->random];
			
			firstPassHead = firstPassHead->next;
			tempReturnList = tempReturnList->next;
		}
		return returnListHead;
}

int main(){
	//[[7,null],[13,0],[11,4],[10,2],[1,0]]

	Node* firstTest = new Node(7);
	firstTest->next = new Node(13);
	firstTest->next->next = new Node(11);
	firstTest->next->next->next = new Node(10);
	firstTest->next->next->next->next = new Node(1);

	firstTest->next->random = firstTest;
	firstTest->next->next->random = firstTest->next->next->next->next;
	firstTest->next->next->next->random = firstTest->next->next;
	firstTest->next->next->next->next->random = firstTest;
	printLinkedList(firstTest);
	Node* firstResult = copyRandomList(firstTest);
	printLinkedList(firstResult);
}
