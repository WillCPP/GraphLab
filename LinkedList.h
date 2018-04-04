#pragma once
#include <iostream>
#include "Edge.h"
#include "OverShotException.h"
#include "UnderFlowException.h"
class LinkedList
{
	int leng = 0;	//length of linked list
	int location = 0;	//Location used for See functions
public:
	Edge *first = nullptr;
	LinkedList() {

	}
	~LinkedList() {
		Edge *temp;
		while (first != nullptr) {//Goes through and deletes all nodes 
			temp = first;
			first = first->next;
			delete temp;
			temp = nullptr;
		}
	}
	void addItem(int inval) {
		Edge *temp = new Edge(inval);//new node going to be added to list
		if(first == nullptr) {//list is empty
			first = temp;
			leng++;
			return;
		}
		else if(first -> data > inval) {//item goes in the first location
			temp->next = first;
			first = temp;
			leng++;
			return;
		}
		else {//item goes in any other location
			Edge *iter = first;//Iter will be used to run through the list to find the location to fit temp
			while (iter->next != nullptr && iter->next->data < inval)
				iter = iter->next;
			temp -> next = iter -> next;
			iter -> next = temp;
			leng++;
		}

	}
	Edge* getItem(int inval) {
		Edge *retval;//Ptr which will be used to point to node being removed
		if(first == nullptr)//List is empty
			return nullptr;//Returns nullptr as told in lab 8 doc
		if(first->data == inval){//inval matches first item in list
			retval = first;
			first = first->next;
			leng--;
			return retval;
		}
		Edge *temp = first;
		while(temp->next != nullptr && !(temp->next->data == inval))//temp will point to either null or the node before the one we want
			temp = temp->next;
		if(temp->next == nullptr)//returns null if not in list
			return nullptr;//Returns nullptr as told in lab 8 doc
		retval = temp->next;//Points retval to the return value and removes it from list
		temp->next = temp->next->next;
		leng--;
		return retval;

	}
	Edge* findItem(int inval) {
		if (first == nullptr)//List is empty
			return nullptr;//Returns nullptr as told in lab 8 doc
		if (first->data == inval) {//inval matches first item in list
			return first;
		}
		Edge *temp = first;
		while (temp->next != nullptr && !(temp->next->data == inval))//temp will point to either null or the node before the one we want
			temp = temp->next;
		if (temp->next == nullptr)//returns null if not in list
			return nullptr;//Returns nullptr as told in lab 8 doc
		return temp->next;

	}
	bool isInList(int inval) {
		if (isEmpty())//List is empty
			return false;
		if (first->data == inval) {//inval matches first item in list
			return true;
		}
		Edge *temp = first;
		while (temp->next != nullptr && !(temp->next->data == inval))//temp will point to either null or the node before the one we want
			temp = temp->next;
		if (temp->next == nullptr)//returns null if not in list
			return false;
		return true;
	}
	bool isEmpty() {
		if (leng == 0)
			return true;
		return false;
	}
	int size() {
		return leng;
	}
	Edge* seeNext() {
		if (isEmpty())
			throw UnderFlowException();
		if (location >= leng)//Returns nullptr as told in lab 8 doc
			return nullptr;
		Edge *temp = first;
		for (int i = 0; i < location; i++) {//finds the node at the current location and returns it
			temp = temp->next;
		}
		location++;
		return temp;
	}
	Edge* seeAt(int loc) {
		if (loc >= leng)
			throw OverShotExcpetion();
		location = loc;//set location 
		Edge *temp = first;
		for (int i = 0; i < location; i++) {//finds the node at the current location and returns it
			temp = temp->next;
		}
		location++;
		return temp;
	}
	void reset() {//reset location to 0 
		location = 0;//set to 0 sinces its the beginning of our list
	}
	void displayList() {
		int temp = location;//saves location to not affect our users
		reset();//resets location so seeNext can be used by our display function
		while (location<leng) {//Prints each item 
			cout <<"->"<<seeNext()->data;
			
		}
		location = temp;//reset location to its previous spot
	}
};

